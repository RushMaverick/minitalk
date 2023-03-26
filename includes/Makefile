NAME = libftprintf.a

SRC = \
ft_printf.c			ft_putchar_print.c		ft_putstr_print.c		ft_printf_utils1.c \
ft_printf_utils2.c	ft_putnbr_print.c		ft_hexbig.c				ft_hexsmol.c	\
ft_putusnbr.c		ft_putvoid.c

LIBFT_FILES = \
ft_bzero.c		ft_isalnum.c	ft_isalpha.c	ft_isascii.c \
ft_isdigit.c	ft_isprint.c	ft_memcpy.c		ft_memmove.c \
ft_memset.c		ft_memchr.c		ft_memcmp.c		ft_strlcpy.c \
ft_strlen.c		ft_strncmp.c	ft_tolower.c	ft_toupper.c \
ft_calloc.c		ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c \
ft_strchr.c		ft_strrchr.c	ft_strdup.c		ft_strlcat.c	\
ft_strnstr.c	ft_atoi.c		ft_substr.c		ft_strjoin.c	\
ft_strtrim.c	ft_putnbr_fd.c	ft_itoa.c		ft_strmapi.c	\
ft_striteri.c	ft_split.c	


all:  $(NAME)

$(NAME): 
	cc -Wall -Wextra -Werror -c $(SRC) $(LIBFT_FILES) 
	ar rc $(NAME) $(SRC:.c=.o) $(NAME)

clean:
	rm -f $(SRC:.c=.o) $(LIBFT_FILES:.c=.o) 

fclean: clean
	rm -f $(NAME)
re: fclean all
