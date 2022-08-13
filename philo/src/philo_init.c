/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:20 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/14 04:06:53 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void philo_init_input(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		memset(&info->philos[i], 0, sizeof(t_philo));
		info->philos[i].info = (t_info *)malloc(sizeof(t_info));
		info->philos[i].info = info;

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
		if (!pthread_create(&info->t_philo[i], 0, philo_run, &info->philos[i]))
			return (RET_ERROR);
		i++;
	}
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
	printf("\n\033[0;33mend of join \n\033[0m"); //debug
	return (OK);
}






//printf("i : %d\n", i);
//printf("%p [1]info->philo[%d] id : %d, 오른쪽포크 : %d, 왼쪽포크 : %d \n",&info->philos[i], i, info->philos[i].id, info->philos[i].right_fork, info->philos[i].left_fork);


// int	handle_err(t_info *info, enum THD_ERR_MSG err)
// {
// 	info->err_flag = 1; // 모니터에서 이걸 계속 체크해야겠다
// 	return (err);
// }

// int	check(t_info *info, int result, enum THD_ERR_MSG err)
// {
// 	if (!result) // 함수들이 성공시 0을 반환하기 때문에
// 		return (OK); // 1
// 	else if (err = CREATE)
// 		return (handle_err(info, CREATE)); // 2
// 	else if (err = JOIN)
// 		return (handle_err(info, JOIN));
// 	else if (err = MUTEX_INIT)
// 		return (handle_err(info, MUTEX_INIT));
// 	else if (err = MUTEX_DESTROY)
// 		return (handle_err(info, MUTEX_DESTROY));
// 	else if (err = MUTEX_LOCK)
// 		return (handle_err(info, MUTEX_LOCK));
// 	else if (err = MUTEX_UNLOCK)
// 		return (handle_err(info, MUTEX_UNLOCK));
// 	return (RET_ERROR);
// }
