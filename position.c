/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:39:19 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/08 15:40:55 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_list(t_node **list)
{
	t_node	*aux;
	t_node	*aux_max;
	int		i;

	i = 0;
	aux = (*list)->next;
	aux_max = *list;
	while (aux)
	{
		if (aux_max->value < aux->value)
			aux_max = aux;
		aux = aux->next;
	}
	aux = *list;
	while (aux)
	{
		if (aux->value == aux_max->value)
			break ;
		i++;
		aux = aux->next;
	}
	return (i);
}

int	position_max(t_node **list, int i)
{
	t_node	*aux;
	t_node	*aux_max;
	int		max;

	aux = (*list)->next;
	aux_max = *list;
	while (aux)
	{
		if (aux_max->value < aux->value)
			aux_max = aux;
		aux = aux->next;
	}
	aux = *list;
	while (aux)
	{
		if (aux->value == aux_max->value)
			break ;
		i++;
		aux = aux->next;
	}
	max = aux->value;
	return (max);
}
