/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:51:28 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/23 00:25:39 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			return ((char *)s + count);
		count++;
	}
	if (s[count] == (char)c)
		return ((char *)s + count);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*res_ptr;

	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	res_ptr = result;
	while (*s1 != '\0')
		*(res_ptr++) = *(s1++);
	while (*s2 != '\0')
		*(res_ptr++) = *(s2++);
	if (*s2 == '\0')
		*res_ptr = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return ("");
	if (start + len > s_len)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memmove(sub, s + start, len + 1);
	sub[len] = '\0';
	return (sub);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	const unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (const unsigned char *)src;
	if (dst2 < src2)
	{
		while (len > 0)
		{
			*dst2++ = *src2++;
			len--;
		}
	}
	else if (dst2 > src2)
	{
		dst2 += len - 1;
		src2 += len - 1;
		while (len > 0)
		{
			*dst2-- = *src2--;
			len--;
		}
	}
	return (dst);
}
