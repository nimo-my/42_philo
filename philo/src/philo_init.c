/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:20 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/06 20:39:11 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	make_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		if (i % 2) // 홀수
			pthread_create(&info->t_id_arr[i], NULL, odd_philo, &info->philos[i]);
		else
			pthread_create(&info->t_id_arr[i], NULL, even_philo, &info->philos[i]);
		
		(&info->philos[i])->info_struct = info;
		(&info->philos[i])->id = i;
		(&info->philos[i])->right_fork = i + 1;

		if ((&info->philos[i])->id > 0)
			(&info->philos[i])->left_fork = i - 1;
		else	
			(&info->philos[i])->left_fork = info->num_philo;
		//printf("id : %d\n", info->philos[i].id);
		//printf("info->philo[%d] id : %d, 오른쪽포크 : %d, 왼쪽포크 : %d \n",i, info->philos[i].id, info->philos[i].right_fork, info->philos[i].left_fork);
		i++;
	}
}


void	*odd_philo(void *arg)
{
	// 구조체 만들고 할당
	t_philo	*this_philo;

	this_philo = (t_philo *)arg;

	// printf("[odd] [%d] 필로 생성됨!\n", this_philo->id);
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


void	*even_philo(void *arg)
{
	// 구조체 만들고 할당
	t_philo *this_philo;

	this_philo = (t_philo *)arg;

	// printf("[eve] [%d] 필로 생성됨!\n", this_philo->id);
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
