/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:19:35 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/08 19:56:12 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*aux;
	t_node	*aux_aux;

	aux = *a;
	while (aux != NULL)
	{
		if (aux->next->next == NULL)
		{
			aux_aux = aux->next;
			aux->next->next = *a;
			aux->next = NULL;
			break ;
		}
		aux = aux->next;
	}
	aux_aux->next = *a;
	*a = aux_aux;
	write(1, "rra\n", 4);
}

void	pa(t_node **a, t_node **b)
{
	t_node	*aux;

	linkar(a, criate_list((*b)->value));
	aux = (*b)->next;
	free(*b);
	*b = aux;
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*aux;

	linkar(b, criate_list((*a)->value));
	aux = (*a)->next;
	free(*a);
	*a = aux;
	write(1, "pb\n", 3);
}
