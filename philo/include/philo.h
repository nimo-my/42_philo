/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:18:43 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/05 12:19:42 by jisookim         ###   ########.fr       */
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
# define RET_ERROR	1

// typedef pthread_mutex_t p_mutex;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	void			*info_struct;





}					t_philo;


typedef struct s_info
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat; // if argv == 6 only

	t_philo				*philos;

	int					*permit_fork; // default all 1
	pthread_t			*t_id_arr; // 나중에 스레드 만들면서 넣어줄 것임! 
	pthread_mutex_t		*m_fork_arr; // 뮤텍스는 공유자원
	pthread_mutex_t		*m_print_arr; // 뮤텍스는 공유자원

}						t_info;

/* ************************************************************************** */
// 	p_func
/* ************************************************************************** */

size_t	p_atoi(const char *str);
char	*p_malloc(size_t size);
char	**p_double_malloc(size_t size);
void	*p_memset(void *b, int c, size_t len);
void	*p_memcpy(void *dest, const void *src, size_t n);

/* ************************************************************************** */
// 	src
/* ************************************************************************** */

// init_info.c
t_info	*make_info_struct(int argc, char *argv[]);
void	init_info_input(int argc, char *argv[], t_info *info);
void	init_info_arr(t_info *info);
int		set_info_and_return(int argc, t_info *info); 

// init_philo.c
t_philo	*init_philo(t_info *info);
void	make_philos(t_info *info);



// fork.c
// void	pickup_forks(t_info info, t_philo philo);
// void	return_forks(int philo->id);


//philo.c
void	*even_philo(void *arg);
void	*odd_philo(void *arg);

//print.c
void	print(char *message);

#endif
