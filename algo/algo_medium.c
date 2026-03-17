/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 08:22:06 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/17 16:21:38 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium_sort(t_stack **a, t_stack **b)
{
	
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