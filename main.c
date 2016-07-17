#include "./includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

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

	ft_putstr("ft_printf(\"%lc, %lc\", '米', '米') |");
	ret = ft_printf("%lc, %lc", L"米", L"米");
	printf("| ret = %d", ret);
	printf("\n");

	ft_putstr("   printf(\"%lc, %lc\", '米', '米') |");
	ret = printf("%lc, %lc", L"米", L"米");
	printf("| ret = %d", ret);
	printf("\n");
	return (0);
}
