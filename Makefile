CC=gcc

SRCDIR=srcs
LIBDIR=.
LIBDIRA=libft
HEADDIR=includes

CFLAGS=-I$(HEADDIR) -Wall -Wextra -Werror
LDFLAGS=-I$(HEADDIR) -L$(LIBDIRA) -lmlx -lft -framework OpenGL -framework AppKit

NAME=fdf

SRC=$(SRCDIR)/main.c\
	$(SRCDIR)/draw.c\
	$(SRCDIR)/projection.c\
	$(SRCDIR)/reader.c\
	$(SRCDIR)/valfile.c\
	$(SRCDIR)/get_file_lines.c\

OBJ=$(LIBDIR)/main.o\
	$(LIBDIR)/draw.o\
	$(LIBDIR)/projection.o\
	$(LIBDIR)/reader.o\
	$(LIBDIR)/valfile.o\
	$(LIBDIR)/get_file_lines.o\

all: $(NAME)

$(NAME) : $(OBJ)
	make re -C $(LIBDIR)/libft
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY:clean fclean

clean:
	make clean -C $(LIBDIR)/libft
	rm -rf $(LIBDIR)/*.o

fclean: clean
	make fclean -C $(LIBDIR)/libft
	rm -rf $(NAME)

re: fclean all
