/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:14:03 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/08 14:38:49 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int size_binary(int max)
{
	int i;

	i = 0;
	while (1)
	{
		if (!(max>>i))
			break ;
		i++;
	}
	return(i);
}

t_node *new_index(t_node **a)
{
	int		i;
	t_node	*aux;
	t_node	*aux_index;
	t_node	*list_radix = NULL;
	
	aux = *a;
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

void	radix(t_node **a, t_node **b)
{
	int		i;
	int		value;
	int		max_binary;
	int		max_index;
	t_node *list_radix;
	
	max_binary = size_binary(position_max(a));
	list_radix = new_index(a);
	max_index = push_strlen(list_radix);
	i = 0;
	while (i < max_binary)
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
		while (push_strlen(*b) != 0)
			pa(&list_radix, b);
		i++;
	}	
}