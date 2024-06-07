/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:43:17 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/07 21:54:40 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkdigit(size_t i,char *str)
{
	int	count;

	// printf("Check digit\n");
	count = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			count++;
		}
		else
			return (0);
	}
	if (count > 10)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (!str[i] && (count > 0))
		return (1);
	else
		return (0);

}

int	checkstr(char *str)
{
	size_t	i;
	int		len;

	// printf("Check Str [%s]\n",str);git
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
			i++;
	}
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (checkdigit(i, str) == 0)
		return (0);
	return(1);
}

int check(char **str)
{
	size_t i;

	i = 0;
	// printf("Check\n");
	while (str[i])
	{
		if (checkstr(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *stack)
{
	t_stack *temp;
	int		value;

	while (stack)
	{
		value = stack->value;
		// printf("value is %d\n",value);
		temp = stack->next;
		while (temp)
		{
			// printf("temp is %d\n",temp->value);
			if (value == temp->value)
				return (0);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	is_sort(t_stack *stack)
{
	int	value;

	value = stack->value;
	stack = stack->next;

	while (stack)
	{
		if (value > stack->value)
			return (0);
		stack = stack->next;
		value = stack->value;
	}
	return (1);
}
