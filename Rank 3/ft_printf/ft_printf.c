#include<stdarg.h>
#include<unistd.h>

void put_string(char *string, int *lenght)
{
	if(!string)
		string = "(null)";
	while (*string)
		*lenght += write(1, string++, 1);	
}

void	put_digit(long long int number, int base, int *length)
{
	char *hexa = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, length);
	*length += write(1, &hexa[number % base], 1);
}

int ft_printf(const char *format, ... )
{
	int lenght = 0;

	va_list pointer;
	va_start(pointer, format);

	while(*format)
	{
		if ( (*format == '%') && ((*(format + 1) == 'x') || (*(format + 1) == 's') || (*(format + 1) == 'd')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &lenght);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &lenght);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &lenght);
		}
		else
			lenght += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), lenght);
}