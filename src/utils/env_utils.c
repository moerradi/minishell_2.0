/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:09:08 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/05 20:49:35 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*dollar_found(char *out, char *exp)
{
	char	*eptr;
	char	*ret;

	eptr = expand_str(exp);
	ret = ft_strjoin(out, eptr);
	free(eptr);
	return (ret);
}

char	*handle_env(char *str)
{
	char	**strs;
	char	*tmp;
	char	*out;
	int		i;

	strs = ft_split(str, ' ');
	i = 0;
	out = NULL;
	tmp = NULL;
	while (strs[i])
	{
		if (ft_strchr(strs[i], '$'))
			tmp = dollar_found(out, strs[i++]);
		else
			tmp = ft_strjoin(out, strs[i++]);
		free(out);
		out = ft_strjoin(tmp, " ");
		free(tmp);
	}
	free_strs(strs);
	return (out);
}

char	*expand_str(char *str)
{
	char	**tokens;
	char	*out;
	char	*tmp;
	char	*eptr;
	int		i;

	tokens = adv_split(str, -32);
	out = NULL;
	tmp = NULL;
	i = 0;
	while (tokens[i])
	{
		if (ft_strchr(tokens[i], '$'))
		{
			eptr = expand(tokens[i++]);
			tmp = ft_strjoin(out, eptr);
			free(eptr);
		}
		else
			tmp = ft_strjoin(out, tokens[i++]);
		free(out);
		out = tmp;
	}
	free_strs(tokens);
	return (out);
}

char	*weirdstring(void)
{
	char	*ret;

	ret = (char *)malloc(23 * sizeof(char));
	ft_strlcpy(ret, "$\\'\"|~<>=-?", 12);
	ret[11] = '$' * -1;
	ret[12] = '\\' * -1;
	ret[13] = '\'' * -1;
	ret[14] = '"' * -1;
	ret[15] = '|' * -1;
	ret[16] = '~' * -1;
	ret[17] = '>' * -1;
	ret[18] = '<' * -1;
	ret[19] = '=' * -1;
	ret[20] = '-' * -1;
	ret[21] = '?' * -1;
	ret[22] = '\0';
	return (ret);
}

char	*expand(char *str)
{
	int		i;
	char	*out;
	char	**toks;
	char	*tmp;
	char	*delim;

	delim = weirdstring();
	toks = ft_strtok(str, delim);
	free(delim);
	tmp = NULL;
	out = NULL;
	i = 0;
	while (toks[i])
	{
		if (!ft_strcmp(toks[i], "$") && toks[i + 1] && toks[i + 1][0] > 0)
			tmp = ft_strjoin(out, ft_getenv(toks[++i]));
		else
			tmp = ft_strjoin(out, toks[i]);
		free(out);
		out = tmp;
		i++;
	}
	free_strs(toks);
	return (out);
}
