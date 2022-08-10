/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:20 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/10 19:15:01 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philo(t_info *info)
{
	philo_init_input(info);
	if (philo_create_thread(info) == RET_ERROR)
		return (RET_ERROR);
	if (philo_collect_all_thread(info) == RET_ERROR)
		return (RET_ERROR);
	return (OK);
}

void philo_init_input(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		memset(&info->philos[i], 0, sizeof(t_philo));
		info->philos[i].time = (t_time *)malloc(sizeof(t_time));
		info->philos[i].go_info = (t_info *)malloc(sizeof(t_info));
		info->philos[i].go_info = info;
		
		// info->philos[i].flag_think = 0;
		// info->philos[i].flag_eat = 0;
		// info->philos[i].flag_sleep = 0;
		
		info->philos[i].eat_count = 0;
		info->philos[i].id = i;
		info->philos[i].right_fork = i;
		info->philos[i].left_fork = (i + 1) % info->num_philo;
		i++;
	}
}

int	philo_create_thread(t_info *info)
{
	int i;

	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_create(&info->t_id_arr[i], NULL, philos_eat, &info->philos[i]))
			return (RET_ERROR);
		i++;
	}
	return (OK);
}

void	*philos_eat(void *arg)
{
	t_philo	*this_philo;
	this_philo = (t_philo *)arg;
	
	if (philo_run(this_philo))
		return ("ERROR!\n"); //return (p_error("ERROR : during philo program running.\n"));

	printf("\033[0;34mphilo [%d] finished!\n\n\033[0m", this_philo->id);
	return (NULL);
}

int	philo_collect_all_thread(t_info *info)
{
	int	i;
	
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(info->t_id_arr[i], NULL))
			return (RET_ERROR);
		i++;
	}
	printf("\n\033[0;33mend of join \n\033[0m"); //debug
	return (OK);
}

//printf("i : %d\n", i);
//printf("%p [1]info->philo[%d] id : %d, 오른쪽포크 : %d, 왼쪽포크 : %d \n",&info->philos[i], i, info->philos[i].id, info->philos[i].right_fork, info->philos[i].left_fork);