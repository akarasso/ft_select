#include "ft_select.h"


void	ft_fill_line(size_t curr, size_t max)
{
	while (curr < max)
	{
		ft_putstr(" ");
		curr++;
	}
}
