#include "ft_select.h"

int		ft_print_key(unsigned char *b, t_select *select)
{
	(void)select;
	while (*b)
	{
		printf("Val:%d\n", *b);
		write(1, " ", 1);
		b++;
	}
	getchar();
	return (1);
}
