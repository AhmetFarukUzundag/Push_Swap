/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:59:16 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/17 08:21:24 by auzundag         ###   ########.fr       */
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
	// if (compute_disorder(a))
	simple_sort(&a, &b);
	// medium_sort(&a, &b);
	// burada a üzerinde algoritmalar çalışacak
	free_stack(&a); // başarılı parse sonrası free
	return (0);
}

int	main(int argc, char **argv)
{
	return (run_push_swap(argc, argv));
}

// argc = 4

// argv[0] = "./push_swap"
// argv[1] = "3"
// argv[2] = "2"
// argv[3] = "1"

// Edge Caseler

// boş input
// ./push_swap ""
// sadece boşluk
// ./push_swap "     "
// invalid karakter
// ./push_swap 1 2 a
// mixed
// ./push_swap 1 "2 a"
// duplicate
// ./push_swap 1 2 2
// int overflow
// ./push_swap 999999999999999
// sign hatası
// ./push_swap --
// ./push_swap +-

// push_swap programı. Programınız çalışma zamanında bir strateji seçebilmelidir
// Giriş yapılandırması üzerinde

// main
//  ↓
// parse_args
//  ↓
// argv[i]
//  ↓
// split
//  ↓
// tokens[j]
//  ↓
// validate_number
//  ↓
// ft_atol
//  ↓
// check_duplicate
//  ↓
// stack_add_back
