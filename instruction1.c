/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:10:30 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/16 13:40:42 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **from, t_stack **to, char *str)
{
	t_stack *temp;
	t_stack *cur;

	cur = *from;
	temp  = cur->next;
	*from = temp;
	cur->next = (*to);
	if (*to == NULL)
		*to = cur;
	else
	{
		temp = *to;
		*to = cur;
		cur->next = temp;
	}
	write(1,"p",1);
	write(1,str,2);
}

void	swap(t_stack **node,char *str)
{
	t_stack *temp;
	t_stack *cur;

	cur = *node;
	temp = cur->next;
	cur->next = temp->next;
	temp->next = cur;
	*node = temp;
	write(1,"s",1);
	write(1,str,2);
}

void	sswap(t_stack **a,t_stack **b)
{
	swap(a,"a\n");
	swap(b,"b\n");
	write(1,"ss\n",1);
}
