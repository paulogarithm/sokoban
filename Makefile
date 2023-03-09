##
## EPITECH PROJECT, 2022
## radar
## File description:
## Makefile
##


## ---------- ##

BIN		= my_sokoban

INC		= -lncurses

SRC		= src/main.c\
		src/soko_map_setup.c\
		src/soko_map_parcing.c\
		src/soko_valid.c\
		src/soko_loop.c\
		src/soko_action.c\
		src/soko_checks.c\
		src/soko_check_corners.c\


## ---------- ##

CC	  = gcc
RM	  = rm -rf

LIB 	= lib/my_putchar.c\
		lib/my_putstr.c\
		lib/my_countnb.c\
		lib/my_countstr.c\
		lib/my_addchar.c\
		lib/my_addstr.c\
		lib/my_conv_nb_str.c\
		lib/my_conv_str_nb.c\
		lib/my_conv_str_array.c\
		lib/my_printf.c\
		lib/my_scanf.c\
		lib/my_compstr.c\
		lib/my_dupstr.c\
		lib/my_isnb.c\
		lib/my_rand.c\
		lib/my_revstr.c\
		lib/my_cutstr.c\
		lib/my_find.c\

SRCOBJ  = $(SRC:.c=.o)
LIBOBJ  = $(LIB:.c=.o)

LIBNAME = lib$(BIN).a

CFLAGS  = -W -Wall -Wextra


## ---------- ##

all: build

build: $(LIBOBJ) $(SRCOBJ)
	ar rc $(LIBNAME) $(LIBOBJ) $(SRCOBJ)
	gcc $(CFLAGS) -L. -l$(BIN) $(INC) -o $(BIN)

clean:
	$(RM) $(SRCOBJ)
	$(RM) $(LIBOBJ)
	$(RM) $(LIBNAME)
	$(RM) *.c~

fclean: clean
	$(RM) $(SRCNAME)
	$(RM) $(BIN)

re: fclean build
	make clean

.PHONY:
	clean fclean re build all
