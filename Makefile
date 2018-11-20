NAME=fdf

OBJECTS=main.o display.o fdf.o display_fdf.o draw.o hooks.o

COMPILE=gcc -Wall -Wextra -Werror -O3

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft
	make -C minilibx
	$(COMPILE) -framework OpenGL -framework Appkit -o $@ $^ libft/libft.a minilibx/libmlx.a

%.o: %.c fdf.h display.h
	$(COMPILE) -c $<

clean:
	make clean -C libft
	make clean -C minilibx
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all

cclean: all clean
