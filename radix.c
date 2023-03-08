/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:14:03 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/08 19:21:39 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_binary(int max)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!(max >> i))
			break ;
		i++;
	}
	return (i);
}

t_node	*new_index(t_node **a)
{
	int		i;
	t_node	*aux;
	t_node	*aux_index;
	t_node	*list_radix;

	aux = *a;
	list_radix = NULL;
	while (aux != NULL)
	{
		i = 0;
		aux_index = *a;
		while (aux_index != NULL)
		{
			if (aux->value > aux_index->value)
				i++;
			aux_index = aux_index->next;
		}
		link_end(&list_radix, criate_list(ft_itoa(i)));
		aux = aux->next;
	}
	return (list_radix);
}

void	radix(t_node **a, t_node **b, int max_index)
{
	int		i;
	int		value;
	int		max_binary;
	t_node	*list_radix;

	max_binary = size_binary(position_max(a, 0));
	list_radix = new_index(a);
	i = 0;
	while (order(&list_radix) != 0)
	{
		value = 0;
		while (value < max_index)
		{
			if ((list_radix->value >> i) & 1)
				ra(&list_radix);
			else
				pb(&list_radix, b);
			value++;
		}
		while (*b)
			pa(&list_radix, b);
		i++;
	}
    ft_free(list_radix);
}
