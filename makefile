CC = gcc
CFLAGC = -Wall -Werror -Wextra
RM = rm -f
NAME = pipex
files = check_cmd.c execute_cmd.c ft_calloc.c ft_strjoin.c ft_strnstr.c ft_substr.c grep_path.c pipex.c ft_split.c \
		ft_strchr.c ft_strdup.c 

OBJECT =$(files:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CC) $(CFLAGC) $^ -o $@

clean : 
	$(RM) $(OBJECT)

fclean : clean 
	$(RM) $(NAME)

re : fclean all