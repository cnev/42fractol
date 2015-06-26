#include "../include/fractol.h"
#include <stdlib.h>

static t_llist		*new_llist(void *data)
{
	t_llist			*new;

	if (!(new = (t_llist *)malloc(sizeof(t_llist))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void				llist_pushback(t_llist **first, void *data)
{
	t_llist			*tmp;

	if (!*first)
	{
		*first = new_llist(data);
		return ;
	}
	tmp = *first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_llist(data);
}
