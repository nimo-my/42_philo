/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:20 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/08 11:18:48 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		info->philos[i].go_info = (t_info *)p_malloc(sizeof(t_info));
		info->philos[i].go_info = info;

		info->philos[i].eat_count = 0;
		info->philos[i].id = i;
		info->philos[i].right_fork = i;
		if (info->philos[i].id > 0)
			info->philos[i].left_fork = i - 1;
		else
			info->philos[i].left_fork = info->num_philo - 1;
		// printf("info->philo[%d] id : %d, 오른쪽포크 : %d, 왼쪽포크 : %d \n",i, info->philos[i].id, info->philos[i].right_fork, info->philos[i].left_fork);
		
		i++;
	}
	// info->t_id_arr = malloc(sizeof(pthread_t) * info->num_philo);
}

int	make_philos(t_info *info)
{
	int i;

	init_philo(info);
	i = 0;
	while (i < info->num_philo)
	{
		//printf("i : %d\n", i);
		//printf("%p [1]info->philo[%d] id : %d, 오른쪽포크 : %d, 왼쪽포크 : %d \n",&info->philos[i], i, info->philos[i].id, info->philos[i].right_fork, info->philos[i].left_fork);
		pthread_create(&info->t_id_arr[i], NULL, philos_eat, &info->philos[i]);
		//printf("%p [2]info->philo[%d] id : %d, 오른쪽포크 : %d, 왼쪽포크 : %d \n",&info->philos[i], i, info->philos[i].id, info->philos[i].right_fork, info->philos[i].left_fork);
		i++;
	}
	
	i = 0;
	while (i < info->num_philo)
	{
		pthread_join(info->t_id_arr[i], NULL);
		i++;
	}
	printf("\n\033[0;33mend of join \n\033[0m");
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

int	philo_run(t_philo *philo)
{
	long	start_time;
	long	end_time;

	if (philo->id % 2 == 0) // 짝수는 늦게 시작
		usleep(200);
	
	while (philo->eat_count < philo->go_info->num_must_eat)
	{
		if (philo->eat_count > philo->go_info->num_must_eat)
			break;
		if ((philo->id % 2 == 0) && (pick_right_fork(philo) != RET_ERROR))
		{
			if (pick_left_fork(philo) != RET_ERROR)
			{
				printf("\n\033[0;33mphilo[%d] philo is thinking...\n\033[0m", philo->id);
				//thinking
				philo->check_end = set_time(philo->limit_time_end); // check
				if (philo->check_start - philo->check_end > philo->starve_time) // starving : if check_start - check_end > starve_time
				{
					printf("[] philo : [%d], starve time : [%ld]\n ",philo->id, philo->check_start - philo->check_end);
					printf("\033[0;31m[%d] philo is dead...\n\033[0m", philo->id);
					break;
				}
				if (!philo_eat(philo, &start_time, &end_time)) //eat
					return (RET_ERROR); //(p_error("ERROR : during philo eating. \n"));
			}
		}
		else if ((philo->id % 2 == 1) && (pick_left_fork(philo) != RET_ERROR))
		{
			if (pick_right_fork(philo) != RET_ERROR)
			{
				printf("\n\033[0;33m[%d] philo is thinking...\n\033[0m", philo->id);
				//thinking
				philo->check_end = set_time(philo->limit_time_end); // check
				if (philo->check_start - philo->check_end > philo->starve_time) // starving : if check_start - check_end > starve_time
				{
					printf("\033[0;31m[%d] philo is dead...\n\033[0m", philo->id);
					break;
				}
				if (!philo_eat(philo, &start_time, &end_time)) //eat
					return (RET_ERROR); //(p_error("ERROR : during philo eating. \n"));
			}
		}
		if (!philo_sleep(philo, &start_time, &end_time)) // sleep time
			return (RET_ERROR); // p_error("ERROR : during philo sleeping. \n")
		// think time  (waiting time)
	}
	return (0);
}