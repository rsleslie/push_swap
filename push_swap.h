/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:05:51 by rleslie-          #+#    #+#             */
/*   Updated: 2023/03/08 14:37:36 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct t_no
{
	int			value;
	struct t_no	*next;	
}t_node;

t_node	*criate_list(char *num);
void	linkar(t_node **list, t_node *atual);
int		check(char *str);
void	link_end(t_node **lista, t_node *atual);
t_node	*node_last(t_node *lista);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
int		duplicated(t_node **list);
int     order(t_node **list);
int     check_error(t_node **list);
size_t	push_strlen(t_node *p);
int     position_list(t_node **list);
void	order_three(t_node **list);
void    moves_five(t_node **list, t_node **b, int i);
void    moves_four(t_node **a, t_node **b, int i);
void    order_five(t_node **a, t_node **b);
void    order_four(t_node **a, t_node **b);
int     position_max(t_node **list);
int     size_binary(int max);
t_node  *new_index(t_node **a);
void	radix(t_node **a, t_node **b);

#endif