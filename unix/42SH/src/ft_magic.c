/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:21:10 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 16:34:14 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>
#include <unistd.h>
#include <libft.h>
#include <ftsh.h>

static int	ft_magic_init(t_datas *datas)
{
	struct termios	sterm;
	struct termios	*dfl;

	ft_bzero(&sterm, sizeof(struct termios));
	if (isatty(STDIN_FILENO) == 0)
		return (1);
	dfl = ft_getterm(datas);
	if (dfl == NULL)
		return (1);
	ft_memmove(&sterm, dfl, sizeof(struct termios));
	sterm.c_lflag &= ~(ICANON | ECHO);
	sterm.c_lflag |= CREAD;
	sterm.c_cc[VMIN] = 1;
	sterm.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &sterm) == -1)
		return (1);
	return (0);
}

static void	ft_magic_put(t_datas *datas)
{
	if (FLAG_ISTERM(datas->flags))
	{
		ft_tputs("mr");
		ft_putchar('%');
		ft_tputs("me");
		ft_tputs("do");
	}
	else
		ft_putstr("%\n");
}

void		ft_magic(t_datas *datas)
{
	char			*tmp;
	char			buf[64];

	ft_bzero(buf, 64);
	if (ft_magic_init(datas) != 0)
		return ;
	ft_putstr("\033[6n");
	read(0, buf, 63);
	if (ft_strlen(buf) == 0)
	{
		ft_shell_end(datas);
		return ;
	}
	tmp = ft_strchr(buf, ';');
	if (tmp == NULL)
	{
		ft_shell_end(datas);
		return ;
	}
	if (ft_atoi(tmp + 1) > 1)
		ft_magic_put(datas);
	ft_shell_end(datas);
}
