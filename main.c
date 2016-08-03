#include "./includes/ft_printf.h"
#include "./libft/includes/libft.h"
#include <stdio.h>
#include <wchar.h>
#include <limits.h>

int main ()
{
	int ret = 0;

	/*ft_putstr("ft_printf(\"%4.15S\", L\"我是一只猫。\")|");*/
	/*ret = ft_printf("%4.15S", L"我是一只猫。");*/
	/*printf("| ret = %d", ret);*/
	/*printf("\n");*/

	/*ft_putstr("   printf(\"%4.15S\", L\"我是一只猫。\") |");*/
	/*ret = printf("%4.4S", L"我是一只猫。");*/
	/*printf("| ret = %d", ret);*/
	/*printf("\n");*/

	ft_putstr("ft_printf(\"%#llx\", 9223372036854775807)|");
	ret = ft_printf("%#llx", 9223372036854775807);
	printf("| ret = %d", ret);
	printf("\n");

	ft_putstr("   printf(\"%#llx\", 9223372036854775807)|");
	ret = printf("%#llx", 9223372036854775807);
	printf("| ret = %d", ret);
	printf("\n");

	return (0);
}


