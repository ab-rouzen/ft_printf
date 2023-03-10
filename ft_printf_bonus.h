/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:26:40 by arouzen           #+#    #+#             */
/*   Updated: 2022/12/19 16:43:16 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define FD 1
# include <unistd.h>
# include <stdarg.h>

void	ft_uputnbr_base(unsigned long int nb, char *base);
int		ft_printf(const char *str, ...);
void	ft_putnbr_base(long int nbr, char *base);
void	init(int *flags);
int		dflags(char *str, int *flags);

#endif
