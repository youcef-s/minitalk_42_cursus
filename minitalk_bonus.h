/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 22:26:28 by ylabtaim          #+#    #+#             */
/*   Updated: 2021/12/29 20:01:32 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
