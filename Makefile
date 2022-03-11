##
##  Makefile
##  TP3-LinkedListe
##
##  Created by Clain Dimitri & Vandenbossche Louis on 2022-02-15.
##

SRC	=	main.cpp \
		ManageNode.cpp

OBJ	=	$(SRC:.cpp=.o)

RM	=	rm -f

CPP	=	g++ -o

CPPFLAGS	=
LDFLAGS		=

NAME		=	LinkedListe

all: $(NAME)

$(NAME): CPPFLAGS += -Wall -Wextra -std=c++20
$(NAME):$(OBJ)
	$(CPP) $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
re:	fclean all

.PHONY:	all clean fclean re