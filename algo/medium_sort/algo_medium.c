/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 08:22:06 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/18 10:30:16 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium_sort(t_stack **a, t_stack **b)
{
	int	size;

	index_compression(a);
	// chunk
	size = stack_size(*a);
	if (size < 100)
		pause; // 5 chunk
	else if (size < 500)
		pause; // 11 chunk
}

// 0..n-1 indexler
// ↓
// √n chunk
// ↓
// A → B push
// ↓
// B → A geri toplama

// index compression
// ↓
// chunk_size belirle
// ↓
// chunk_range oluştur
// ↓
// while A boş değil
//     if index chunk içindeyse
//         pb
//         gerekiyorsa rb
//     else
//         ra
// ↓
// while B boş değil
//     max bul
//     rotate ile top'a getir
//     pa

// pratikte oluşturulması gereken tahmini chunk miktarı: (karekök olmayacak)
// n ≤ 100 → 5 chunk
// n ≤ 500 → 11 chunk