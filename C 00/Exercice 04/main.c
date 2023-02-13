#include<stdio.h>

void ft_is_negative(int n);

int main()
{
    printf("test with 1 : \n"); 
    ft_is_negative(1);
    printf("\n");

    printf("test with -1 : \n");
    ft_is_negative(-1);
    printf("\n");


    printf("test with 0 : \n");
    ft_is_negative(0);
    printf("\n");

    
    printf("test with 2,147,483,647 : \n");
    ft_is_negative(2147483647);
    printf("\n");

    printf("test with -2,147,483,648 : \n");
    ft_is_negative(-2147483648);
    printf("\n");

    return 0;
}
