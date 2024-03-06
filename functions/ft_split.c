/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:53:18 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/03 20:08:41 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	count_strings(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static int	ft_strlen_sep(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*ft_word(char const *str, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (word == NULL)
		return (NULL);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *) * (count_strings(str, c) + 1));
	if (strings == NULL)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			strings[i++] = ft_word(str, c);
		while (*str && *str != c)
			str++;
	}
	strings[i] = NULL;
	return (strings);
}

/* int main(void)
{
	char **strs;
	char str[] = "::::12345:67890q:wertyui:opasdf:ghjkl:: ::32423";
	strs = ft_split(str, ':');
	while (*strs)
	{
		printf("%s\n", *strs);
		strs++;
	}
} */
