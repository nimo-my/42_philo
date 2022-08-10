/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:34:46 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/10 10:10:51 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// int	philo_run(t_philo *philo)
// {
// 	long	start_time;
// 	long	end_time;

// 	if (philo->id % 2 == 0) // 짝수는 늦게 시작
// 		usleep(200);
	
// 	while (philo->eat_count < philo->go_info->num_must_eat)
// 	{
// 		if ((philo->id % 2 == 0) && (pick_right_fork(philo) != RET_ERROR))
// 		{
// 			if (pick_left_fork(philo) != RET_ERROR)
// 			{
// 				printf("\n\033[0;33mphilo[%d] philo is thinking...\n\033[0m", philo->id);
// 				//thinking
// 				philo->check_end = set_time(philo->limit_time_end); // check
// 				if (philo->check_start - philo->check_end > philo->starve_time) // starving : if check_start - check_end > starve_time
// 				{
// 					printf("[] philo : [%d], starve time : [%ld]\n ",philo->id, philo->check_start - philo->check_end);
// 					printf("\033[0;31m[%d] philo is dead...\n\033[0m", philo->id);
// 					break;
// 				}
// 				if (!philo_eat(philo, &start_time, &end_time)) //eat
// 					return (RET_ERROR); //(p_error("ERROR : during philo eating. \n"));
// 			}
// 		}
// 		else if ((philo->id % 2 == 1) && (pick_left_fork(philo) != RET_ERROR))
// 		{
// 			if (pick_right_fork(philo) != RET_ERROR)
// 			{
// 				printf("\n\033[0;33m[%d] philo is thinking...\n\033[0m", philo->id);
// 				//thinking
// 				philo->check_end = set_time(philo->limit_time_end); // check
// 				if (philo->check_start - philo->check_end > philo->starve_time) // starving : if check_start - check_end > starve_time
// 				{
// 					printf("\033[0;31m[%d] philo is dead...\n\033[0m", philo->id);
// 					break;
// 				}
// 				if (!philo_eat(philo, &start_time, &end_time)) //eat
// 					return (RET_ERROR); //(p_error("ERROR : during philo eating. \n"));
// 			}
// 		}
// 		if (!philo_sleep(philo, &start_time, &end_time)) // sleep time
// 			return (RET_ERROR); // p_error("ERROR : during philo sleeping. \n")
// 		// think time  (waiting time)
// 	}
// 	return (0);
// }

int	philo_run(t_philo *philo)
{
	long	start_time;
	long	end_time;

	if (philo->id % 2 == 0) // 짝수는 늦게 시작
		usleep(200);
	
	while (philo->eat_count < philo->go_info->num_must_eat)
	{
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


int philo_eat(t_philo *philo, long *start_time, long *end_time)
{
	*start_time = set_time(philo->go_info->start_time);
	usleep(philo->go_info->time_to_eat);
	*end_time = set_time(philo->go_info->end_time);
	printf("\033[0;35m[%ld] [%d] philo is eating!\n\033[0m", *end_time - *start_time, philo->id);
				
	philo->check_start = *end_time;
	philo->eat_time = *end_time - *start_time;

	// return fork
	pthread_mutex_unlock(&(philo->go_info->m_fork_arr[philo->left_fork]));
	pthread_mutex_unlock(&(philo->go_info->m_fork_arr[philo->right_fork]));
	philo->eat_count++;
	usleep(100);

	return (OK);
}

int	philo_sleep(t_philo *philo, long *start_time, long *end_time)
{
	*start_time = set_time(philo->go_info->start_time);
	usleep(philo->go_info->time_to_eat);
	*end_time = set_time(philo->go_info->end_time);
	printf("\033[0;32m[%ld] [%d] philo is sleeping...\n\033[0m", *end_time - *start_time, philo->id);

	//if (*end_time-*start_time > philo->go_info->time_to_sleep)
	return (OK);
}