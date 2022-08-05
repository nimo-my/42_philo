/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:50:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/05 12:28:40 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// 스레드 생성(필로 홀짝 id에 따라 다르게)
// 뮤텍스 생성(m_fork_arr, m_print,arr)
// 홀수 짝수 필로

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	
	philo = (t_philo *)p_malloc(sizeof(t_philo) * info->num_philo);
	p_memset(philo, 0, sizeof(t_philo) * info->num_philo);

	
	return (philo);
}

void	make_philos(t_info *info)
{
	int		i;
	int		id;

	i = 0;
	id = 0;
	// printf("zz\n");
	// printf("info->num_philo: %d\n", info->num_philo);
	while (i < info->num_philo)
	{
		// philo = init_philo(info, i); // 각 스레드 별 필로 구조체 만들기
		info->permit_fork[i] = 1;
		printf("info->permit_fork[%d]: %d\n",i, info->permit_fork[i]);
		printf("info->philos[%d].id: %d\n",i, info->philos[i].id);
		if (i % 2) // 홀수
		{
			// printf("aa\n");
			p_memcpy(&(info->philos[i]), init_philo(info), sizeof(t_philo));
			pthread_create(&info->t_id_arr[i], NULL, odd_philo, &info->philos[i]);
			//printf("[홀] %d 철학자 생성!\n", i);
		}
		else
		{
			//printf("bb\n");
			p_memcpy(&(info->philos[i]), init_philo(info), sizeof(t_philo));
			pthread_create(&info->t_id_arr[i], NULL, even_philo, &info->philos[i]);
			//printf("[짝] %d 철학자 생성!\n", i);
		}
		i++;
	}
	printf("asdfasdfasdfasdf\n");
}


// t_philo	*make_philo_struct()
// {
// 	t_philo *philo;

// 	philo = (t_philo *)p_malloc(sizeof(t_philo));
// 	p_memset(philo, 0, sizeof(t_philo));
// 	return (philo);
// }




// t_info	*make_info_struct(int argc, char *argv[])
// {
// 	t_info *info;

// 	info = (t_info *)p_malloc(sizeof(t_info));
// 	p_memset(info, 0, sizeof(t_info));
// 	init_info_arr(info);
// 	init_info_input(argc, argv, info, philo);
// 	return (info);
// }

// void	init_info_arr(t_info *info)
// {
// 	// permit_fork initialize, default 1.
// 	info->permit_fork = (int *)p_malloc(sizeof(int) * info->num_philo);
// 	p_memset(info->permit_fork, 1, sizeof(int) * info->num_philo);

// 	info->t_id_arr = (pthread_t **)p_double_malloc(sizeof(pthread_t *) \
// 															* info->num_philo);
// 	info->m_print_arr = (pthread_mutex_t **)p_double_malloc\
// 								(sizeof(pthread_mutex_t *)* info->num_philo);
// }


// void	init_info_input(int argc, char *argv[], t_info *info, t_info *philo)
// {
// 	int	i;

// 	i = 0;
	
// 	if (argc == 5 || argc == 6)
// 	{
// 		info->num_philo = p_atoi(argv[1]);
// 		info->time_to_die = p_atoi(argv[2]);
// 		info->time_to_eat = p_atoi(argv[3]);
// 		info->time_to_sleep = p_atoi(argv[4]);
// 	}
// 	if (argc == 6)
// 		info->num_must_eat = p_atoi(argv[5]);
// 	while (i < info->num_philo)
// 	{
// 		if (i % 2){
// 			pthread_create(info->t_id_arr[i], NULL, even_philo, (void *)&philo);
// 			printf("even philo created %d\n", i);		
// 		}else{
// 			pthread_create(info->t_id_arr[i], NULL, odd_philo, (void *)&philo);
// 			printf("odd philo created %d\n", i);		
// 		}
// 		// info->t_id_arr = (pthread_t *)p_malloc(sizeof(pthread_t) * \
// 		// 													info->num_philo);
// 		// info->m_print_arr = (pthread_mutex_t *)p_malloc(sizeof(pthread_mutex_t)\
// 		// 													* info->num_philo);
// 		i++;
// 	}
// }

