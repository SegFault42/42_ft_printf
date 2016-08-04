#include "./includes/ft_printf.h"
#include "./libft/includes/libft.h"
#include <stdio.h>
#include <wchar.h>
#include <limits.h>

int main ()
{
	int ret = 0;

	ft_putstr("ft_printf(\"%-#6o\", 2500)|");
	ret = ft_printf("%-#6o", 2500);
	printf("| ret = %d", ret);
	printf("\n");

	ft_putstr("   printf(\"%-#6o\", 2500)|");
	ret = printf("%-#6o", 2500);
	printf("| ret = %d", ret);
	printf("\n");

	/*ft_putstr("ft_printf(\"@moulitest: %5.x, %5.0x\", 0, 0)|");*/
	/*ret = ft_printf("@moulitest: %5.x, %5.0x", 0, 0);*/
	/*printf("| ret = %d", ret);*/
	/*printf("\n");*/

	/*ft_putstr("   printf(\"@moulitest: %5.x, %5.0x\", 0, 0)|");*/
	/*ret = printf("@moulitest: %5.x, %5.0x", 0, 0);*/
	/*printf("| ret = %d", ret);*/
	/*printf("\n");*/

	return (0);
}


