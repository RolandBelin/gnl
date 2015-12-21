/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 07:53:58 by r§belin            #+#    #+#             */
/*   Updated: 2015/12/07 17:21:06 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define GNL_MAX_BUFF_SIZE 9999

/* Si BUFF_SIZE n'est pas defini, on l'affecte.
 * Question de stabilite, si dans mes futures projet je define un BUFF_SIZE
 * ca serais bien que get_next_line ne le modifie pas derriere, au quel cas je
 * devrais modifier le header de get_next_line pour chaque modification apporte
 * au BUFF_SIZE au lieu de modifier les fichier de l'eventuel projet.
*/ 
# ifndef BUFF_SIZE
#  define BUFF_SIZE 32

/* Si BUFF_SIZE est supperieur a GNL_MAX_BUFF_SIZE qui est la taille maximum
 * d'un buffer, on redefini BUFF_SIZE.
*/
#  if BUFF_SIZE > GNL_MAX_BUFF_SIZE
#   undef BUFF_SIZE
#   define BUFF_SIZE GNL_MAX_BUFF_SIZE
#  endif
# endif

int		get_next_line(const int fd, char **line);

#endif
