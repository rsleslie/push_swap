/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:19:35 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/08 14:39:54 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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
