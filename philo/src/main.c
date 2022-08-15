/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:10:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 23:02:26 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo(t_info *info)
{
	int ret_monitor;
	// 이 처리를 어떻게 해주지? 시간 스레드 만든 다음에 측정하는게 맞는ㄱ ㅓㅅ 같은데ㅔ
	// 스레드가 만들어졌는데 시간이 초기화가 안 되어있을 수 있잖아! 
	// 일단 처음에도 start time 만들어주긴 했는데 실험해봐야 할 것 같아. 
	pthread_mutex_lock(&info->m_start_time);
	gettimeofday(&info->start_time, 0);
	pthread_mutex_unlock(&info->m_start_time);

	if (philo_create_thread(info) == RET_ERROR) // 스레드 생성
		return (RET_ERROR);

	pthread_mutex_lock(&info->m_start_time);
	gettimeofday(&info->start_time, 0);
	pthread_mutex_unlock(&info->m_start_time);

	ret_monitor = monitor(info);
	if (ret_monitor == PHIL_DIE)
		return (PHIL_DIE); // 모니터 (계속 돌아갈 수 있도록)

	if (philo_collect_all_thread(info) == RET_ERROR)
		return (RET_ERROR);

	return (OK);
}

int main(int argc, char *argv[])
{
	t_info	*info;

	// [set] & [init]
	info = make_info_struct(argc, argv);
	if (!info || check_argv(argc, info) == RET_ERROR)
	{
		p_error("ERROR : invalid input!\n");
		return (RET_ERROR);
	}
	// [run philo]
	if (philo_init_input(info) == ERROR || philo(info) != OK)
		return (RET_ERROR);

	//[clean_up] , free, thread mutex unlock->destroy
	end_philo(info);

	return (0);
}
