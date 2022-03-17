/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakkach <yhakkach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:48:48 by yhakkach          #+#    #+#             */
/*   Updated: 2022/03/17 22:09:47 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_valid_identifier1(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		printf("export: `%s': not a valid identifier \n", str);
		return (0);
	}
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			printf("export: `%s': not a valid identifier \n", str);
			return (0);
		}
		i++;
	}
	return (1);
}


int		is_here(char	*str,char	**envp)
{
	int		i;

	i = 0;

	while (str[i])
	{
		if (!strncmp(envp[i], str, ft_strlen(str)))
			return (-1);		
		i++;
	}
	return (1);
}



int	ft_unset(char **args)
{
	int		i;
	int		j;
	char	**unse;
	int 	ii;
	char	**envp;

	ii = 0;
	i = 0;
	j = 0; 
	envp = env_var(NULL);
	unse = malloc(sizeof(char *) * (ft_arrlen((void **)envp)));
	if (!unse)
		ft_error_exit(ERR_MALLOC);
	while (envp[i])
	{
		j = 0;
		while (args[j])
		{
			if (!strncmp(envp[i], args[j], ft_strlen(args[j])))
				break ;
			j++;
		}
		if (j == ft_arrlen((void **)args))
		{
			unse[ii] = envp[i];
			ii++;
		}
		i++;
	}
	unse[ii] = NULL;
	env_var(unse);
	return (0);
}
