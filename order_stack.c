/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:21:54 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/08 14:39:38 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	order_three(t_node **list)
{
	int	i;
	
	i = position_list(list);
	if(i == 0)
		ra(list);
	else if (i == 1)
		rra(list);
	if((*list)->value > (*list)->next->value)
		sa(list);
}

void	moves_five(t_node **list, t_node **b, int i)
{
	if(i == 0)
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

void moves_four(t_node **a, t_node **b, int i)
{
	if(i == 0)
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

int position_list(t_node **list)
{
	t_node *aux;
	t_node *aux_max;
	int i = 0;
	
	aux = (*list)->next;
	aux_max = *list;
	while(aux)
	{
		if(aux_max->value < aux->value)
			aux_max = aux;
		aux = aux->next;
	}
	aux = *list;
	while (aux)
	{
		if(aux->value == aux_max->value)
			break;
		i++;
		aux = aux->next;	
	}
	printf("aux: %i, aux_max: %i numero i : %i", aux->value, aux_max->value, i);
	return (i);
	
}

int position_max(t_node **list)
{
	t_node *aux;
	t_node *aux_max;
	int i = 0;
	int max;
    
	aux = (*list)->next;
	aux_max = *list;
	while(aux)
	{
		if(aux_max->value < aux->value)
			aux_max = aux;
		aux = aux->next;
	}
	aux = *list;
	while (aux)
	{
		if(aux->value == aux_max->value)
			break;
		i++;
		aux = aux->next;	
	}
    max = aux->value;
	return (max);
	
}

void order_five(t_node **a, t_node **b)
{
	moves_five(a, b, position_list(a));
	moves_four(a, b, position_list(a));
	order_three(a);
	if((*b)->value > (*b)->next->value)
		sb(b);
	pa(a, b);
	ra(a);
	pa(a, b);
	ra(a);
}

void order_four(t_node **a, t_node **b)
{
	moves_four(a, b, position_list(a));
	order_three(a);
	pa(a, b);
	ra(a);
}
