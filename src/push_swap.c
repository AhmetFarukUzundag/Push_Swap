/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:59:16 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/22 15:48:38 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void selected_strategy(t_stack *a)
// {

// }

static int	run_push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc < 2)
		return (0);
	if (!parser_arguments(argc, argv, &a))
		return (0);   // hata durumunda 0 return eder
	if (is_sorted(a)) // stack sıralıysa programı sonlandırır
		return (free_stack(&a), 0);
	normalize(a);
	// if (compute_disorder(a))
	simple_sort(&a, &b);
	// burada a üzerinde algoritmalar çalışacak
	free_stack(&a); // başarılı parse sonrası free
	return (0);
}

int	main(int argc, char **argv)
{
	return (run_push_swap(argc, argv));
}
