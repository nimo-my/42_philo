/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:18:43 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/04 17:31:58 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h> // gettimeofday
# include <unistd.h>
# include <stdio.h> // printf
# include <stdbool.h>

# define ERROR	1
# define OK		0

// typedef pthread_mutex_t p_mutex;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	// pthread_mutex_t	m_fork;


}	t_philo;


typedef struct s_info
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat; // if argv == 6 only


	int*				permit_fork; // default all 1
	pthread_t			*tid_arr; // 나중에 스레드 만들면서 넣어줄 것임! 
	pthread_mutex_t		*mutex_arr;

}	t_info;


#endif
