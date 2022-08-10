/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:58:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/10 14:26:05 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print(char *message, t_philo *philo)
{
	if (pthread_mutex_lock(&philo->go_info->m_print)) // mutex
		return (RET_ERROR);
	printf("%s\n", message); // print
	if (pthread_mutex_unlock(&philo->go_info->m_print)) // unlock mutex
		return (RET_ERROR);
	return (OK);
}


