#include "./sources/includes/ft_printf.h"
#include <stdio.h>

int main ()
{
	printf("-----------\n");
	ft_printf("%s", "this is a string");
	printf("\n-----------\n");
	ft_printf("%s ", "this is a string");
	printf("\n-----------\n");
	ft_printf("%s  ", "this is a string");

	return (0);
}
