#define MAX_INT 2147483647
#define MIN_INT -2147483648

#include<unistd.h>

void ft_putnbr(int nb);

int main()
{
	ft_putnbr(0);
	write(1, "\n", 1);
}