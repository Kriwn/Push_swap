/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:54:20 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/07 13:39:37 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotatea(t_stack **a)
{
	t_stack	*cur;
	t_stack	*temp;
	t_stack *last;

	last = find_last(a);
	cur = *a;
	temp = cur->next;
	cur->next = NULL;
	last->next = cur;
	*a = temp;
	write(1,"ra\n",3);
}

void rotateb(t_stack **b)
{
	t_stack	*cur;
	t_stack	*temp;
	t_stack *last;

	last = find_last(b);
	temp = cur->next;
	cur->next = NULL;
	last->next = cur;
	*b = temp;
	write(1,"rb\n",3);
}

void rrotate(t_stack **a,t_stack **b)
{
	rotatea(a);
	rotateb(b);
	write(1,"rr\n",3);
}
