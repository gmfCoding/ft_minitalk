# TARGET NAME AND VARIBLES
NAME = libftall.a
OBJDIR = obj/
CC = clang
FLAGS = $(DFLAGS) -Wall -Wextra -Werror

PRINTF = printf/libftprintf.a
GETNL = gnl/libgnl.a
LIBFT = libft/libft.a

DEPS = $(LIBFT) $(GETNL) $(PRINTF)  

# ANY
all: $(NAME)

# CLEAN
re: fclean all

$(PRINTF): 
	@make -s -C printf
	@mkdir -p libtmp
	@cd libtmp; ar -x ../$(PRINTF)

$(GETNL): 
	@make -s -C gnl
	@mkdir -p libtmp
	@cd libtmp; ar -x ../$(GETNL)
	
$(LIBFT): 
	@make -s -C libft
	@mkdir -p libtmp
	@cd libtmp; ar -x ../$(LIBFT)

# BUILD LIBRARY
$(NAME): $(DEPS)
	@mkdir -p libtmp
	@ar rcs $(NAME) ./libtmp/*.o

fclean: clean
	@make -s -C ./printf lclean
	@make -s -C gnl lclean
	@make -s -C libft lclean
	rm -rf ./libtmp
	rm -f $(NAME)

clean:
	@echo "Cleaning $(NAME) objects"
	@make -s -C gnl clean
	@make -s -C libft clean
	@make -s -C printf clean
	@rm -rf $(OBJDIR)

.PHONY: clean all re fclean