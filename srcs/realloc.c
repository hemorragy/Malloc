/*
** realloc.c for realloc in /home/antoin_g/rendu/Unix/PSU_2016_malloc/srcs
**
** Made by Loïs Antoine
** Login   <antoin_g@pc-antoin_g>
**
** Started on  Fri Feb 10 18:14:53 2017 Loïs Antoine
** Last update Sun Feb 12 14:58:59 2017 Loïs Antoine
*/

#include <string.h>
#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
  void		*new;
  t_block	*block;

  if (!size)
    return (NULL);
  if (!(new = malloc(size)))
    {
      if (size)
	free(ptr);
      return (NULL);
    }
  if (!ptr)
    return (new);
  block = (void *)ptr - sizeof(*block);
  new = memcpy(new, ptr, (size < block->size) ? size : block->size);
  free(ptr);
  return (new);
}
