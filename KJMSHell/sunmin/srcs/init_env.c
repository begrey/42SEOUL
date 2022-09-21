/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:28:21 by sunmin            #+#    #+#             */
/*   Updated: 2021/05/29 12:49:26 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_env(char *envp[], t_env *env)
{
	int		i;
	int		len;

	i = 0;
	while (envp[i])
	{
		i++;
	}
	len = i;

	i = 0;
	while (i < len)
	{
		ft_envadd_back(&env, ft_envnew(find_key(envp[i]), find_value(envp[i]), 1));
		i++;
	}
	return (env);
	// 종료 상태 추가
//	temp[i].key = ft_strdup("?");
//	temp[i].value = ft_strdup("0");
//	temp[i].if_value = 0;
//	ft_envadd_back(&env, &temp[i]);
}

