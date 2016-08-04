#include "./includes/ft_printf.h"
#include "./libft/includes/libft.h"
#include <stdio.h>
#include <wchar.h>
#include <limits.h>

int main ()
{
	int ret = 0;

	ft_putstr("ft_printf(\"%05o\", 42)|");
	ret = ft_printf("%05o", 42);
	printf("| ret = %d", ret);
	printf("\n");

	ft_putstr("   printf(\"%05o\", 42)|");
	ret = printf("%05o", 42);
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


