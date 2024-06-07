/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:54:18 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/07 13:40:20 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotatea(t_stack **a)
{
	t_stack	*beforelast;
	t_stack	*temp;
	t_stack	*cur;

	cur = *a;
	beforelast = find_before_last(a);
	temp = beforelast->next;
	temp->next = cur;
	beforelast->next = NULL;
	*a = temp;
	write(1,"rra\n",4);
}

void	reverse_rotateb(t_stack **b)
{
	t_stack	*beforelast;
	t_stack	*temp;
	t_stack	*cur;

	cur = *b;
	beforelast = find_before_last(b);
	temp = beforelast->next;
	temp->next = cur;
	beforelast->next = NULL;
	*b = temp;
	write(1,"rrb\n",4);
}

void	rreverse_rotate(t_stack **a,t_stack **b)
{
	reverse_rotatea(a);
	reverse_rotateb(b);
	write(1,"rrr\n",4);
}
