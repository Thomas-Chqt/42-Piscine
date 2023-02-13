#include<unistd.h>

void ft_putchar(char c);

int main(){

    for (char i = '!'; i <= '~'; i++)
    {
        ft_putchar(i);
    }

    ft_putchar('\n');
    
    return 0;
}