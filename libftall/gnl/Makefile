INCS = ../get_next_line.h

# SOURCE FILES
SRCS = 	get_next_line.c \
		get_next_line_utils.c

NAME = libgnl.a
OBJDIR = obj/
CC = cc
CFLAGS = $(DFLAGS) -I../ -Wall -Wextra -Werror

# OBJECT FILES
OBJ = $(patsubst %.c,$(OBJDIR)%.o, $(SRCS))

# NAME IS SUPPLIED VIA HIGHER MAKEFILES
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
