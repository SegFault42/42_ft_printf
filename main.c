#include "./includes/ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <limits.h>

int main ()
{
	int ret = 0;

	ft_putstr("ft_printf(\"{% d}\", -9999) |");
	ret = ft_printf("{% d}", -9999);
	printf("| ret = %d", ret);
	printf("\n");
	
	ft_putstr("   printf(\"{% d}\", -9999) |");
	ret = printf("{% d}", -9999);
	printf("| ret = %d", ret);
	printf("\n");
	return (0);
}
