#include<stdio.h>


void ft_print_combn(int n);


int main() {
    for (int i = -1; i <= 11; i++)
    {
        printf("Test with %d :\n", i);
        ft_print_combn(i);
        printf("\n");
        printf("\n");
    }
    return 0;
}
