#include "../includes/ft_printf.h"

void	init_struct(t_printf *printf)
{
	printf->ret = 0;
	printf->ret_wchar = 0;
	printf->valid = 0;
	printf->space_number = 0;
	printf->negatif = 0;
	printf->zero = 0;
	printf->d = 0;
}
