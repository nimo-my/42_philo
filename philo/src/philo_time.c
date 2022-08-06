/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:42:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/07 01:12:42 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	set_time(struct timeval time)
{
	if (gettimeofday(&time, NULL))
		return (RET_ERROR);
	
	return (time.tv_sec);
}