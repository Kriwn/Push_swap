/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:32:38 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/07 13:31:00 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct node
{
	int			value;
	struct node	*next;
	int			index;
}t_stack;

typedef struct push_swap
{
	t_stack		*a;
	t_stack		*b;
	char *ans;
	char **temp;
}t_push_swap;


//------------check.c--------------//
int	checkdigit(size_t i,char *str);
int	checkstr(char *str);
int check(char **str);
int	is_duplicate(t_stack *stack);
int	is_sort(t_stack *stack);


//-------------free.c-------------//
void	ft_error(t_push_swap data);
void	cleardata(t_push_swap data);
void	free2d(char **str);
void	freelist(t_stack **node);

//------------ft_split.c-----------//
void	freeall(char ***ptr);
size_t	count(char const *s, char c);
int	makearray(char **ptr, char const *s, char c);
char	**ft_split(char const *s, char c);

//------------instruction1.c----------//
void	pusha(t_stack **a,t_stack **b);
void	pushb(t_stack **a,t_stack **b);
void	swapa(t_stack **a);
void	swapb(t_stack **b);
void	sswap(t_stack **a,t_stack **b);

//------------instruction2.c----------//
void rotatea(t_stack **a);
void rotateb(t_stack **b);
void rrotate(t_stack **a,t_stack **b);

//------------instruction3.c----------//
void	reverse_rotatea(t_stack **a);
void	reverse_rotateb(t_stack **b);
void	rreverse_rotate(t_stack **a,t_stack **b);

//------------list.c----------------//
void	add_node(t_stack **node, int value);
t_stack	*find_last(t_stack **stack);
t_stack	*find_before_last(t_stack **stack);
int	fill_a(t_stack **a,char **data);
void	print_list(t_stack *stack);

//---------------utils.c----------//
char	*ft_strjoin(char const *s1, char const *s2);
long	ft_atol(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);



//------------ utils2.c ---------//
char *loopjoin(char **argv, int argc);
void	ft_putstr(char *s);
#endif
