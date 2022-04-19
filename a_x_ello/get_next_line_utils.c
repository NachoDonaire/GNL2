#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	unsigned long	i;

	i = 0;
	p = (void *)malloc(nmemb * size);
	if (!p)
		return (0);
	while (i < nmemb * size)
	{
		((char *)p)[i] = '\0';
		i = i + 1;
	}
	return (p);
}

static int	lens(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i = i + 1;
	return (i);
}

static char	*copy(const char *s1, const char *s2, char *x)
{
	int		i;
	int		y;
	char	aux;

	i = 0;
	y = 0;
	while (s1[i])
	{
		aux = s1[i];
		x[i] = aux;
		i++;
	}
	while (s2[y])
	{
		aux = s2[y];
		x[i] = aux;
		y++;
		i++;
	}
	x[i] = '\0';
	return (x);
}

static char	*cncat(const char *s1, const char *s2)
{
	char	*x;

	if (s1 && s2)
	{
		x = malloc((lens((char *)s1) + lens((char *)s2) + 1) * sizeof(char));
		if (!x)
			return (0);
		x = copy(s1, s2, x);
		return (x);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	int		z;
	char	*x;

	if (s1 && s2)
	{
		i = lens(s1);
		z = 0;
		y = lens(s2);
		x = cncat(s1, s2);
		return (x);
	}
	return (0);
}
/*
int main()
{
	char *s1 = "holaa";
	char *s2 = malloc(sizeof(char) * 3);
	int i;
	s1 = joinstr(s1, s2);
	i = lens(s2);
	s1[6] = 'c';
	s1[100] = 'f';
	printf("%c", s1[6]);
	system("leaks a.out");
	return (0);
}*/
