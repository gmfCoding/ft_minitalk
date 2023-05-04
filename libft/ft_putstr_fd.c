#include "libft.h"
#include <unistd.h>

void ft_putstr_fd(char *s, int fd)
{
	int length;

	length = ft_strlen(s);
	write(fd, s, length);
}
