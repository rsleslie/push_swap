/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:39:39 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/07 18:32:49 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void	imprimir(t_node *p)
{
	while (p != NULL)
	{
		ft_printf("%i",p->value);
		p = p->next;
	}
	write(1, "\n", 2);
}

size_t	push_strlen(t_node *p)
{
	int	i;

	i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void	moves_three(t_node **list)
{
	t_node	*aux;
	t_node	*aux_aux;

	while(1)
	{
		aux = *list;
		aux_aux = (*list)->next;
		if (aux->value > aux_aux->value)
			sa(list);
		else
			rra(list);
		if(order(list) == 0)
			return ;
	}
}

void four_five(t_node **list)
{
	t_node *aux;
	t_node *aux_aux;
	
	aux = *list;
	aux_aux = (*list)->next;
	if(aux->value > aux_aux->value)
	{
		if(aux->value < aux_aux->next->value)
			sa(list);
		else
		{
			rra(list);
			if(aux->value > aux->next->value)
				sa(list);
			ra(list);
			ra(list);		
		}
	}	
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		if (check(argv[i]) == 0)
			return (write(1, "Error!\n", 8));
		link_end(&a, criate_list(argv[i]));
		i++;
	}
	if (check_error(&a) == 0)
		return(0);
	if (push_strlen(a) == 3)
		moves_three(&a);
	if (push_strlen(a) == 4)
	{
		pb(&a, &b);	
		moves_three(&a);
		pa(&a, &b);
		four_five(&a);
	}
	if (push_strlen(a) == 5)
	{
		pb(&a, &b);
		pb(&a, &b);	
		moves_three(&a);
		pa(&a, &b);
		four_five(&a);
		pa(&a, &b);
		if(a->value > a->next->value)
		{
			sa(&a);
			pb(&a, &b);
			four_five(&a);
			pa(&a, &b);
		}
	}
	imprimir(a);
	imprimir(b);
	return (0);
}
