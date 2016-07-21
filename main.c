#include "./includes/ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <limits.h>

int main ()
{
	int ret = 0;

	ft_putstr("ft_printf(\"{%+03d}\", 0) |");
	ret = ft_printf("{%+03d}", 0);
	printf("| ret = %d", ret);
	printf("\n");
	
	ft_putstr("   printf(\"{%+03d}\", 0) |");
	ret = printf("{%+03d}", 0);
	printf("| ret = %d", ret);
	printf("\n");
	return (0);
}
