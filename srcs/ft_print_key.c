#include "ft_select.h"

int		ft_print_key(unsigned char *b, t_select *select)
{
	(void)select;
	while (*b)
	{
		printf("%d\n", *b);
		b++;
	}
	return (1);
}
