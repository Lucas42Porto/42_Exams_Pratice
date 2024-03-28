void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main (int ac, char **av)
{
    if(ac == 2)
    {
        int i;

		i=0;
        while(av[1][i])
        {
            if(av[1][i] == " " || av[1][i] == "\t")
                i++;
        }
        while((av[1][i] >= "a" && av[1][i] <= "z") || (av[1][i] >= "A" && av[1][i] <= "Z"))
            ft_putchar(av[1][i++]);
    }
	ft_putchar("\n");
	return(0);
}