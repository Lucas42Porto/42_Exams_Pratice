#include <unistd.h>

void repeat(char c, int i)
{
	while(i > 0)
	{
		write(1, &c, 1);
		i--;
	}

}

int main (int ac, char **av)
{
    if(ac == 2)
    {
        int i;

		i=0;
		while(av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				repeat(av[1][i], av[1][i] - 96);
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				repeat(av[1][i], av[1][i] - 64);
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}