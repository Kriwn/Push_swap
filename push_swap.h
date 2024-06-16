/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:32:38 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/16 21:56:43 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct node
{
	int			value;
	struct node	*next;
	int			index;
}	t_stack;

typedef struct push_swap
{
	t_stack		*a;
	t_stack		*b;
	char		*ans;
	int			max_index;
	char		**temp;
}	t_push_swap;

//------------check.c--------------//
int	checkdigit(size_t i, char *str);
int		checkstr(char *str);
int		check(char **str);
int		is_duplicate(t_stack *stack);
int		is_sort(t_stack *stack);

//-------------free.c-------------//
void	ft_error(t_push_swap data);
void	cleardata(t_push_swap data);
void	free2d(char **str);
void	freelist(t_stack **node);

//------------ft_split.c-----------//
void	freeall(char ***ptr);
size_t	count(char const *s, char c);
int		makearray(char **ptr, char const *s, char c);
char	**ft_split(char const *s, char c);

//------------instruction1.c----------//
void	push(t_stack **from, t_stack **to, char *str);
void	swap(t_stack **node, char *str);
void	sswap(t_stack **a, t_stack **b);

//------------instruction2.c----------//
void	rotate(t_stack **node, char *str);
void	rrotate(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **node, char *str);
void	rreverse_rotate(t_stack **a, t_stack **b);

//------------list.c----------------//
int		add_node(t_stack **node, int value);
t_stack	*find_last(t_stack **stack);
t_stack	*find_before_last(t_stack **stack);
int		fill_a(t_stack **a, char **data);
int		list_count(t_stack *a);

// debug
void	print_list(t_stack *stack);
void	print_list_index(t_stack *stack);

//----------------pre sort.c-------------//
t_stack	*find_min_index(t_stack *a);
void	pre_sort(t_push_swap data);
void	find_two_min(t_push_swap **node);

//--------------radix.c----------------//
int		findmaxbit(t_push_swap *data);
void	radix(t_push_swap *data);

//----------------sort.c--------------//
void	sort(t_push_swap *data);
void	sort_two(t_stack **node, char *str);
void	sort_three(t_stack **node, char *str);
void	sort_four(t_push_swap *data);
void	sort_five(t_push_swap *data);

//---------------utils.c----------//
char	*ft_strjoin(char const *s1, char const *s2);
long	ft_atol(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

//------------ utils2.c ---------//
char	*loopjoin(char **argv, int argc);
void	ft_putstr(char *s);
#endif
