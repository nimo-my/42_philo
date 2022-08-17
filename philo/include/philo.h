/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:18:43 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 21:40:52 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define OK			1
# define ERROR		0
# define PHIL_DIE	0
# define RET_ERROR	-1

enum e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD
};

typedef struct s_philo
{
	struct s_info		*info;
	int					id;
	int					right_fork;
	int					left_fork;
	struct timeval		current_eat;
	pthread_mutex_t		m_current_eat;
	int					eat_count;
	pthread_mutex_t		m_eat_count;
	int					flag_eat_all;
	pthread_mutex_t		m_flag_eat_all;
}						t_philo;

typedef struct s_info
{
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_must_eat;
	int					count_everyone_eat;
	pthread_mutex_t		m_everyone_eat;
	int					must_eat_all_flag;
	pthread_mutex_t		m_must_eat_all_flag;
	int					flag_die;
	pthread_mutex_t		m_flag_die;
	struct timeval		start_time;
	pthread_mutex_t		m_start_time;
	pthread_mutex_t		m_print;
	t_philo				*philos;
	pthread_t			*t_philo;
	int					*fork;
	pthread_mutex_t		*m_fork;
}						t_info;

// p_func

size_t			p_atoi(const char *str);
void			*p_memcpy(void *dest, const void *src, size_t n);
int				p_error(char *msg);
size_t			p_strlen(const char *str);

// init_info.c
t_info			*make_info_struct(int argc, char *argv[]);
int				init_info_argv(int argc, char *argv[], t_info *info);
int				setting_struct(t_info *info);
int				check_argv(t_info *info);
int				philo_init_input(t_info *info);

// monitor.c
int				monitor(t_info *info);

// philo_action.c
void			grab_fork(t_info *info, t_philo *p);
void			put_down_fork(t_info *info, t_philo *p);
void			philo_eat(t_info *info, t_philo *p);
void			philo_sleep(t_info *info, t_philo *p);
void			philo_think(t_info *info, t_philo *p);

// philo_thread.c
int				philo_create_thread(t_info *info);
int				philo_collect_all_thread(t_info *info);

// philo_run.c
void			*philo_run(void *arg);
int				day_running_check_die(int die, t_philo *p);
int				day_running_check_eat_all(int eat_all, t_philo *p);
void			philo_day_running(t_philo *p);

// time.c
struct timeval	check_curr_time(t_info *info);
void			custom_usleep_timer(struct timeval *start, int input_time);
int				time_gap(struct timeval start_time, struct timeval end_time);

//voice.c
int				get_flag_philo_dead(t_info *info);
void			set_flag_philo_dead(t_info *info);
void			voice(enum e_state state, t_info *info, t_philo *p);

//philo_end.c
void			destroy_info_mutex1(t_info *info);
void			end_philo(t_info *info);
#endif
