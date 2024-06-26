#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i])
	{
		if (ft_strchr(accept, s[i]) == 0)
			break;
		++i;
	}
	return (i);
}

// int main(int ac, char *av)
// {
// 	char *s1 = "Teste aceito";
// 	char *t1 = "T aceito";
// 	char *t2 = " rejeita";

// 	int len = ft_strspn(s1, t1);
// 	printf("%d\n", len);
// 	len = strspn(s1, t1);
// 	printf("%d\n", len);
// 	len = ft_strspn(s1, t2);
// 	printf("%d\n", len);
// 	len = strspn(s1, t2);
// 	printf("%d\n", len);

// }