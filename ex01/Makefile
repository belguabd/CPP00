FLAGS=c++ #-Wall -Wextra -Werror -std=c++98

NAME=PhoneBook

SRC=main.cpp PhoneBook.cpp Contact.cpp

OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all 