/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:39:39 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/08 19:20:54 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

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

void	sort(t_node **a, t_node **b, int argc)
{
	if (push_strlen(*a) <= 3 && push_strlen(*a) > 1)
		order_three(a);
	else if (push_strlen(*a) == 4)
		order_four(a, b);
	else if (push_strlen(*a) == 5)
		order_five(a, b);
	else
		radix(a, b, argc - 1);
}

void ft_free(t_node *list)
{
    if (list)
    {
        ft_free(list->next);
        free(list);
    }   
}

int	main(int argc, char **argv)
{
	int		i;
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
			return (0);
		link_end(&a, criate_list(argv[i++]));
	}
	if (check_error(&a) == 0)
		return (0);
	sort(&a, &b, argc);
    ft_free(a);
    ft_free(b);
	return (0);
}
