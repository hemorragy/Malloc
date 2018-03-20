/*
** malloc.h for malloc in /home/antoin_g/rendu/Unix/PSU_2016_malloc
**
** Made by Loïs Antoine
** Login   <antoin_g@pc-antoin_g>
**
** Started on  Tue Jan 31 16:31:27 2017 Loïs Antoine
** Last update Sun Feb 12 14:41:13 2017 Loïs Antoine
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <stdlib.h>
# include <stdbool.h>

# define EXA_BASE "0123456789ABCDEF"
# define BREAK "break : "
# define POINT_SEP " - "
# define SIZE_SEP " : "
# define UNIT_SIZE " bytes\n"
# define PAGE_SIZE 1024
# define PADDING 8

typedef struct		s_block
{
  struct s_block	*prev;
  struct s_block	*next;
  size_t		size;
  size_t		padded_size;
  bool			free;
}			t_block;

t_block	*g_last;

void		*malloc(size_t);
void		*realloc(void *, size_t);
void		free();
void		show_alloc_mem();
size_t		power_more(size_t);
void		my_putchar(char, int);
void		my_putstr(const char *, int);
void		my_put_nbr(const char *, int, int);
void		my_pointnbr(const char *, long, int);

#endif /* !MALLOC_H_ */
