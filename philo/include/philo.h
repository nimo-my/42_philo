/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:18:43 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/14 04:20:39 by jisookim         ###   ########seoul.kr  */
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

enum	THD_ERR_MSG
{
	CREATE = 2,
	JOIN,
	MUTEX_INIT,
	MUTEX_DESTROY,
	MUTEX_LOCK,
	MUTEX_UNLOCK
};

typedef struct s_philo
{
	struct s_info	*info;

	int		id;				// init in set_info_struct
	int		right_fork;
	int		left_fork;

	struct timeval	current_eat;

	int					eat_count;
	pthread_mutex_t		*m_eat_count;


}				t_philo;

typedef struct s_info
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat; // if argv == 6 only

	int	flag_die;
	int	flag_eat_all;

	struct timeval	start_time;

	t_philo				*philos;
	pthread_t			*t_philo; // init in set_info_struct

	pthread_mutex_t		*m_fork; // init in set_info_struct
	pthread_mutex_t		m_flag_die;
	pthread_mutex_t		m_print;



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
void	*philo_run(void *arg);



// time.c
time_t	custom_timer(int input_time);

time_t	starved_time(struct timeval start_time, struct timeval end_time);


//philo_init.c
int		init_philo(t_info *info);
void	philo_init_input(t_info *info);
int		philo_create_thread(t_info *info);
void	*philos_eat(void *arg);
int		philo_collect_all_thread(t_info *info);


//print.c
int	print(t_philo *philo, time_t time, int id, char *message);
#endif
