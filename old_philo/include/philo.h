/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:18:43 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/14 02:19:50 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ************************************************************************** */
// 	INCLUDE
/* ************************************************************************** */

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h> // gettimeofday
# include <unistd.h>
# include <stdio.h> // printf
# include <stdbool.h>
#include <string.h> // memset

/* ************************************************************************** */
// 	DEFINE
/* ************************************************************************** */

# define OK			1
# define ERROR		0
# define PHIL_DIE	0
# define RET_ERROR	-1

# define BEF_SEC_0	0
# define BEF_SEC_1	1
# define BEF_SEC_2	2
# define BEF_SEC_3	3

/* ************************************************************************** */
// 	STRUCTURE
/* ************************************************************************** */

typedef struct s_time
{
	uint64_t	start_time;
	uint64_t	eat_time;
	uint64_t	sleep_time;
	uint64_t	now_time;

	// end
	struct timeval	start;
	struct timeval	think;
	struct timeval	eat;
	struct timeval	sleep;

}				t_time;

typedef struct s_philo
{
	struct s_time	*time;
	struct s_info	*info;

	int		eat_count;
	int		id;				// init in set_info_struct
	int		right_fork;
	int		left_fork;

}				t_philo;

typedef struct s_info
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat; // if argv == 6 only

	int					finish_flg;
	int					argc_flg; // 0 : argc = 5 // 1 : argc = 6
	size_t				count;
	t_philo				*philos;
	pthread_t			*t_philo; // init in set_info_struct
	int					*permit_fork; // default all 1, init in set_info_struct
	pthread_mutex_t		*m_fork; // init in set_info_struct
	pthread_mutex_t		m_print; //

}						t_info;

/* ************************************************************************** */
// 	p_func
/* ************************************************************************** */

size_t	p_atoi(const char *str);
void	*p_memcpy(void *dest, const void *src, size_t n);
int		p_error(char *msg);
size_t	p_strlen(const char *str);

/* ************************************************************************** */
// 	src
/* ************************************************************************** */

// init_info.c
t_info	*make_info_struct(int argc, char *argv[]);
void	set_info_struct(t_info *info);
void	init_info_argv(int argc, char *argv[], t_info *info);
int		check_argv(int argc, t_info *info);

// philo_fork.c
int	pick_fork(t_philo *this_philo, int fork_position);

// philo_run.c
int	philo_run(t_philo *philo);
int take_fork_and_eat(t_philo *philo, int first_fork, int second_fork);
int philo_eat(t_philo *philo);
int put_down_fork(t_philo *philo, int first_fork, int second_fork);
int philo_sleep(t_philo *philo);

// philo_time.c
long	set_time(struct timeval time);


//philo_init.c
int		init_philo(t_info *info);
void	philo_init_input(t_info *info);
int		philo_create_thread(t_info *info);
void	*philos_eat(void *arg);
int		philo_collect_all_thread(t_info *info);


//print.c
int	print(char *message, t_philo *philo);

#endif
