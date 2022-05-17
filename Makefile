NAME			=	ft_containers

GTEST			=	gtest_bin

GTEST_SRCS		=	srcs/gtest.cpp

SRCS			=	main.cpp

HEADERS			=	${INC_FLD}stack.hpp \
					${INC_FLD}vector.hpp

INC_FLD			=	includes/

GTEST_FLD_INC	=	.	

GTEST_FLD_LIB	=	./gtest

OBJS			=	${addprefix srcs/,${SRCS:.cpp=.o}}

CXX				=	c++

CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98

GTEST_FLAGS		=	-pthread -Wall -Wextra -Werror -std=c++98


all			:	${NAME}

${NAME}		:	${OBJS}
			${CXX} ${CXXFLAGS} -I ${INC_FLD} ${OBJS} -o ${NAME}


%.o			:	%.cpp ${HEADERS}
			${CXX} ${CXXFLAGS} -I ${INC_FLD} -c $< -o ${<:.cpp=.o}

clean		:
			rm -rf ${OBJS}

fclean		:	clean
			rm -rf ${NAME}

re			:	fclean all

gtest		:	srcs/gtest.cpp
			${CXX} ${CXXFLAGS} -I ${INC_FLD} srcs/main.cpp -o srcs/main.o
			rm -rf srcs/main.o
			c++ -pthread -I ${GTEST_FLD_INC} -I ${INC_FLD} -c -o srcs/gtest.o srcs/gtest.cpp
			c++ -pthread -o ${GTEST} srcs/gtest.o -L ${GTEST_FLD_LIB} -lgtest 
			./${GTEST}

.PHONY		:	all re clean fclean
