NAME			=	ft_containers

GTEST			=	gtest_bin

GTEST_SRCS		=	srcs/gtest.cpp

SRCS			=	main.cpp

HEADERS			=	${INC_FLD}stack.hpp \
					${INC_FLD}vector.hpp \
					${INC_FLD}type_utils.hpp \
					${INC_FLD}ContainsAlloc.hpp

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

vgtest		:	srcs/gtest.cpp includes/vector.hpp
			${CXX} ${CXXFLAGS} -I ${INC_FLD} srcs/main.cpp -o srcs/main.o
			rm -rf srcs/main.o
			c++ -pthread -D${ARG} -I ${GTEST_FLD_INC} -I ${INC_FLD} -c -o srcs/gtest.o srcs/gtest.cpp
			c++ -pthread -D${ARG} -o ${GTEST} srcs/gtest.o -L ${GTEST_FLD_LIB} -lgtest 
			valgrind ./${GTEST}

gtest_vector		:	srcs/gtest.cpp includes/vector.hpp
			${CXX} ${CXXFLAGS} -I ${INC_FLD} srcs/main.cpp -o srcs/main.o
			rm -rf srcs/main.o
			c++ -pthread -D${ARG} -I ${GTEST_FLD_INC} -I ${INC_FLD} -c -o srcs/gtest.o srcs/gtest.cpp
			c++ -pthread -D${ARG} -o ${GTEST} srcs/gtest.o -L ${GTEST_FLD_LIB} -lgtest 
			./${GTEST}

test_pair	:	includes/pair.hpp srcs/main_pair.cpp
			${CXX} -D${ARG} ${CXXFLAGS} -I ${INC_FLD} srcs/main_pair.cpp -o test_pair
			
test_map	:	includes/map.hpp includes/rbnode.hpp srcs/main_map.cpp \
	includes/map_iterator.hpp
			#${CXX} -D${ARG} ${CXXFLAGS} -I ${INC_FLD}
			${CXX} ${CXXFLAGS} -I ${INC_FLD} \
				srcs/main_map.cpp -o test_map

.PHONY		:	all re clean fclean
