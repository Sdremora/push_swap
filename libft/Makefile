NAME := libft.a
INCLUDES := includes/
LST_DIR := lst/
MEM_DIR := mem/
STR_DIR := str/
PRINTF_DIR := other/ft_printf/
OTHER_DIR := other/

LST_SRCS := $(patsubst $(LST_DIR)%, %, $(wildcard $(LST_DIR)*.c))
MEM_SRCS := $(patsubst $(MEM_DIR)%, %, $(wildcard $(MEM_DIR)*.c))
STR_SRCS := $(patsubst $(STR_DIR)%, %, $(wildcard $(STR_DIR)*.c))
OTHER_SRCS := $(patsubst $(OTHER_DIR)%, %, $(wildcard $(OTHER_DIR)*.c))
PRINTF_SRCS := $(patsubst $(PRINTF_DIR)%, %, $(wildcard $(PRINTF_DIR)*.c))
PRINTF_SRCS := $(addprefix other/ft_printf/,$(PRINTF_SRCS))

FLAGS := -Wall -Wextra -Werror
DEBUG_FLAGS := -g -O0

GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color

VPATH := $(LST_DIR) $(MEM_DIR) $(STR_DIR) $(OTHER_DIR) $(PRINTF_DIR)
.PHONY: clean re all fclean add_flags debug

OBJ = $(patsubst %.c, %.o, $(LST_SRCS) $(MEM_SRCS) $(STR_SRCS) $(OTHER_SRCS) $(PRINTF_SRCS))

all: $(NAME)

debug: fclean add_flags all

test:
	gcc -lft -L. test.c -o test.out $(addprefix -I,$(INCLUDES))

add_flags:
	$(eval FLAGS += $(DEBUG_FLAGS))

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "${GREEN}$(NAME) was created ${NC}"

%.o: %.c
	@gcc $(FLAGS) -c $(addprefix -I,$(INCLUDES)) $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	@echo "${YELLOW}$(NAME) was cleaned ${NC}"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "${YELLOW}$(NAME) was full cleaned ${NC}"

re: fclean all
