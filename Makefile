##
## EPITECH PROJECT, 2021
## ex00
## File description:
## Makefile
##

SRC =	sources/strlen.asm \
		sources/strchr.asm \
		sources/strcmp.asm \
		sources/strncmp.asm \
		sources/strpbrk.asm \
		sources/memset.asm \
		sources/strrchr.asm \
		sources/memcpy.asm \
		sources/strcspn.asm \
		sources/strcasecmp.asm \
		sources/strstr.asm \
		sources/memmove.asm \
		sources/index.asm \
		sources/rindex.asm \

OBJ = $(SRC:.asm=.o) $(MAIN:.asm=.o)

POOL = -std=c++20 -Wall -Wextra

CFLAGS = -Wall -Wextra -Wpedantic -g3

NCURSES = -lncurses

NASM = nasm -f elf64

LDFLAGS = -shared

NAME = libasm.so

%.o:%.asm
		$(NASM) $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	@ld -o $(NAME) $(LDFLAGS) $(OBJ)

clean:
	rm -f ./sources/*.o
	rm -f *.gcda *.gcno

fclean: clean
	rm -rf $(NAME)

re:	fclean all

tests_run: all $(TEST_OBJ)
	gcc -lcriterion --coverage -ldl -I./include -o test tests/*.c
	./test


.PHONY:	all re clean fclean