/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:18:43 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/02 21:28:17 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

struct s_philo
{
	size_t	philo_id;
	size_t	time_die;
	size_t	time_eat;
	size_t	time_sleep;
	size_t	num_of_time_must_eat;
	size_t	left_fork_num;
	size_t	right_fork_num;



}	t_philo;

struct s_info
{
	size_t	num_philo;

}	t_info;

#endif
