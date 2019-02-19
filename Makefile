NAME := push_swap checker
INCLUDES := includes/ libft/includes/
CHECKER_DIR := srcs/checker/
PUSH_SWAP_DIR := srcs/push_swap/
GENERAL_DIR := srcs/general/

CHECKER_SRCS := $(patsubst $(CHECKER_DIR)%, %, $(wildcard $(CHECKER_DIR)*.c))
PUSH_SWAP_SRCS := $(patsubst $(PUSH_SWAP_DIR)%, %, $(wildcard $(PUSH_SWAP_DIR)*.c))
GENERAL_SRCS := $(patsubst $(GENERAL_DIR)%, %, $(wildcard $(GENERAL_DIR)*.c))

FLAGS := -Wall -Wextra -Werror
DEBUG_FLAGS := -g -O0

GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color

VPATH := $(CHECKER_DIR) $(PUSH_SWAP_DIR) $(GENERAL_DIR)
.PHONY: clean re all fclean add_flags debug

CHECKER_OBJ = $(patsubst %.c, %.o, $(CHECKER_SRCS))
PUSH_SWAP_OBJ = $(patsubst %.c, %.o, $(PUSH_SWAP_SRCS))
GENERAL_OBJ = $(patsubst %.c, %.o, $(GENERAL_SRCS))

all: $(NAME)

debug: fclean add_flags all

test:
	gcc -lft -L. test.c -o test.out $(addprefix -I,$(INCLUDES))

add_flags:
	$(eval FLAGS = $(DEBUG_FLAGS))

push_swap: libft/libft.a $(PUSH_SWAP_OBJ) $(GENERAL_OBJ)
	gcc $(FLAGS) -lft -Llibft/ $(addprefix -I,$(INCLUDES)) $(PUSH_SWAP_OBJ) $(GENERAL_OBJ) -o $@

checker: libft/libft.a $(CHECKER_OBJ) $(GENERAL_OBJ)
	gcc $(FLAGS) -lft -Llibft/ $(addprefix -I,$(INCLUDES)) $(CHECKER_OBJ) $(GENERAL_OBJ) -o $@

%.o: %.c
	gcc $(FLAGS) -c $(addprefix -I,$(INCLUDES)) $< -o $@

libft/libft.a:
	$(MAKE) -C libft/ all

clean:
	/bin/rm -f $(CHECKER_OBJ) $(PUSH_SWAP_OBJ) $(GENERAL_OBJ)
	$(MAKE) -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean all
