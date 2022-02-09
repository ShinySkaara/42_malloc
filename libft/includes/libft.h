/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:12:26 by alalonzo          #+#    #+#             */
/*   Updated: 2021/04/09 12:04:21 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void			ft_hexdump(void *data, size_t size);
int				ft_indexof(char *s, int c);
int				ft_isspace(int c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memrev(void *m, size_t size);
void			*ft_memset(void *s, int c, size_t len);
int				ft_numlen(unsigned int n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_stralloc(size_t n);
int				ft_strcasecmp(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strchrnul(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
char			*ft_strlwr(char *s);
int				ft_strncasecmp(const char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *s);
char			*ft_strupr(char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
