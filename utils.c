/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:38:32 by arouzen           #+#    #+#             */
/*   Updated: 2022/12/19 16:38:38 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init(int *flags)
{
	int	i;

	i = 0;
	while (i < 3)
		flags[i++] = 0;
}

int	dflags(char *str, int *flags)
{
	int	i;

	i = 0;
	if (str[i] == ' ')
	{
		while (str[i + 1] == ' ')
			i++;
		flags[0] = 1;
	}
	else if (str[i] == '+')
	{
		while (str[i + 1] == '+')
			i++;
		flags[1] = 1;
	}
	else if (str[i] == '#')
	{
		while (str[i + 1] == '#')
			i++;
		flags[2] = 1;
	}
	return (++i);
}
