/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:57:29 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/26 16:40:18 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}					t_strategy;

typedef struct s_config
{
	t_strategy		strategy;
	int				bench_enabled;
	double			disorder;
	int				size;
	int				chunk_size;
}					t_config;

typedef struct s_bench
{
	size_t			total;
	size_t			sa;
	size_t			sb;
	size_t			ss;
	size_t			pa;
	size_t			pb;
	size_t			ra;
	size_t			rb;
	size_t			rr;
	size_t			rra;
	size_t			rrb;
	size_t			rrr;
}					t_bench;

t_stack				*new_node(int data);

void				add_stack_back(t_stack **lst, t_stack *new);
void				free_stack(t_stack **stack);
void				sa(t_stack **a, t_bench *bench, t_config *cfg);
void				sb(t_stack **b, t_bench *bench, t_config *cfg);
void				ss(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg);
void				pa(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg);
void				pb(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg);
void				ra(t_stack **a, t_bench *bench, t_config *cfg);
void				rb(t_stack **b, t_bench *bench, t_config *cfg);
void				rr(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg);
void				rra(t_stack **a, t_bench *bench, t_config *cfg);
void				rrb(t_stack **b, t_bench *bench, t_config *cfg);
void				rrr(t_stack **a, t_stack **b, t_bench *bench,
						t_config *cfg);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					is_sorted(t_stack *a);
char				**ft_split(char const *s, char c);
long				ft_atol(const char *str, int *error);
int					parser_arguments(int argc, char **argv, t_stack **a);
int					stack_size(t_stack *a);
double				compute_disorder(t_stack *a);
void				index_compression(t_stack **a, int size);
int					parse_flags(int argc, char **argv, t_config *cfg,
						int *first_num_idx);
void				putstr(char *s);
void				putnbr(long n);
void				putendl(char *s);
void				bench_init(t_bench *b);
void				put_percent(double d);

void				simple_sort(t_stack **a, t_stack **b, t_bench *bench,
						t_config *cfg);
void				sort_two(t_stack **a, t_bench *bench, t_config *cfg);
void				sort_three(t_stack **a, t_bench *bench, t_config *cfg);
void				medium_sort(t_stack **a, t_stack **b, t_bench *bench,
						t_config *cfg);
void				radix_sort(t_stack **a, t_stack **b, t_bench *bench,
						t_config *cfg);
void				normalize(t_stack *a);
void				adaptive_sort(t_stack **a, t_stack **b, t_config *cfg,
						t_bench *bench);
void				bench_print(t_config *cfg, t_bench *b);

void				push_back_to_a(t_stack **a, t_stack **b, t_bench *bench,
						t_config *cfg);

int					find_max_position(t_stack *stack);
void				min_to_top(t_stack **a, t_bench *bench, t_config *cfg);
int					min_position(t_stack *a);
void				sort_five(t_stack **a, t_stack **b, t_bench *bench,
						t_config *cfg);

#endif
