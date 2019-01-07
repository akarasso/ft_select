#include "ft_select.h"

int		ft_print_key(unsigned char *b, t_select *select)
{
	(void)select;
	printf("LAAAA\n");
	while (*b)
	{
		printf("Val:%d\n", *b);
		write(1, " ", 1);
		b++;
	}
	return (1);
}
