#include "./includes/ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <limits.h>

int main ()
{
	int ret = 0;

	/*ft_putstr("ft_printf(\"%4.15S\", \"我是一只猫。\") |");*/
	/*ret = ft_printf("%4.15S", L"我是一只猫。");*/
	/*printf("| ret = %d", ret);*/
	/*printf("\n");*/

	/*ft_putstr("   printf(\"%4.s\", \"42\") |");*/
	/*ret = printf("%15.4S", L"我是一只猫。");*/
	/*printf("| ret = %d", ret);*/
	/*printf("\n");*/

	ft_putstr("ft_printf(\"%.5p\", 0) |");
	ret = ft_printf("%.5p", 9);
	printf("| ret = %d", ret);
	printf("\n");

	ft_putstr("   printf(\"%.5p\", 0) |");
	ret = printf("%.5p", 9);
	printf("| ret = %d", ret);
	printf("\n");
	return (0);
}
