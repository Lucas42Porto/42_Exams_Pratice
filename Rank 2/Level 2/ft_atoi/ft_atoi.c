int	ft_atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	
	if (str[0] == '-')
		sign *= -1; 
	while(*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str++) - '0';
	}

	return (result * sign);
}