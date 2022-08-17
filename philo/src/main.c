/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:10:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 21:12:21 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_init_input(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		memset(&info->philos[i], 0, sizeof(t_philo));
		info->philos[i].info = (t_info *)malloc(sizeof(t_info));
		if (!info->philos[i].info)
			return (RET_ERROR);
		info->philos[i].info = info;
		info->philos[i].eat_count = 0;
		info->philos[i].id = i;
		info->philos[i].right_fork = i;
		info->philos[i].left_fork = (i + 1) % info->num_philo;
		i++;
	}
	return (OK);
}

int	philo_create_thread(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		gettimeofday(&info->start_time, 0);
		if (pthread_create(&info->t_philo[i], 0, philo_run, &info->philos[i]))
			return (RET_ERROR);
		gettimeofday(&info->philos[i].current_eat, 0);
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
	int				gap;
	struct timeval	curr;
	int				ret_monitor;

	if (philo_init_input(info) == RET_ERROR)
		return (RET_ERROR);
	if (philo_create_thread(info) == RET_ERROR)
		return (RET_ERROR);
	ret_monitor = monitor(info);
	gettimeofday(&curr, NULL);
	gap = time_gap(info->start_time, curr);
	if (ret_monitor == -1)
		printf("== philo eat all. dinning end! ==\n");
	else
		printf("[%d] philo %d died\n", gap, ret_monitor);
	if (philo_collect_all_thread(info) == RET_ERROR)
		return (RET_ERROR);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	*info;

	info = make_info_struct(argc, argv);
	if (!info)
		return (RET_ERROR);
	if (philo(info) == RET_ERROR)
		return (RET_ERROR);
	end_philo(info);
	return (0);
}
