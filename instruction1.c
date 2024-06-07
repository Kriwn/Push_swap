/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:10:30 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/01 15:05:42 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pusha(t_stack **a,t_stack **b)
{
	t_stack *temp;
	t_stack *cur;

	cur = *b;
	temp  = cur->next;
	cur->next = (*a);
	if (*a == NULL)
		*a = cur;
	*b = temp;
	write(1,"pa\n",3);
}

void	pushb(t_stack **a,t_stack **b)
{
	t_stack *temp;
	t_stack *cur;

	cur = *a;
	temp  = cur->next;
	cur->next = (*b);
	if (*b == NULL)
		*b = cur;
	*a = temp;
	write(1,"pb\n",3);
}

void	swapa(t_stack **a)
{
	t_stack *temp;
	t_stack *cur;

	cur = *a;
	temp = cur->next;
	temp->next = cur;
	cur->next = temp->next;
	*a = temp;
	write(1,"sa\n",3);
}

void	swapb(t_stack **b)
{
	t_stack *temp;
	t_stack *cur;

	cur = *b;
	temp = cur->next;
	temp->next = cur;
	cur->next = temp->next;
	*b = temp;
	write(1,"sb\n",3);
}

void	sswap(t_stack **a,t_stack **b)
{
	swapa(a);
	swapb(b);
	write(1,"ss\n",1);
}
