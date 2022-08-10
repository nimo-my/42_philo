/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:34:46 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/10 19:18:51 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_run(t_philo *philo)
{
	int flg;

	flg = 0;
	philo->time->start_time = set_time(philo->time->start);
	while (1)
	{
		if (philo->id % 2)
			flg = take_fork_and_eat(philo, philo->right_fork, philo->left_fork);
		else
			flg = take_fork_and_eat(philo, philo->left_fork, philo->right_fork);
		if (flg && (philo->id % 2) && (!put_down_fork(philo, philo->right_fork, philo->left_fork)))
			break ;
		else if (flg && (!put_down_fork(philo, philo->left_fork, philo->right_fork)))
			break ;
		if (philo->go_info->finish_flg == philo->go_info->num_philo)
		{
			printf("[%d] philo eat all.\n", philo->id);
			return (OK);
		}
		if (!philo_sleep(philo))
			break ;
		if (philo->go_info->argc_flg && philo->eat_count == philo->go_info->num_must_eat)
			return (OK);
	}
	return (PHIL_DIE);
}

int take_fork_and_eat(t_philo *philo, int first_fork, int second_fork)
{
	first_fork = philo->right_fork;
	second_fork = philo->left_fork;
	pthread_mutex_lock(&(philo->go_info->m_fork_arr[first_fork]));
	pthread_mutex_lock(&(philo->go_info->m_fork_arr[second_fork]));
	if (philo_eat(philo) != OK)
		return (PHIL_DIE);

	return (OK);
}

int philo_eat(t_philo *philo)
{
	usleep(philo->go_info->time_to_eat); // eat
	if (philo->time->eat_time - (philo->time->start_time) > \
												philo->go_info->time_to_die)
	{
		printf("philo : [%d], starve time : [%ld]\n ", \
				philo->id, philo->time->eat_time - (philo->time->start_time));
		return (PHIL_DIE);
	}
	return (OK);
}

int put_down_fork(t_philo *philo, int first_fork, int second_fork)
{
	pthread_mutex_unlock(&(philo->go_info->m_fork_arr[second_fork]));
	pthread_mutex_unlock(&(philo->go_info->m_fork_arr[first_fork]));
	philo->time->eat_time = set_time(philo->time->eat) - (philo->time->start_time); // set time
	philo->eat_count++;
	if (philo->eat_count == philo->go_info->num_must_eat)
		philo->go_info->finish_flg++;
	
	return (OK);
}

int philo_sleep(t_philo *philo)
{
	usleep(philo->go_info->time_to_sleep);
	philo->time->sleep_time = set_time(philo->time->sleep) - (philo->time->start_time); // set time
	philo->time->now_time += philo->time->sleep_time + philo->time->eat_time; 
	if (philo->time->now_time > philo->go_info->time_to_die)
		return (PHIL_DIE);
	return (OK);
}



// int	philo_run(t_philo *philo)
// {
// 	philo->time->living_time[0] = set_time(philo->time->living[0]);
// 	if (philo->id % 2 == 0) // 짝수는 늦게 시작
// 		usleep(200);
	
// 	while (philo->eat_count < philo->go_info->num_must_eat)
// 	{
// 		if ((philo->id % 2 == 0) && (pick_fork(philo, philo->right_fork) != RET_ERROR))
// 		{
// 			if (pick_fork(philo, philo->left_fork) != RET_ERROR)
// 			{
// 				philo->time->think_time[1] = set_time(philo->time->think[1]);
// 				philo->flg_think = philo_think(philo, philo->time->think_time);
// 				philo->flg_eat = philo_eat(philo); //eat
// 				philo->flg_sleep = philo_sleep(philo);
// 			}
// 		}
// 		else if ((philo->id % 2 == 1) && pick_fork(philo, philo->left_fork))
// 		{
// 			if (pick_fork(philo, philo->right_fork) != RET_ERROR)
// 			{
// 				philo->time->think_time[1] = set_time(philo->time->think[1]);
// 				philo->flg_think = philo_think(philo, philo->time->think_time);
// 				philo->flg_eat = philo_eat(philo); //eat
// 				philo->flg_sleep = philo_sleep(philo);
// 			}
// 		}
// 		philo->time->living_time[1] = set_time(philo->time->living[1]);
// 		printf("[][][] philo->time->living_time[2]: %llu\n", philo->time->living_time[2]);
// 		philo->time->living_time[2] += philo->time->living_time[1] - philo->time->living_time[0];
// 		if (philo->flg_think || philo->flg_eat || philo->flg_sleep || (philo->time->living_time[2] >= (unsigned long long)philo->go_info->time_to_die))
// 		{
// 			printf("\033[0;31m[%d] philo is dead...\n\033[0m", philo->id);
// 			break;
// 		}
// 		philo->time->think_time[0] = set_time(philo->time->think[0]); // think time  (waiting time)
// 	}
// 	return (0);
// }

// int	philo_run_must_eat(t_philo *philo)
// {
// 	if (philo->id % 2 == 0) // 짝수는 늦게 시작
// 		usleep(200);
	
// 	while (philo->eat_count < philo->go_info->num_must_eat)
// 	{
// 		if ((philo->id % 2 == 0) && (pick_fork(philo, philo->right_fork) != RET_ERROR))
// 		{
// 			if (pick_fork(philo, philo->left_fork) != RET_ERROR)
// 			{
// 				philo->time->think_time[1] = set_time(philo->time->think[1]);
// 				philo->flg_think = philo_think(philo, philo->time->think_time);
// 				philo->flg_eat = philo_eat(philo); //eat
// 				philo->flg_sleep = philo_sleep(philo);
// 			}
// 		}
// 		else if ((philo->id % 2 == 1) && pick_fork(philo, philo->left_fork))
// 		{
// 			if (pick_fork(philo, philo->right_fork) != RET_ERROR)
// 			{
// 				philo->time->think_time[1] = set_time(philo->time->think[1]);
// 				philo->flg_think = philo_think(philo, philo->time->think_time);
// 				philo->flg_eat = philo_eat(philo); //eat
// 				philo->flg_sleep = philo_sleep(philo);
// 			}
// 		}
// 		if (philo->flg_think || philo->flg_eat || philo->flg_sleep)
// 		{
// 			printf("\033[0;31m[%d] philo is dead...\n\033[0m", philo->id);
// 			break;
// 		}
// 		philo->time->think_time[0] = set_time(philo->time->think[0]); // think time  (waiting time)
// 	}
// 	return (0);
// }

// int philo_eat(t_philo *philo)
// {
// 	philo->time->eat_time[0] = set_time(philo->time->eat[0]); 
// 	usleep(philo->go_info->time_to_eat);// eat
// 	philo->time->eat_time[1] = set_time(philo->time->eat[1]);
// 	if (philo->time->eat_time[1] - philo->time->eat_time[0] > philo->go_info->time_to_die) // starving : if check_start - check_end > starve_time
// 	{
// 		printf("[] philo : [%d], starve time : [%ld]\n ",philo->id, philo->time->eat_time[1] - philo->time->eat_time[0]);
// 		return (PHIL_DIE);
// 	}
// 	pthread_mutex_unlock(&(philo->go_info->m_fork_arr[philo->left_fork]));
// 	pthread_mutex_unlock(&(philo->go_info->m_fork_arr[philo->right_fork]));
// 	philo->eat_count++;

// 	return (OK);
// }

// int	philo_sleep(t_philo *philo)
// {
// 	philo->time->sleep_time[0] = set_time(philo->time->sleep[0]);
// 	usleep(philo->go_info->time_to_sleep);
// 	philo->time->sleep_time[1] = set_time(philo->time->sleep[1]);
// 	printf("\033[0;32m[%ld] [%d] philo is sleeping...\n\033[0m", philo->time->sleep_time[1] - philo->time->sleep_time[0], philo->id);

// 	return (OK);
// }

// int	philo_think(t_philo *philo, uint64_t think_time[2]) // philo->time->think[1] - philo->time->think[0]
// {
// 	if (think_time[1] - think_time[0] > philo->go_info->time_to_think)
// 		return (PHIL_DIE);
// 	else
// 	{
// 		printf("\n\033[0;33m[%d] [%d] philo is thinking...\n\033[0m", think_time[1] - think_time[0], philo->id); //thinking
// 	}
// 	return (OK);
// }




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