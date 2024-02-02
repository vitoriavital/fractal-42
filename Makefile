NAME        := fractol
CFLAGS      := -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX      := ./MLX42

HEADERS     := -I ./include -I $(LIBMLX)/include
LIBS        := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS        := $(shell find ./srcs -iname "*.c")
SRCS_BONUS  := $(shell find ./srcs_bonus -iname "*.c")
OBJS_PATH   := ./objs
OBJS_PATH_BONUS := ./objs_bonus
OBJS        := $(patsubst %.c,$(OBJS_PATH)/%.o,$(notdir $(SRCS)))
OBJS_BONUS  := $(patsubst %.c,$(OBJS_PATH_BONUS)/%.o,$(notdir $(SRCS_BONUS)))

all: libmlx $(OBJS_PATH) $(OBJS) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJS_PATH)/%.o: ./srcs/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS_PATH)
	@rm -rf $(OBJS_PATH_BONUS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus

re: clean all

bonus: libmlx $(OBJS_PATH_BONUS) $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME)_bonus

$(OBJS_PATH_BONUS)/%.o: ./srcs_bonus/%.c | $(OBJS_PATH_BONUS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling Bonus: $(notdir $<)\n"

$(OBJS_PATH_BONUS):
	@mkdir -p $(OBJS_PATH_BONUS)

.PHONY: all, clean, fclean, re, libmlx, bonus
