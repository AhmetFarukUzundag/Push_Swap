/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_compression.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:20:50 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/24 13:53:26 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	index_compression(t_stack **a)
{
	t_stack	*curr;
	int		buf[stack_size(*a)];
	int		i;
	int		size;

	size = stack_size(*a);
	curr = *a;
	i = 0;
	while (curr)
	{
		buf[i++] = curr->data;
		curr = curr->next;
	}
	bubble_sort(buf, size);
	curr = *a;
	while (curr)
	{
		curr->index = find_index(buf, size, curr->data);
		curr = curr->next;
	}
}
