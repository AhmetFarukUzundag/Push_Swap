/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:45:44 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/17 08:21:12 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char delimiter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != delimiter)
		{
			count++;
			while (s[i] != '\0' && s[i] != delimiter)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	word_length(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*copy(char const *start, int length)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (length + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	free_all(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	length;
	char	**result;
	size_t	j;

	j = 0;
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			length = word_length(s, c);
			result[j] = copy(s, length);
			if (!result[j] && free_all(result, j))
				return (NULL);
			while (*s && *s != c)
				s++;
			j++;
		}
		else
			s++;
	}
	result[j] = NULL;
	return (result);
}
