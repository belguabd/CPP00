FLAGS=c++ -Wall -Wextra -Werror -std=c++98

NAME=megaphone

SRC=megaphone.cpp 

OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp  
	$(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all