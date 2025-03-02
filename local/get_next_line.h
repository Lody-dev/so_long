/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsarmien <dsarmien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:32:51 by dsarmien          #+#    #+#             */
/*   Updated: 2024/12/04 13:30:20 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* PRE-PROCESSOR RULES */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* INCLUDES */

# include <stdlib.h> // for size_t, malloc() and free() usage
# include <unistd.h> // for read() and ssize_t usage
# include <stdio.h> // for printft
/* DEFINES */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD __FD_SETSIZE
# endif

/* PROTOTYPES */

/**
 * @brief Reads a line from the given file descriptor.
 * @param fd The file descriptor from were to read.
 * @return A string which is the line readed. In case of fail or reading ends,
	returns NULL.
 */
char	*get_next_line(int fd);

/* ADDITIONAL PROTOTYPES */

/**
 * @brief Calculate the length of the given string.
 * @param s The string to calculate the length of.
 * @return The length of the string 's'.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Searches for the first occurrence of character 'c' in the string 's'.
 * @param s The string to search in.
 * @param c The character to search for.
 * @return Pointer to the located character in the string 's'.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Copies 'n' bytes from memory area 'src' to memory area 'dest'.
 *
 *        The memory areas must not overlap:
 *        use ft_memmove() if the memory areas do overlap.
 * @param dest The destination memory block to be copied in.
 * @param src The source memory block.
 * @param n The number of bytes to copy.
 * @return Pointer to 'dest'.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Allocates memory and returns a new string,
 *        resulting from the concatenation of string 's2' to 's1'.
 * @param s1 The first string.
 * @param s2 The string to be added to 's1'.
 * @return The new string or NULL if the memory allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Free allocated memory and set it to NULL.
 * @param ptr The pointer to be freed.
 * @return Pointer to the string.
 */
char	*ft_memclean(char *ptr);

#endif
