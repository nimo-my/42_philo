/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:10:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/16 22:58:50 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo(t_info *info)
{
	int ret_monitor;

	if (philo_create_thread(info) == RET_ERROR) // 스레드 생성
		return (RET_ERROR);
	ret_monitor = monitor(info);
	if (ret_monitor == PHIL_DIE)
		return (PHIL_DIE);
	if (philo_collect_all_thread(info) == RET_ERROR)
		return (RET_ERROR);
	return (OK);
}

int main(int argc, char *argv[])
{
	t_info	*info;

	info = make_info_struct(argc, argv);
	if (!info || check_argv(info) == RET_ERROR)
		return (RET_ERROR);
	if (philo_init_input(info) == ERROR || philo(info) != OK)
		return (RET_ERROR);
	end_philo(info);

	return (0);
}
