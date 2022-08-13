/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:58:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/12 15:50:57 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print(char *message, t_philo *philo)
{
	if (pthread_mutex_lock(&philo->info->m_print)) // mutex
		return (RET_ERROR);
	printf("%s\n", message); // print
	if (pthread_mutex_unlock(&philo->info->m_print)) // unlock mutex
		return (RET_ERROR);
	return (OK);
}


