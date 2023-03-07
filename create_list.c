/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:31:43 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/03 17:43:31 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*criate_list(char *num)
{
	t_node	*aux;

	aux = malloc(sizeof(t_node));
	aux->value = atoi(num);
	aux->next = NULL;
	return (aux);
}

t_node	*node_last(t_node *list)
{
	t_node	*last;

	last = list;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void linkar(t_node **lista, t_node *atual)
{
	if (lista == NULL)
		return;
	if (*lista == NULL)
	{
		*lista = atual;
		return;
	}
	atual->next = *lista;
	*lista = atual;
}

void	link_end(t_node **list, t_node *atual)
{
	t_node	*aux;

	if (list == NULL)
		return ;
	if (*list == NULL)
	{
		*list = atual;
		return ;
	}
	aux = node_last(*list);
	aux->next = atual;
}

