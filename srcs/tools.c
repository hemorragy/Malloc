/*
** tools.c for tools in /home/antoin_g/rendu/Unix/PSU_2016_malloc
**
** Made by Loïs Antoine
** Login   <antoin_g@pc-antoin_g>
**
** Started on  Sun Feb 12 04:56:19 2017 Loïs Antoine
** Last update Sun Feb 12 14:37:52 2017 Loïs Antoine
*/

#include <stdio.h>
#include "malloc.h"

size_t		power_more(size_t n)
{
  size_t	nb;

  if (!n)
    return (0);
  nb = 1;
  while (nb < n)
    nb = nb * 2;
  return (nb);
}

void		show_alloc_mem(void)
{
  t_block	*tmp;

  tmp = g_last;
  if (tmp)
    my_pointnbr(BREAK,
		(long)((void *)tmp + tmp->padded_size + sizeof(*tmp)), 1);
  else
    my_pointnbr(BREAK, (long)tmp, 1);
  my_putchar('\n', 1);
  while (tmp && tmp->prev)
    tmp = tmp->prev;
  while (tmp)
    {
      if (!tmp->free)
	{
	  my_pointnbr("", (long)(&tmp->free + 8), 1);
	  my_pointnbr(POINT_SEP,
		      (long)((void *)tmp + tmp->size + sizeof(*tmp)), 1);
	  my_put_nbr(SIZE_SEP, tmp->size, 1);
	  my_putstr(UNIT_SIZE, 1);
	}
	tmp = tmp->next;
    }
}
