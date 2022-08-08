/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:18:43 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/08 10:58:35 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h> // gettimeofday
# include <unistd.h>
# include <stdio.h> // printf
# include <stdbool.h>
// #include <string.h> // for debug

# define ERROR		0
# define OK			1
# define RET_ERROR	-1

// typedef pthread_mutex_t p_mutex;

typedef struct s_philo
{
	struct s_info	*go_info;

	int				id;				// init in set_info_struct
	int				left_fork;
	int				right_fork;
	int				eat_count;

	long	eat_time;
	long	sleep_time;
	long	starve_time;

	long	check_start;
	long	check_end;

	struct	timeval	limit_time_start;
	struct	timeval	limit_time_end;

}					t_philo;


typedef struct s_info
{
	struct	timeval 	start_time;
	struct	timeval 	end_time;

	

	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_think;
	int	time_to_sleep;
	int	num_must_eat; // if argv == 6 only

	size_t				count;
	t_philo				*philos;
	pthread_t			*t_id_arr; // init in set_info_struct
	int					*permit_fork; // default all 1, init in set_info_struct
	pthread_mutex_t		*m_fork_arr; // init in set_info_struct
	pthread_mutex_t		m_print; // 

}						t_info;

/* ************************************************************************** */
// 	p_func
/* ************************************************************************** */

size_t	p_atoi(const char *str);
char	*p_malloc(size_t size);
void	*p_memset(void *b, int c, size_t len);
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
int	pick_left_fork(t_philo *this_philo);
int	pick_right_fork(t_philo *this_philo);

// philo_do.c
int philo_eat(t_philo *philo, long *start_time, long *end_time);
int	philo_sleep(t_philo *philo, long *start_time, long *end_time);


// philo_time.c
int	set_time(struct timeval time);

//philo_init.c
int		make_philos(t_info *info);
void	init_philo(t_info *info);
void	*philos_eat(void *arg);
int		philo_run(t_philo *philo);

//print.c
void	print(char *message, t_info info);

#endif
