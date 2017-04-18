/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 19:31:26 by lwang             #+#    #+#             */
/*   Updated: 2017/04/06 19:31:31 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H

# include <dirent.h>
# include <stdio.h>
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>

#define FLAG_A 1
#define FLAG_R 2
#define FLAG_CAP_R 4
#define FLAG_T 8
#define FLAG_L 16
#define FLAG_ONE 32
#define FLAG_F 64
#define FLAG_N 128
#define FLAG_U 256

typedef struct	s_linfo
{
	// t_list *path;
	t_list *invalid;
	t_list *file;
	t_list *directory;
	int flag;
	int count;
}				t_linfo;

// typedef	struct		s_list
// {
// 	struct dirent	*dir;
// 	size_t			dir_size;
// 	struct s_list	*next;
// }					t_list;

// struct node
// {
//     int data;
//     struct node* next;
// };

// t_list *f (t_list *a, t_list *b);

t_list *sorted_merge(t_list *a, t_list *b);
t_list *sorted_merge_r_dir(t_list *a, t_list *b);
t_list *sorted_merge_a_dir(t_list *a, t_list *b);
t_list *sorted_merge_file(t_list *a, t_list *b);

void front_back_split(t_list *source, t_list **frontref, t_list **backref);
void merge_sort(t_list **headref, t_list *(*f)(t_list *, t_list *));


int	list_directory(char *path, int len, t_linfo *info);
void	get_lst(struct dirent *dir, t_list **all_lst, t_list **dir_lst, char *path);
char	*get_path(char *path, char *name);
void	lst_print_all_color(t_list *lst, char *path, t_linfo *info);
char	*add_path(char *dname, char *path);

#endif