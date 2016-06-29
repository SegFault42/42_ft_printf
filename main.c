#include "./sources/includes/ft_printf.h"
#include <stdio.h>

int main ()
{
	int ret = 0;

	ret = ft_printf("%s %s", "this is", "a string");
	printf("\nret = %d\n", ret);
	printf("-----------\n");
	ret = printf("%s %s", "this is", "a string");
	printf("\nret = %d\n", ret);

	return (0);
}
