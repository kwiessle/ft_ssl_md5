/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:18:21 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/13 10:43:57 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H



typedef struct          s_input
{
    char        *message;
    size_t      len;
}                       t_input;



typedef struct          s_md5
{
    t_input          *input;
    uint8_t          *data;
    uint64_t         encoded_len;
    uint32_t         w[16];
    uint32_t         a;
    uint32_t         b;
    uint32_t         c;
    uint32_t         d;
    uint32_t         f;
    uint32_t         g;
    uint32_t         h0;
    uint32_t         h1;
    uint32_t         h2;
    uint32_t         h3;

}                       t_md5;

typedef struct          s_sha256
{
    t_input         *input;
    uint8_t         *data;
    uint64_t        encoded_len;
    uint32_t        current[16];
    uint32_t        w[64];
    uint32_t        h0;
    uint32_t        h1;
    uint32_t        h2;
    uint32_t        h3;
    uint32_t        h4;
    uint32_t        h5;
    uint32_t        h6;
    uint32_t        h7;
    uint32_t         a;
    uint32_t         b;
    uint32_t         c;
    uint32_t         d;
    uint32_t         e;
    uint32_t         f;
    uint32_t         g;
    uint32_t         h;
    uint32_t        s0;
    uint32_t        s1;
    uint32_t        ch;
    uint32_t        maj;
}                       t_sha256;






#endif
