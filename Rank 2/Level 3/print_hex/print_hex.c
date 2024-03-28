#include <unistd.h>


int ft_atoi(char *str)
{
	int nbr;
	int i;

	i=0;
	while(str[i])
	{
		nbr *= 10;
		nbr += str[i++] - '0';
	}
	return (nbr);
}

void printhex(int n)
{
	char hex[] = "0123456789abcdef";
	
	if (n >= 16)
		printhex(n / 16);
	write(1, &hex[n % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printhex(ft_atoi(av[1]));
	}
	write(1, "\n", 1);
	return 0;
}