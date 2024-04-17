#include <stdlib.h>
#include <stdio.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	int wc = 0;
	int k = 0;
	int i = 0;
	int j = 0; //init word

	char **words;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
	}
	words = (char **)malloc(sizeof(char*) * (wc + 1));
	i=0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{

			words[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(words[k++], &str[j], i - j);
		}
	}
	words[k] = NULL;
	return (words);

}

int main ()
{
	char **result = ft_split("u a b c ");

    int i = 0;
    while (result[i] != NULL)
    {
        printf("%s\n", result[i]);
        i++;
    }

    i = 0;
    while (result[i] != NULL)
    {
        free(result[i]);
        i++;
    }
    free(result);

    return 0;
}