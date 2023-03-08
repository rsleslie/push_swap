/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:43:56 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/07 23:43:13 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	t_node	*aux_head;
	t_node	*aux;

	aux_head = (*a)->next;
	aux = (*a)->next->next;
	(*a)->next = aux;
	aux_head->next = *a;
	*a = aux_head;
    write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	t_node	*aux_head;
	t_node	*aux;

	aux_head = (*b)->next;
	aux = (*b)->next->next;
	(*b)->next = aux;
	aux_head->next = *b;
	*b = aux_head;
    write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
    write(1, "ss\n", 3);
}

void	ra(t_node **a)
{
	t_node	*aux;

	aux = *a;
	while (aux != NULL)
	{
		if (aux->next == NULL)
		{
			aux->next = *a;
			break ;
		}
		aux = aux->next;
	}
	*a = (*a)->next;
	aux->next->next = NULL;
    write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	t_node	*aux;

	aux = *b;
	while (aux != NULL)
	{
		if (aux->next == NULL)
		{
			aux->next = *b;
			break ;
		}
		aux = aux->next;
	}
	*b = (*b)->next;
	aux->next->next = NULL;
    write(1, "rb\n", 3);
}
