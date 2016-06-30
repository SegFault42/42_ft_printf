#include "./sources/includes/ft_printf.h"
#include <stdio.h>

int main ()
{
	int ret = 0;

	printf("\n---------------------------------------------------------------\n");
	ft_putstr("ft_printf(\"\"); =");
	ret = ft_printf("");
	printf("| ret = %d", ret);
	printf("\n");

	ft_putstr("   printf(\"\"); =");
	ret = printf("");
	printf("| ret = %d", ret);
  printf("\n");

	printf("\n---------------------------------------------------------------\n");
	ft_putstr("ft_printf(\"\\n\"); =");
	ret = ft_printf("\n");
	printf("| ret = %d", ret);
	printf("\n");

	ft_putstr("   printf(\"\\n\"); =");
	ret = printf("\n");
	printf("| ret = %d", ret);
  printf("\n");

	printf("\n---------------------------------------------------------------\n");
	ft_putstr("ft_printf(\"test\") =");
	ret = ft_printf("test");
	printf("| ret = %d", ret);
	printf("\n");

	ft_putstr("   printf(\"test\") =");
	ret = printf("test");
	printf("| ret = %d", ret);
	printf("\n");

	return (0);
}
