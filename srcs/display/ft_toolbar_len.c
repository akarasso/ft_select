#include "ft_select.h"

int		ft_toolbar_len(t_select *select)
{
	size_t		len_selection;
	size_t		len_mode;

	len_selection = 20 + ft_nbr_len(select->nselect);
	if (select->mode == SEARCH_MOD && !select->search)
		len_mode = 18;
	else if (select->mode == SEARCH_MOD && select->search)
		len_mode = 10 + ft_strlen(select->search);
	else if (select->mode == SELECT_MOD)
		len_mode = 14;
	else
		len_mode = 10;
	if (len_mode + len_selection >= select->win.width)
		return (2);
	return (1);
}
