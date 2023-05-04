#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char* dup = ft_strdup(s);
	size_t idx;

	dup = ft_strdup(s);
	if (dup == NULL)
		return (NULL);
	idx = 0;
	while (dup[idx] != '\0')
	{
		dup[idx] = f(idx, dup[idx]);
		idx++;
	}
	return (dup);
}
