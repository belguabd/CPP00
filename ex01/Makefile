FLAGS=c++ -Wall -Wextra -Werror -std=c++98 

NAME=PhoneBook

SRC=main.cpp PhoneBook.cpp Contact.cpp

OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)


%.o : %.cpp PhoneBook.hpp Contact.hpp
	$(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all 