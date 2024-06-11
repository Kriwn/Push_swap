/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:54:20 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/12 01:43:27 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **node,char *str)
{
	t_stack	*cur;
	t_stack	*temp;
	t_stack *last;

	last = find_last(node);
	cur = *node;
	temp = cur->next;
	cur->next = NULL;
	last->next = cur;
	*node = temp;
	write(1,"r",1);
	write(1,str,2);
}

void rrotate(t_stack **a,t_stack **b)
{
	rotate(a,"a\n");
	rotate(b,"b\n");
	write(1,"rr\n",3);
}

void	reverse_rotate(t_stack **node, char *str)
{
	t_stack	*beforelast;
	t_stack	*temp;
	t_stack	*cur;

	cur = *node;
	beforelast = find_before_last(node);
	temp = beforelast->next;
	temp->next = cur;
	beforelast->next = NULL;
	*node = temp;
	write(1,"rr",2);
	write(1,str,2);
}

void	rreverse_rotate(t_stack **a,t_stack **b)
{
	reverse_rotate(a, "a\n");
	reverse_rotate(b, "b\n");
	write(1,"rrr\n",4);
}
