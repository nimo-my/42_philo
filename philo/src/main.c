/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:10:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/04 23:29:28 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char *argv[])
{
	t_info	*info;
	// t_philo	*philo;
	

	// [set] & [init]
	info = make_info_struct(argc, argv);
	printf("info->num_philo: %d\n", info->num_philo);
	printf("info->ttd: %d\n", info->time_to_die);
	printf("info->tte: %d\n", info->time_to_eat);
	printf("info->tts: %d\n", info->time_to_sleep);
	printf("info->nme: %d\n", info->num_must_eat);
	if (!set_info_and_return(argc, info))
	{
		printf("asdfasdf\n");
		return (RET_ERROR);
	}
	
	

	
	// [do] // -필로소퍼 생성(스레드 생성)

	// i = 0;
	// // 뮤텍스초기화
	// while (i < info->num_philo)
	// {
	// 	pthread_mutex_init(&info->mutex_arr[i], NULL);
	// 	info->permit_fork[i] = 1; // set and return 에서 하긴 함

	// 	// [[ philo 홀 짝에 따라 다른 스레드 만들기 ]]
	// 	philo = make_info_philo(philo);
	// 	philo->id = i;
	// 	if (i % 2) // 홀수 필로 스레드 생성
	// 	{
			
	// 		pthread_create(&info->tid_arr[i], NULL, odd_philo, (void *)philo);
	// 	}
	// 	else // 짝수 필로 스레드 생성
	// 	{
		
	// 			pthread_create(&info->tid_arr[i], NULL, even_philo, (void *)philo);
	// 	}
	// 	i++;
	// }

	// --------------------------------------------------
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
