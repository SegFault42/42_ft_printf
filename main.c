#include "./includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void print_code_point_as_utf8(const unsigned int cp)
{
  if (cp < 128)
	putchar(cp);
  else if (cp < 2048)
  {
	putchar(192 | (cp >> 6));
	putchar(128 | (cp & 63));
	ft_putchar('\n');
  }
  else if (cp < 65536)
  {
	putchar(224 | (cp >> 12));
	putchar(128 | ((cp >> 6) & 63));
	putchar(128 | (cp & 63));
  }
  else if (cp < 1114112)
  {
	putchar(240 | (cp >> 18));
	putchar(128 | ((cp >> 12) & 63));
	putchar(128 | ((cp >> 6) & 63));
	putchar(128 | (cp & 63));
  }
}

int main ()
{
	int ret = 0;

	// printf("--------------------------------1------------------------------\n");
	// ft_putstr("ft_printf(\"\"); |");
	// ret = ft_printf("");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"\"); |");
	// ret = printf("");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// printf("\n------------------------------2--------------------------------\n");
	// ft_putstr("ft_printf(\"\\n\"); |");
	// ret = ft_printf("\n");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"\\n\"); |");
	// ret = printf("\n");
	// printf("| ret = %d", ret);
	//  printf("\n");
	//
	// printf("\n------------------------------3--------------------------------\n");
	// ft_putstr("ft_printf(\"test\") |");
	// ret = ft_printf("test");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"test\") |");
	// ret = printf("test");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// printf("\n------------------------------4--------------------------------\n");
	// ft_putstr("ft_printf(\"test\n\") |");
	// ret = ft_printf("test\n");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"test\n\") |");
	// ret = printf("test\n");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// printf("\n------------------------------5--------------------------------\n");
	// ft_putstr("ft_printf(\"1234\") |");
	// ret = ft_printf("1234");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"1234\") |");
	// ret = printf("1234");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// printf("\n------------------------------6--------------------------------\n");
	// ft_putstr("ft_printf(\"%%\") |");
	// ret = ft_printf("%%");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"%%\") |");
	// ret = printf("%%");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// printf("\n------------------------------7--------------------------------\n");
	// ft_putstr("ft_printf(\"%5%\") |");
	// ret = ft_printf("%5%");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"%5%\") |");
	// ret = printf("%5%");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// printf("\n------------------------------8--------------------------------\n");
	// ft_putstr("ft_printf(\"%5% Bonjour\") |");
	// ret = ft_printf("%5% Bonjour");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"%5% Bonjour\") |");
	// ret = printf("%5% Bonjour");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// printf("\n------------------------------9--------------------------------\n");
	// ft_putstr("ft_printf(\"%    %\") |");
	// ret = ft_printf("%    %");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"%    %\") |");
	// ret = printf("%    %");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// printf("\n------------------------------10--------------------------------\n");
	// ft_putstr("ft_printf(\"%-5%\") |");
	// ret = ft_printf("%-5%");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"%-5%\") |");
	// ret = printf("%-5%");
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// printf("\n------------------------------11--------------------------------\n");
	// ft_putstr("ft_printf(\"%x\", ULONG_MAX) |");
	// ret = ft_printf("%x", ULONG_MAX);
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"%x\", ULONG_MAX) |");
	// ret = printf("%x", ULONG_MAX);
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// printf("\n------------------------------12--------------------------------\n");
	// ft_putstr("ft_printf(\"%x\", -ULONG_MAX) |");
	// ret = ft_printf("%x", -ULONG_MAX);
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"%x\", -ULONG_MAX) |");
	// ret = printf("%x", -ULONG_MAX);
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// printf("\n------------------------------13--------------------------------\n");
	// ft_putstr("ft_printf(\"%10x\", ULONG_MAX) |");
	// ret = ft_printf("%10x", ULONG_MAX);
	// printf("| ret = %d", ret);
	// printf("\n");
	//
	// ft_putstr("   printf(\"%10x\", ULONG_MAX) |");
	// ret = printf("%10x", ULONG_MAX);
	// printf("| ret = %d", ret);
	// printf("\n");

	int i;

	ft_putstr("ft_printf(\"%lU%lU\", 0, USHRT_MAX) |");
	ret = ft_printf("%lU%lU", 0, USHRT_MAX);
	printf("| ret = %d", ret);
	printf("\n");

	ft_putstr("   printf(\"%lU%lU\", 0, USHRT_MAX) |");
	ret = printf("%lU%lU", 0, USHRT_MAX);
	printf("| ret = %d", ret);
	printf("\n");
	
	return (0);
}
