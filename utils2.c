/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:07:44 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/16 17:01:43 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*loopjoin(char **argv, int argc)
{
	int		i;
	char	*ans;
	char	*temp;
	char	*temp_space;

	ans = malloc(sizeof(char) * 1);
	ans[0] = '\0';
	i = 1;
	temp = NULL;
	while (i < argc)
	{
		temp_space = ft_strjoin(argv[i], " ");
		temp = ans;
		ans = ft_strjoin(ans, temp_space);
		if (!temp_space || !ans)
			return (NULL);
		free(temp);
		free(temp_space);
		i++;
	}
	return (ans);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}
