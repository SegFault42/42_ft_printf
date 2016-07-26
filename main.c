#include "./includes/ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <limits.h>

int main ()
{
	int ret = 0;

	ft_putstr("ft_printf(\"{%10d}\", 42) |");
	ret = ft_printf("{%10d}", 42);
	printf("| ret = %d", ret);
	printf("\n");

	ft_putstr("   printf(\"{%10d}\", 42) |");
	ret = printf("{%10d}", 42);
	printf("| ret = %d", ret);
	printf("\n");
	return (0);
}
