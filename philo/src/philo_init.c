/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:20 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/07 17:13:53 by jisookim         ###   ########.fr       */
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
		printf("i : %d\n", i);
		//printf("%p [1]info->philo[%d] id : %d, 오른쪽포크 : %d, 왼쪽포크 : %d \n",&info->philos[i], i, info->philos[i].id, info->philos[i].right_fork, info->philos[i].left_fork);
		pthread_create(&info->t_id_arr[i], NULL, philos_eat, &info->philos[i]);
		//printf("%p [2]info->philo[%d] id : %d, 오른쪽포크 : %d, 왼쪽포크 : %d \n",&info->philos[i], i, info->philos[i].id, info->philos[i].right_fork, info->philos[i].left_fork);
		i++;
	}
	
	i = 0;
	while (i < info->num_philo)
	{
		printf("wait \n");
		pthread_join(info->t_id_arr[i], NULL);
		i++;
	}
	printf("\n end of join \n");
	return (OK);
}


void	*philos_eat(void *arg)
{
	t_philo	*this_philo;
	this_philo = (t_philo *)arg;
	
	philo_run(this_philo);

	printf("[%d] finished!\n\n", this_philo->id);

	return (NULL);
}

void	philo_run(t_philo *philo)
{
	long	start_eat_time;
	long	end_eat_time;

	
	if (philo->id % 2 == 0) // 짝수는 늦게 시작
		usleep(300);
	
	while (philo->eat_count < philo->go_info->num_must_eat)
	{
		if (philo->eat_count > philo->go_info->num_must_eat)
			break;
		if ((philo->id % 2 == 0) && (pick_right_fork(philo) != RET_ERROR))
		{
			if (pick_left_fork(philo) != RET_ERROR)
			{
				start_eat_time = set_time(philo->go_info->start_time);
				usleep(philo->go_info->time_to_eat);
				end_eat_time = set_time(philo->go_info->end_time);
				printf("[%ld] [%d] philo is eating!\n", end_eat_time-start_eat_time, philo->id);
				pthread_mutex_unlock(&(philo->go_info->m_fork_arr[philo->left_fork]));
				pthread_mutex_unlock(&(philo->go_info->m_fork_arr[philo->right_fork]));
				philo->eat_count++;
				usleep(100);
			}
		}
		else if ((philo->id % 2 == 1) && (pick_left_fork(philo) != RET_ERROR))
		{
			if (pick_right_fork(philo) != RET_ERROR)
			{
				start_eat_time = set_time(philo->go_info->start_time);
				usleep(philo->go_info->time_to_eat);
				end_eat_time = set_time(philo->go_info->end_time);
				printf("[%ld] [%d] philo is eating!\n", end_eat_time-start_eat_time, philo->id);
				pthread_mutex_unlock(&(philo->go_info->m_fork_arr[philo->left_fork]));
				pthread_mutex_unlock(&(philo->go_info->m_fork_arr[philo->right_fork]));
				philo->eat_count++;
				usleep(100);
			}
		}
		
	}

}
