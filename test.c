# include "push_swap.h"


int	duplicated(t_node **list)
{
	t_node *aux;
	t_node *aux_aux;

	aux = *list;
	while(aux != NULL)
	{
		aux_aux = aux->next;
		while (aux_aux != NULL)
		{
			if (aux_aux->value == aux->value)
				return (0);
			aux_aux = aux_aux->next;
		}
		aux = aux->next;
	}
	return (1);
}
