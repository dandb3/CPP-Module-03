NAME		=	a.out
SRCS		=	main.cpp Fixed.cpp
OBJS		=	$(SRCS:.cpp=.o)
HEADERS		=	Fixed.hpp

CXX		=	c++
CXXFLAGS	=	-Werror -Wall -Wextra -std=c++98
RM		=	rm
RMFLAGS		=	-rf

all		:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o		:	%.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean		:
	$(RM) $(RMFLAGS) $(OBJS)

fclean		:	clean
	$(RM) $(RMFLAGS) $(NAME)

re		:
	make fclean
	make all

.PHONY		:	all clean fclean re
