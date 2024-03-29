/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:51:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/02/20 19:00:47 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>

int		ft_isalpha(int num);
int		ft_isalnum(int num);
int		ft_isdigit(int num);
int		ft_isprint(int num);
int		ft_tolower(int num);
int		ft_toupper(int num);
size_t	ft_strlen(const char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int num);
int		ft_isascii(int num);
char	*ft_strdup(const char *str1);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, int num);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	num_send(int pid, int len);
void	ft_putchar_fd(char c, int fd);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
#endif
