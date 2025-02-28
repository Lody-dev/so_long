/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsarmien <dsarmien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:37:01 by dsarmien          #+#    #+#             */
/*   Updated: 2024/10/17 14:15:34 by dsarmien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlibft.h"

/**
 * @brief Computes the index of the next delimiter.
 * @param str String where search.
 * @param c Delimiter character.
 * @param i Index of the actual iteration.
 * @return Index to the next delimiter.
 */
static int	next_delimiter(const char *str, char c, int i)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

/**
 * @brief Computes the index of the next word.
 * @param str String where search.
 * @param c Delimiter character.
 * @param i Index of the actual iteration.
 * @return Index to the next word.
 */
static int	next_word(const char *str, char c, int i)
{
	while (str[i] && str[i] == c)
		i++;
	return (i);
}

/**
 * @brief Counts the number of words in a string.
 * @param str String to be counted.
 * @param c Delimiter character.
 * @return Number of total words.
 */
static int	count_words(const char *str, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			words++;
			i = next_delimiter(str, c, i);
		}
		else
			i++;
	}
	return (words);
}

/**
 * @brief Frees the memory of an array of strings.
 * @param str Array of strings to be freed.
 * @return None.
 */
static void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/*
First, the function count the number of words in the string.
Then, it allocates memory for the array of strings.
Then, it allocates memory for each string and copies it.
Finally, it returns the array of strings.

If the array of strings cannot be allocated, the function returns NULL.
If any of the strings cannot be allocated, the function frees the memory
of the array of strings and returns NULL.
*/

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		i;
	int		j;

	words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		i = next_word(s, c, i);
		split[j] = ft_substr(s, i, next_delimiter(s, c, i) - i);
		if (!split[j])
		{
			free_split(split);
			return (NULL);
		}
		i = next_delimiter(s, c, i);
		j++;
	}
	split[j] = NULL;
	return (split);
}
