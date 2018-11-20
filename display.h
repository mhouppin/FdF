/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 11:55:56 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 12:43:38 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "libft/libft.h"

void				print_usage(char *filename);

void				print_error(int errval);

void				assert_error(int condition, int errval);

# define NO_FILE		0
# define NO_NUMBER		1
# define MALLOC_FAIL	2
# define ATOL_FAIL		3
# define UNKNOWN_PARAM	4
# define COLSET_ZERO	5
# define COLSET_INV		6
# define INIT_FAIL		7
# define WIN_FAIL		8

#endif
