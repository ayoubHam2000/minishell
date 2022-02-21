/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:37:14 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/20 20:00:18 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	char *str;
	//< << > >>
	printf("%d\n", getpid());
	while (1)
	{
		str = readline("minishell$ ");
		if (str)
		{
			if (str[0] == 'a')
			{
				free(str);
				while (1)
				{
					str = readline("");	
				}
			}
			add_history(str);
			free(str);			
		}
	}
	return (0);
}
