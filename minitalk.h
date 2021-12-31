/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 22:26:28 by ylabtaim          #+#    #+#             */
/*   Updated: 2021/12/29 19:37:50 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_byte
{
	unsigned char	b1 :1;
	unsigned char	b2 :1;
	unsigned char	b3 :1;
	unsigned char	b4 :1;
	unsigned char	b5 :1;
	unsigned char	b6 :1;
	unsigned char	b7 :1;
	unsigned char	b8 :1;
}	t_byte;

#endif
