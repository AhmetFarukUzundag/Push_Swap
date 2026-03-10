#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b, int print_on);
void				pb(t_stack **a, t_stack **b, int print_on);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
int					is_sorted(t_stack *a);
char				**ft_split(char const *s, char c);

#endif