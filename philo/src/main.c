/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:10:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 10:16:38 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_create_thread(t_info *info)
{
	int i;

	i = 0;
	gettimeofday(&info->start_time, 0);
	while (i < info->num_philo)
	{
		if (pthread_create(&info->t_philo[i], 0, philo_run, &info->philos[i]))
			return (RET_ERROR);
		i++;
	}
	return (OK);
}

int	philo_collect_all_thread(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(info->t_philo[i], NULL) >= 0)
			i++;
		else
			return (RET_ERROR);
	}
	return (OK);
}

int	philo(t_info *info)
{
	int ret_monitor;

	if (philo_create_thread(info) == RET_ERROR) // 스레드 생성
		return (RET_ERROR);
	ret_monitor = monitor(info);
	if (ret_monitor == EAT_ALL)
		printf("== philo eat all. dinning end! ==\n");
	else
		printf("== philo %d died. dinning end! ==\n", ret_monitor);
	if (philo_collect_all_thread(info) == RET_ERROR)
		return (RET_ERROR);
	return (0);
}

int main(int argc, char *argv[])
{
	t_info	*info;

	info = make_info_struct(argc, argv);
	if (!info || check_argv(info) == RET_ERROR)
		return (RET_ERROR);
	if (philo_init_input(info) == ERROR || philo(info) == RET_ERROR)
		return (RET_ERROR);
	end_philo(info);

	return (0);
}
