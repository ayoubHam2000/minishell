/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:22:52 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/01 18:22:11 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_queue	*parse_command(char *str)
{
	t_queue	*res;
	char	*format_str;

	format_str = expansion(str);
	if (!check_sysntax(format_str))
		printf("Syntax Error\n");
	else
		printf("%s\n", format_str);
	res = get_structur(format_str);
	free(format_str);
	return (res);
}
