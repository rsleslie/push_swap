/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:43:00 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/08 14:47:26 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '-')
		    i++;
		if (ft_isdigit(str[i]))
        {
            write(1, "Error\n", 7);
			return (0);
        }
		i++;
	}
	return (1);
}

int	check_error(t_node **list)
{
	if (duplicated(list) == 0)
    {
        write(1, "Error\n", 7);
		return (0);
    }
    if (order(list) == 0)
    {
        write(1, "Error\n", 7);
		return (0);
    }
	return (1);
}

int order(t_node **list)
{
	t_node *aux;
	int		i;

	i = 0;
	aux = *list;
    int size_list = 0;
	while (aux->next != NULL)
	{
		if (aux->value < aux->next->value)
		    i += 1;	
		aux = aux->next;
        size_list++;
	}
	if (i == size_list)
		return (0);
	else
		return (1);
}

int	duplicated(t_node **list)
{
	t_node *aux;
	t_node *aux_aux;

	aux = *list;
	while(aux != NULL)
	{
		aux_aux = aux->next;
		while (aux_aux != NULL)
		{
			if (aux_aux->value == aux->value)
				return (0);
			aux_aux = aux_aux->next;
		}
		aux = aux->next;
	}
	return (1);
}
