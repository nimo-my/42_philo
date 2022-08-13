/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:10:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/14 04:10:00 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo(t_info *info)
{
	philo_create_thread(info); // 스레드 생성
	gettimeofday(&(info->start_time), 0); // 시작시간 측정

	monitor(info); // 모니터 (계속 돌아갈 수 있도록)

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
		return (RET_ERROR);

]	// [run philo]
	if (philo(info) != OK)
		return (RET_ERROR);

	//[clean_up] , free, thread mutex unlock->destroy
	clean(info);

	return (0);
}
