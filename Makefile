# Project file
NAME = fractol

# Project builds and dirs
SRCDIR = ./src/
SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./include/
BUILDDIR = ./build/
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Libft builds and dirs
LIBDIR = ./libft/
LIBFT = ./libft/libft.a
LIBINC = ./libft/

# Optimization and Compiler flags and commands
CC = gcc
CFLAGS = -Wall -Wextra -Werror
GPUFLAG = -lmlx -framework OpenGL -framework AppKit -lm
# Main rule
all: $(BUILDDIR) $(NAME)

# Object dir rule
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Objects rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<

# Project file rule
$(NAME): $(BUILDOBJS)
	$(CC) $(CFLAGS) $(GPUFLAG) -o $(NAME) $(BUILDOBJS) $(LIBFT)

# Cleaning up the build files
clean:
	rm -rf $(BUILDDIR)

# Getting rid of the project file
fclean: clean
	rm -rf $(NAME)

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re