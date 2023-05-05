INCS = ft_lprintf.h ../ft_printf.h

# SOURCE FILES
SRCS = 	ft_printf.c \
		ft_putchar_sfd.c \
		ft_putstr_sfd.c	\
		ft_putnb_sfd.c \
		ft_puthex_sfd.c


NAME = libftprintf.a
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
$(OBJDIR)%.o: %.c $(INCS)
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

