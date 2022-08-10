/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:00:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/10 10:19:58 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	pick_fork(t_philo *this_philo, int fork_position)
{
	int	fork_id;

	fork_id = fork_position;
	if (pthread_mutex_lock(&(this_philo->go_info->m_fork_arr[fork_id])))
		return (RET_ERROR);
	else
	{
		if (!pthread_mutex_lock(&(this_philo->go_info->m_print)))
		{
			printf("[%d] has taken a fork \n", this_philo->id);
			if (pthread_mutex_unlock(&(this_philo->go_info->m_print)))
				return (RET_ERROR);
		}
	}
	return (OK);
}

// int	pick_left_fork(t_philo *this_philo)
// {
// 	int	fork_id;

// 	fork_id = this_philo->left_fork;
// 	if (pthread_mutex_lock(&(this_philo->go_info->m_fork_arr[fork_id])))
// 	{
// 		return (RET_ERROR);
// 	}
// 	else
// 	{
// 		//printf("[%d] get left fork \n", this_philo->id);
// 	}
// 	// printf("left\n");
// 	return (OK);
// }

// int	pick_right_fork(t_philo *this_philo)
// {
// 	int	fork_id;

// 	fork_id = this_philo->right_fork;
// 	if (pthread_mutex_lock(&this_philo->go_info->m_fork_arr[fork_id]))
// 	{
// 		return (RET_ERROR);
// 	}
// 	else
// 	{
// 		//printf("[%d] get right fork \n", this_philo->id);
// 	}
// 	// printf("right\n");
// 	return (OK);
// }


// void	return_forks(int philo->id)
// {
// 	pthread_mutex_lock(&mutexes[philo->id % info->num_philo]);
// 	permits[philo->id % info->num_philo] = 1;
// 	// while (permits[philo->id % info->num_philo] == 0)
// 	// 	pthread_cond_wait(&conditionVars[philo->id % info->num_philo], &mutexes[philo->id % info->num_philo]);
// 	// 	// 조건이 참이 될 때까지 대기하는 함수
// 	// 	/
// 	pthread_mutex_unlock(&mutexes[philo->id % info->num_philo]);
// }