/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:46:26 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/07 03:22:27 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_info	*make_info_struct(int argc, char *argv[])
{
	t_info *info;

	info = (t_info *)p_malloc(sizeof(t_info));
	p_memset(info, 0, sizeof(t_info));
	init_info_argv(argc, argv, info);
	set_info_struct(info);
	return (info);
}

void	set_info_struct(t_info *info)
{
	info->count = 0;
	info->philos = (t_philo *)p_malloc(sizeof(t_philo) * info->num_philo);
	info->permit_fork = (int *)p_malloc(sizeof(int) * info->num_philo);
	info->t_id_arr = (pthread_t *)p_malloc(sizeof(pthread_t) \
															* info->num_philo);
	info->m_fork_arr = (pthread_mutex_t *)p_malloc\
								(sizeof(pthread_mutex_t)* info->num_philo);
	
}

void	init_info_argv(int argc, char *argv[], t_info *info)
{
	if (argc == 5 || argc == 6)
	{
		info->num_philo = p_atoi(argv[1]);
		info->time_to_die = p_atoi(argv[2]);
		info->time_to_eat = p_atoi(argv[3]);
		info->time_to_sleep = p_atoi(argv[4]);
		// printf("%s %s %s %s \n", argv[1], argv[2], argv[3], argv[4]); // debug
	}
	if (argc == 6)
		info->num_must_eat = p_atoi(argv[5]);
}

int	check_argv(int argc, t_info *info)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (info->num_philo <= 0 || info->time_to_die <= 0 || \
		info->time_to_eat <= 0 || info->time_to_sleep <= 0)
			flag = p_error("ERROR : input value needs to be over 0.");
	if ((argc == 6) && info->num_must_eat <= 0)
		flag = p_error("ERROR : input value needs to be over 0.");
	if (pthread_mutex_init(&(info->m_print), NULL)) //thread init
		flag = p_error("ERROR : thread initialize error");
	while (i < info->num_philo)
	{
		info->permit_fork[i] = 1;
		if (pthread_mutex_init(&info->m_fork_arr[i], NULL)) //init fork
			flag = p_error("ERROR : mutex initialize error");
		i++;
	}
	if (flag == RET_ERROR)
		return (RET_ERROR);
	return (OK);
}