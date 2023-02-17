#define MAX_INT 2147483647
#define MIN_INT -2147483648

#include<stdio.h>

void ft_putnbr(int nb);

int main()
{
	printf("Test with 42 : \n");
	ft_putnbr(42);
	printf("\nTest with -42 : \n");
	ft_putnbr(-42);
	printf("\nTest with 0 : \n");
	ft_putnbr(0);
	printf("\nTest with 402 : \n");
	ft_putnbr(402);
	printf("\nTest with MAX_INT : \n");
	ft_putnbr(MAX_INT);
	printf("\nTest with MIN_INT : \n");
	ft_putnbr(MIN_INT);
	printf("\n");
}