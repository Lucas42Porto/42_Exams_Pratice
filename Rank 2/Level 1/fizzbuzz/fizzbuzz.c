#include <unistd.h>

void ft_putnbr(int n)
{
	char	str[10] = "0123456789";

	if (n > 9)
		ft_putnbr(n / 10);
	write (1, &str[n % 10], 1);
}

int main ()
{
	int i;

	i=0;
	while(++i <= 100)
	{
		if (i % 3 == 0)
			write(1, "fizz", 4);
		if (i % 5 == 0)
			write(1, "buzz", 4);
		if ((i % 3 != 0) && (i % 5 != 0))
			ft_putnbr(i);
		write (1, "\n", 1);
	}

return(0);
}