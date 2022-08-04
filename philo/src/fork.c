/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:00:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/04 22:20:44 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void	pickup_forks(t_info info, t_philo philo, int philo->id)
// {
// 	pthread_mutex_lock(&mutex_arr[philo->id % info->num_philo]);

// 	//조건을 적어 critical section 안에 들어오지 못하고 대기하는 부분을 만들면 된다. 

// 	// while (permits[philo->id % info->num_philo] == 0)
// 	// 	pthread_cond_wait(&conditionVars[philo->id % info->num_philo], &mutexes[philo->id % info->num_philo]);
// 	// 	// 조건이 참이 될 때까지 대기하는 함수
// 	// 	// 이 함수는 호출한 스레드를 조건발생대기 스레드의 목록에 추가하고 뮤텍스를 풀게 됨.
// 	permits[philo->id % info->num_philo] = 0;
// 	pthread_mutex_unlock(&mutexes[philo->id % info->num_philo]);
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