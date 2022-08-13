/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:34:46 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/14 04:29:23 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_run(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if ((p->id) % 2 != 0)
		usleep(200);
	while (1)
	{
		grab_fork(p);
		philo_eat();
		put_down_fork(p);
		philo_sleep();
		// philo_think();
		// exception();
	}
	return (NULL);
}

		grab_fork(p);


		philo_eat();


		put_down_fork(p);


		philo_sleep();
