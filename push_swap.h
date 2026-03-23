#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	int				index;
}					t_stack;

typedef enum e_strategy
{
    STRAT_ADAPTIVE,
    STRAT_SIMPLE,
    STRAT_MEDIUM,
    STRAT_COMPLEX
}	t_strategy;

typedef struct s_config
{
    t_strategy	strategy;
    int			bench_enabled;
    double		disorder;     
}	t_config;


t_stack				*new_node(int data);

void				add_stack_back(t_stack **lst, t_stack *new);
void				free_stack(t_stack **stack);
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

int	                ft_strncmp(const char *s1, const char *s2, size_t n);
int					is_sorted(t_stack *a);
char				**ft_split(char const *s, char c);
long				ft_atol(const char *str, int *error);
int					parser_arguments(int argc, char **argv, t_stack **a);
int					stack_size(t_stack *a);
double				compute_disorder(t_stack *a);
void				index_compression(t_stack **a);
int	                parse_flags(int argc, char **argv, t_config *cfg, int *first_num_idx);

// algoritmalar
void				simple_sort(t_stack **a, t_stack **b);
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				medium_sort(t_stack **a, t_stack **b);
void				radix_sort(t_stack **a, t_stack **b);
void 				normalize(t_stack *a);
void                adaptive_sort(t_stack *a, t_stack *b, t_config *cfg);

#endif