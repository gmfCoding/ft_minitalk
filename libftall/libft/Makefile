# SOURCE FILES
SRCS1 = 	ft_strlen.c		\
		ft_isalpha.c 	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_atoi.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memset.c		\
		ft_memchr.c		\
		ft_memmove.c	\
		ft_memcmp.c		\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_calloc.c		\
		ft_strdup.c		

SRCS2 = ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\

# BONUS SOURCE FILES
SRCSB =	ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstadd_back.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c


SRCS = $(SRCS1) $(SRCSB)
NAME = libft.a
INCS = ../libft.h
OBJDIR = obj/
CC = cc
CFLAGS = $(DFLAGS) -I../ -Wall -Wextra -Werror

# OBJECT FILES
OBJ = $(patsubst %.c,$(OBJDIR)%.o, $(SRCS))
all: $(NAME)

# BUILD LIBRARY
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

# COMPILE SOURCES
$(OBJ): $(OBJDIR)%.o: ./%.c $(INCS)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	@echo "Cleaning $(NAME) objects"
	@-rm -rf $(OBJDIR)

lclean:
	@echo "Cleaning $(NAME)"
	@rm -f $(NAME)

fclean: clean lclean

.PHONY: clean all re fclean lclean
