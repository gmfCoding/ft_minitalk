#include "libft.h"
#include <stdio.h>

void main()
{
	// 16
	// 13
	//char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	//char **ret = ft_split("Hello,World,,Goodbye,Works?", ',');
	char **ret = ft_split("\0aa\0bbb", '\0');
 	
	while (*ret)
	{
		printf("%s\n", *ret);
		ret++;
	}	
}
