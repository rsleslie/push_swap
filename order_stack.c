/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:21:54 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/08 15:39:36 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_three(t_node **list)
{
	int	i;

	i = position_list(list);
	if (i == 0)
		ra(list);
	else if (i == 1)
		rra(list);
	if ((*list)->value > (*list)->next->value)
		sa(list);
}

void	moves_five(t_node **list, t_node **b, int i)
{
	if (i == 0)
		pb(list, b);
	else if (i == 1)
	{
		sa(list);
		pb(list, b);
	}
	else if (i == 2)
	{
		ra(list);
		ra(list);
		pb(list, b);
	}
	else if (i == 3)
	{
		rra(list);
		rra(list);
		pb(list, b);
	}
	else if (i == 4)
	{
		rra(list);
		pb(list, b);
	}
}

void	moves_four(t_node **a, t_node **b, int i)
{
	if (i == 0)
		pb(a, b);
	else if (i == 1)
	{
		sa(a);
		pb(a, b);
	}
	else if (i == 2)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if (i == 3)
	{
		rra(a);
		pb(a, b);
	}
}

void	order_five(t_node **a, t_node **b)
{
	moves_five(a, b, position_list(a));
	moves_four(a, b, position_list(a));
	order_three(a);
	if ((*b)->value > (*b)->next->value)
		sb(b);
	pa(a, b);
	ra(a);
	pa(a, b);
	ra(a);
}

void	order_four(t_node **a, t_node **b)
{
	moves_four(a, b, position_list(a));
	order_three(a);
	pa(a, b);
	ra(a);
}
