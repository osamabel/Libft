/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:27:26 by obelkhad          #+#    #+#             */
/*   Updated: 2021/11/16 14:22:59 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *s, char c)
{
	int	start;
	int	n;

	start = 0;
	n = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			n++;
			while (s[start] != c && s[start])
				start++;
		}
		else
			start++;
	}
	return (n);
}

static int	free_splitted(char	**splitted, size_t wc)
{
	if (!splitted[wc])
	{
		while (wc >= 0)
			free(splitted[wc--]);
		free (splitted);
		return (1);
	}
	return (0);
}

static char	**ft_trim_to_split(char *trimmed, char **splitted, char c)
{
	size_t	start;
	size_t	end;
	size_t	wc;

	start = 0;
	end = 0;
	wc = 0;
	while (trimmed[start])
	{
		if (trimmed[start] != c)
		{
			while (trimmed[end] != c && trimmed[end])
				end++;
			splitted[wc] = (char *)malloc((end - start + 1) * sizeof(char));
			if (free_splitted(splitted, wc))
				return (0);
			ft_strlcpy(splitted[wc++], trimmed + start, end - start + 1);
		}
		start = end + 1;
		end = start;
	}
	splitted[wc] = 0;
	free(trimmed);
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	char	*trimmed;

	if (!s)
		return (0);
	trimmed = ft_strtrim(s, &c);
	if (!trimmed)
		return (0);
	splitted = (char **)malloc((ft_wordcount(trimmed, c) + 1) * sizeof(char *));
	if (!splitted)
		return (0);
	return (ft_trim_to_split(trimmed, splitted, c));
}
