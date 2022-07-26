##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC 	= 	src/main.cpp	\
			src/Complet.cpp	\
			src/Complet_utils.cpp	\
			src/Parser.cpp	\

TEST_SRC	= test/Complet_test.cpp

CC	=	g++

CPPFLAGS =	-Iincludes -Wall -Wextra

TEST_CFLAGS	=	--coverage

TEST_LDFLAGS	=	-lcriterion -DUNIT_TEST

NAME	=	autoCompletion

TEST_NAME	=	unit_tests

all :		$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(CPPFLAGS)

test_run:
		@$(CC) $(TEST_SRC) -o $(TEST_NAME) $(TEST_LDFLAGS) $(TEST_CFLAGS) $(CPPFLAGS)
		@echo -e "Compile with $(SRC)files : OK"
		@echo -e "Compile with $(LDFLAGS) $(CPPFLAGS) flags : OK)"
		@echo -e "Unit tests compile"
		./$(TEST_NAME)

coverage:
		gcovr -b  --exclude-directories test
		gcovr -r  . --exclude-directories test
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean test_run coverage
