#include "./sources/includes/ft_printf.h"
#include <stdio.h>

int main ()
{
	printf("test 1\n");
	ft_printf("Bonjour caca\n");
	printf("\ntest 2\n");
	ft_printf("%   %", "test");

	return (0);
}
