
NAME	= fractol

SRC     = src/main.c src/util.c

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -I includes $(SRC) -o $(NAME) -L libft/ -lft -lmlx -lXext -lX11 -lm
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Fractol"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -I includes -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libprintf"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libprintf"

re: fclean all

test: re
	printf '\033[32m%s\n\033[0m' "-------------------------------------"
	./fdf

all: $(NAME)
.PHONY: clean fclean re all
