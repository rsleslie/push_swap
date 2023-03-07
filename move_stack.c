/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:43:56 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/07 18:09:04 by rleslie-         ###   ########.fr       */
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

void	rr(t_node **a, t_node **b)
{
	rb(b);
	ra(a);
    write(1, "rr\n", 3);
}

void	rra(t_node **a)
{
	t_node	*aux;
    t_node  *aux_aux;

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

void	rrb(t_node **b)
{
	t_node	*aux;

	aux = *b;
	while (aux != NULL)
	{
		if (aux->next == NULL)
		{
			aux->next = *b;
			aux->next->next = (*b)->next;
			break ;
		}
		aux = aux->next;
	}
	*b = (*b)->next->next;
	aux->next->next->next = NULL;
    write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
    write(1, "rrr\n", 4);
}

void	pa(t_node **a, t_node **b)
{
	linkar(a, criate_list(ft_itoa((*b)->value)));
	*b = (*b)->next;
    write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	linkar(b, criate_list(ft_itoa((*a)->value)));
	*a = (*a)->next;
    write(1, "pb\n", 3);
}