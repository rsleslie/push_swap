/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:39:39 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/08 14:45:43 by rleslie-         ###   ########.fr       */
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
			return (0);
		link_end(&a, criate_list(argv[i]));
		i++;
	}
	if (check_error(&a) == 0)
		return(0);
	if(push_strlen(a) == 3)
		order_three(&a);
	if(push_strlen(a) == 4)
		order_four(&a, &b);
	if(push_strlen(a) == 5)
		order_five(&a, &b);
    if (push_strlen(a) > 5)
		radix(&a, &b);
	return (0);
}
