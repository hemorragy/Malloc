/*
** free.c for free in /home/antoin_g/rendu/Unix/PSU_2016_malloc/srcs
**
** Made by Loïs Antoine
** Login   <antoin_g@pc-antoin_g>
**
** Started on  Fri Feb 10 18:14:53 2017 Loïs Antoine
** Last update Sun Feb 12 14:40:33 2017 Loïs Antoine
*/

#include <unistd.h>
#include "malloc.h"

static void	merge_block(t_block *block)
{
  if (block->next && block->next->free)
    {
      if (block->next->next)
	block->next->next->prev = block;
      block->size = block->size + block->next->size + sizeof(*block);
      block->padded_size = block->size;
      if (block->next == g_last)
	g_last = block;
      block->next = block->next->next;
    }
  if (block->prev && block->prev->free)
    {
      if (block->next)
	block->next->prev = block->prev;
      block->prev->size = block->prev->size + block->size + sizeof(*block);
      block->prev->padded_size = block->prev->size;
      block->prev->next = block->next;
      if (block == g_last)
	g_last = block->prev;
    }
}

void		free(void *ptr)
{
  t_block	*block;

  if (!ptr)
    return ;
  block = g_last;
  while (block && (long)((long)block + sizeof(*block)) != (long)ptr)
    block = block->prev;
  if (!block)
    return ;
  block->free = 1;
  block->size = block->padded_size;
  merge_block(block);
  if (g_last && ((g_last->size >= PAGE_SIZE && g_last->free)
		 || (!g_last->prev && g_last->free)))
    {
      block = g_last;
      g_last = g_last->prev;
      if (g_last)
	g_last->next = NULL;
      brk(block);
    }
}
