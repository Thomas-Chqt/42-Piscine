#include <unistd.h>

#define max_len 9

int ft_add_one(char str[], int len);
void    ft_setup(char str[], int len);
int ft_need_print(char str[], int len);
int ft_is_over(char str[], int len);


void    ft_print_combn(int n)
{
    char str[max_len];

    if (n < 1 || n > 9) 
        return;

    ft_setup(str, n);

    write(1, &str, n);

    while(ft_add_one(str, n) && !ft_is_over(str, n)) {
        if (ft_need_print(str, n))
        {
            write(1, ", ", 2);
            write(1, &str, n);
        }        
	}

    write(1, ", ", 2);
    write(1, &str, n);

}

// return 0 if over
int ft_add_one(char str[], int len)
{
    int i;

    i = len - 1;
    while (i >= 0)
    {
        if (str[i] == '9')
		{
			str[i] = '0';
		}
		else
		{
			str[i] = str[i] + 1;
            return (1);
		}

        i--;
    }
    
	return (0);
}

void    ft_setup(char str[], int len)
{
    int i;

    str[0] = '0';

    i = 1;
    while (i < len)
    {
        str[i] = str[i-1] + 1; 
        i++;
    }
}

int ft_need_print(char str[], int len)
{
    int i;

    i = 1;
    while (i <= len - 1)
	{
        if (str[i] <= str[i - 1]) return 0;
        i++;
	}

    return 1;
}

int ft_is_over(char str[], int len)
{
    int i;

    i = len - 1;
    if (str[len - 1] != '9')
        return (0);
    
    while (i >= 1)
	{
        if (str[i] != str[i - 1] + 1) 
            return (0);
        i--;
	}
    
    return (1);
}
