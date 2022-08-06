/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:20 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/07 01:53:01 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	make_philos(t_info *info)
{
	int i;

	init_philo(info);
	i = 0;
	while (i < info->num_philo)
	{
		//printf("info->philo[%d] id : %d, 오른쪽포크 : %d, 왼쪽포크 : %d \n",i, info->philos[i].id, info->philos[i].right_fork, info->philos[i].left_fork);
		if (pthread_create(&info->t_id_arr[i], NULL, philos_eat, &info->philos[i]))
			return (RET_ERROR);
		i++;
	}
	return (OK);
}

void	init_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		(&info->philos[i])->go_info = info;
		(&info->philos[i])->id = i;
		(&info->philos[i])->right_fork = i + 1;
		if ((&info->philos[i])->id > 0)
			(&info->philos[i])->left_fork = i - 1;
		else
			(&info->philos[i])->left_fork = info->num_philo;
		// printf("info->philo[%d] id : %d, 오른쪽포크 : %d, 왼쪽포크 : %d \n",i, info->philos[i].id, info->philos[i].right_fork, info->philos[i].left_fork);
		
		i++;
	}
}

void	*philos_eat(void *arg)
{
	t_philo	*this_philo;
	
	this_philo = (t_philo *)arg;
	if (this_philo->id % 2) // 홀수
		odd_philo(this_philo);
	else
		even_philo(this_philo);
	return (NULL);
}

void	odd_philo(t_philo *philo)
{
	long	start_eat_time;
	long	end_eat_time;

	start_eat_time = set_time(philo->go_info->start_time);
	end_eat_time = set_time(philo->go_info->end_time);
	//printf("id : %d ,time : [%ld] \n",philo->id, end_eat_time-start_eat_time);
	
	// printf("id : %d ,time : [%ld] \n",philo->id, end_eat_time-start_eat_time);
	// pick_right_fork(philo);
	// pick_left_fork(philo);
	// start_eat_time = set_time(philo->go_info->start_time);
	// sleep(1);
	// end_eat_time = set_time(philo->go_info->end_time);
	// printf("id : %d ,time : [%ld] [%ld] res: [%ld]\n",philo->id, start_eat_time, end_eat_time, end_eat_time-start_eat_time);
	// [pick up right fork]


	// if ((pick_right_fork(philo) != RET_ERROR) && (pick_left_fork(philo) != RET_ERROR))
	// {
	// 	start_eat_time = set_time(philo->go_info->start_time);
	// 	sleep(1);
	// 	end_eat_time = set_time(philo->go_info->end_time);
	// 	printf("id : %d ,time : [%ld] [%ld] res: [%ld]\n",philo->id, start_eat_time, end_eat_time, end_eat_time-start_eat_time);
	// }
}

void	even_philo(t_philo *philo)
{

	long	start_eat_time;
	long	end_eat_time;

	start_eat_time = set_time(philo->go_info->start_time);
	end_eat_time = set_time(philo->go_info->end_time);
	// printf("id : %d ,time : [%ld] \n",philo->id, end_eat_time-start_eat_time);
	
	// [pick up right fork]
	// if ((pick_right_fork(philo) != RET_ERROR) && (pick_left_fork(philo) != RET_ERROR))
	// {
	// 	start_eat_time = set_time(philo->go_info->start_time);
	// 	sleep(1);
	// 	end_eat_time = set_time(philo->go_info->end_time);
	// 	printf("id : %d ,time : [%ld] [%ld] res: [%ld]\n",philo->id, start_eat_time, end_eat_time, end_eat_time-start_eat_time);
	// }

}
