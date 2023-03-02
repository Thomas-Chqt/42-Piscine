SRC="ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c"

for file in $SRC
do
	cc -Wall -Wextra -Werror -c $file
done

ar rcs libft.a *.o