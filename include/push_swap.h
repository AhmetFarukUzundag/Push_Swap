#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

t_stack			*new_node(int data);

void			add_stack_back(t_stack **lst, t_stack *new);
void			free_stack(t_stack **stack);

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
long				ft_atol(const char *str, int *error);
int					parser_arguments(int argc, char **argv, t_stack **a);

#endif