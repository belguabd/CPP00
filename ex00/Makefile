FLAGS=c++ -Wall -Wextra -Werror -std=c++98

NAME=megaphone

SRC=megaphone.cpp 

OBJ=$(SRC:.cpp=.o)


$(NAME) : $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all 