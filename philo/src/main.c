/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:10:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/04 17:33:22 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char *argv[])
{
	t_info	*info;
	t_philo	philo;
	int i;

	// [set] & [init]
	info = make_info_struct(info);
	if (!info || set_and_return(argc, argv, info))
		return (ERROR);

	// [do] // -필로소퍼 생성(스레드 생성)

	i = 0;
	// 뮤텍스초기화
	while (i < info->num_philo)
	{
		pthread_mutex_init(&info->mutex_arr[i], NULL);
		info->permit_fork[i] = 1; // set and return 에서 하긴 함

		// [[ philo 홀 짝에 따라 다른 스레드 만들기 ]]
		if (i % 2) // 홀수 필로 스레드 생성
			pthread_create(&info->tid_arr[i], NULL, odd_philo, (void *)(unintptr_t)i);
		else // 짝수 필로 스레드 생성
			pthread_create(&info->tid_arr[i], NULL, even_philo, (void *)(unintptr_t)i);

		i++;
	}

	// 중간 정검, 스레드 볼 수 있는 함수로 스레드가 정상적으로 잘 만들어졌는지 확인하고 넘어가자! 

	// // - 필로소퍼 생성 완료하면 시간재고 시뮬레이션 시작
	// // 

	// // thread join (기다리기)
	// i = 0;
	// while (i < info->num_philo)
	// {
	// 	pthread_join(&info->tid_arr[i], NULL);
	// 	i++;
	// }

	// // malloc free, delete philo

	// // pthread_mutex_destroy
	// i  = 0;
	// while (i < info->num_philo)
	// {
	// 	pthread_mutex_destroy(&mutex_arr[i]);
	// 	i++;
	// }

	return (0);
}
