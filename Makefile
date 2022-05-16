NAME			=	ft_containers

GTEST			=	gtest_bin

SRCS			=	main.cpp

HEADERS			=	${INC_FLD}stack.hpp \
					${INC_FLD}vector.hpp

INC_FLD			=	includes/

GTEST_FLD_INC	=	/mnt/nfs/homes/axaidan/Documents/googletest/include/

GTEST_FLD_LIB	=	/mnt/nfs/homes/axaidan/Documents/googletest/lib/

OBJS			=	${addprefix srcs/,${SRCS:.cpp=.o}}

CXX				=	c++

CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98

SANITIZE_FLAGS	=	-fsanitize=thread -Wall -Wextra -Werror -std=c++98

GTEST_FLAGS		=	-pthread -Wall -Wextra -Werror -std=c++98


all			:	${NAME}

${NAME}		:	${OBJS}
			${CXX} ${CXXFLAGS} -I ${INC_FLD} ${OBJS} -o ${NAME}


%.o			:	%.cpp ${HEADERS}
			${CXX} ${CXXFLAGS} -I ${INC_FLD} -c $< -o ${<:.cpp=.o}
#			${CXX} ${SANITIZE_FLAGS} -I ${INC_FLD} -c $< -o ${<:.cpp=.o}

clean		:
			rm -rf ${OBJS}

fclean		:	clean
			rm -rf ${NAME}

re			:	fclean all

test		:
			g++ -pthread -I ${GTEST_FLD_INC} -I ${INC_FLD} -c -o srcs/main.o srcs/main.cpp
			g++ -o ${GTEST_BIN} srcs/main.o -L ${GTEST_FLD_LIB} -pthread
			./${GTEST_BIN}

sanitize	:	${OBJS}
			${CXX} ${SANITIZE_FLAGS} ${OBJS} -o ${NAME}

leaks		:	$(NAME)
			valgrind --suppressions=valgrind_ignore.txt \
			--child-silent-after-fork=yes \
			--leak-check=full --show-leak-kinds=all --track-origins=yes \
			--log-file=valgrind-out.txt \

.PHONY		:	all re clean fclean
