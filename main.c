#include "./includes/ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <limits.h>

int main ()
{
	int ret = 0;

	/*ft_putstr("ft_printf(\"{%15.4d}\", 42) |");*/
	/*ret = ft_printf("{%15.4d}", 42);*/
	/*printf("| ret = %d", ret);*/
	/*printf("\n");*/

	/*ft_putstr("   printf(\"{%15.4d}\", 42) |");*/
	/*ret = printf("{%15.4d}", 42);*/
	/*printf("| ret = %d", ret);*/
	/*printf("\n");*/
	ft_putstr("ft_printf(\"{%05p}\", 0) |");
	ret = ft_printf("{%05p}", 0);
	printf("| ret = %d", ret);
	printf("\n");

	ft_putstr("   printf(\"{%05p}\", 0) |");
	ret = printf("{%05p}", 1);
	printf("| ret = %d", ret);
	printf("\n");
	return (0);
}
