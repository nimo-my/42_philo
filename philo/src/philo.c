/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:20 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/04 22:28:05 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*even_philo(t_philo *philo)
{
	philo->id = (int)philo->id;

	printf("[eve] [%d] 필로 생성됨!\n", philo->id);
	// // [pick up left fork]
	// pickup_forks(philo->id);
	// //printf("[%d] %d has taken a fork.(%d)\n", philo->id);

	// // [pick up right fork]
	// pickup_forks(philo->id + 1);
	// // printf("philo(%d)가 포크(%d)를 집었습니다.\n", philo->id, (philo->id + 1) % NUM_THREADS);
	// // printf("philo(%d)가 먹기 시작했습니다.\n", philo->id);
	// sleep(2);
	// // printf("philo(%d)가 다 먹었습니다.\n", philo->id);

	// // [put down right fork]
	// return_forks(philo->id + 1);
	// // printf("philo(%d)가 포크(%d)를 내려놓았습니다.\n", philo->id, (philo->id + 1) % NUM_THREADS);

	// // [put down left fork]
	// return_forks(philo->id);
	// // printf("philo(%d)가 포크(%d)를 내려놓았습니다.\n", philo->id, philo->id);

	return (NULL);
}

void	*odd_philo(t_philo *philo)
{
	philo->id = (int)philo->id;

	printf("[odd] [%d] 필로 생성됨!\n", philo->id);

	// // [pick up right fork]
	// pickup_forks(philo->id + 1);
	// // printf("philo(%d)가 포크(%d)를 집었습니다.\n", philo->id, (philo->id + 1) % NUM_THREADS);

	// // [pick up left fork]
	// pickup_forks(philo->id);
	// // printf("philo(%d) 가 포크(%d)를 집었습니다.\n", philo->id, philo->id);
	// // printf("philo(%d)가 먹기 시작했습니다.\n", philo->id);
	// sleep(2);
	// // printf("philo(%d)가 다 먹었습니다.\n", philo->id);

	// // [put down left fork]
	// return_forks(philo->id);
	// // printf("philo(%d)가 포크(%d)를 내려놓았습니다.\n", philo->id, philo->id);

	// // [put down right fork]
	// return_forks(philo->id + 1);
	// // printf("philo(%d)가 포크(%d)를 내려놓았습니다.\n", philo->id, (philo->id + 1) % NUM_THREADS);

	return (NULL);
}