/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiefer <kiefer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:14:07 by kiefer            #+#    #+#             */
/*   Updated: 2018/08/13 20:11:49 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"



t_input *input_init(char *message)
{
    t_input *new;

    if (!(new = malloc(sizeof(t_input))))
        return NULL;
    new->message = message;
    new->len = ft_strlen(message) * 8;

    return new;
}

char    *get_input(int fd)
{
    char    buf;
    char    *input;

    if (!(input = malloc(sizeof(char))))
        return NULL;
    while (read(fd, &buf, sizeof(buf)) > 0)
        input = ft_strappend(input, buf);

    return (input);
}

size_t      get_padding_size(size_t len, int modulo, size_t congruent)
{
    size_t result;

    result = len % modulo;

    if (result >= congruent)
        return (modulo + congruent) - result;
    return congruent - result;
}

int         little_endian(uint32_t h)
{
    int b0, b1, b2, b3;
    b0 = (h & 0x000000FF) >> 0;
    b1 = (h & 0x0000FF00) >> 8;
    b2 = (h & 0x00FF0000) >> 16;
    b3 = (h & 0xFF000000) >> 24;
    return b0 << 24 | b1 << 16 | b2 << 8 | b3 << 0;
}


void        throw_error(char *err, char *desc)
{
    ft_putstr("Error : ");
    ft_putstr(err);
    ft_putchar(' ');
    ft_putstr(desc);
    ft_putchar('\n');
}
