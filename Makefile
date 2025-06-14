NAME           = libasm.a
BUILD_DIR      = build
SRCS           = $(wildcard src/*.s)
TEST_SRCS      = $(wildcard test/*.c)
TEST_OBJS      = $(notdir $(TEST_SRCS:.c=.o))
TEST_OBJS_FULL = $(addprefix $(BUILD_DIR)/, $(TEST_OBJS))
OBJS           = $(notdir $(SRCS:.s=.o))
OBJS_FULL      = $(addprefix $(BUILD_DIR)/, $(OBJS))
ACC            = nasm
ACCFLAGS       = -f elf64
CC             = cc
CFLAGS         = -Wall -Wextra -Werror
RM             = rm -f
AR             = ar
ARFLAGS        = rcs

all: $(NAME)

$(NAME): $(OBJS_FULL)
	@mkdir -p $(BUILD_DIR)
	$(AR) $(ARFLAGS) $(BUILD_DIR)/$@ $(OBJS_FULL)

$(BUILD_DIR)/%.o: src/%.s
	@mkdir -p $(BUILD_DIR)
	$(ACC) $(ACCFLAGS) -o $@ $<

clean:
	$(RM) $(BUILD_DIR)/*.o

fclean: clean
	$(RM) $(BUILD_DIR)/$(NAME) $(BUILD_DIR)/test

re: fclean all

test: $(NAME) $(TEST_OBJS_FULL)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/test $(TEST_OBJS_FULL) -L$(BUILD_DIR) -lasm

$(BUILD_DIR)/%.o: test/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
