/*
** malloc.c for malloc in /home/antoin_g/rendu/Unix/PSU_2016_malloc
**
** Made by Loïs Antoine
** Login   <antoin_g@pc-antoin_g>
**
** Started on  Tue Jan 31 16:33:55 2017 Loïs Antoine
** Last update Sun Feb 12 14:40:08 2017 Loïs Antoine
*/

#include <unistd.h>
#include <string.h>
#include "malloc.h"

t_block	*g_last = NULL;

static void		split_block(t_block *block, size_t size)
{
  t_block	*new;
  size_t	new_size;

  new_size = power_more(size);
  new = (void *)block + sizeof(*new) + new_size;
  new->next = block->next;
  new->prev = block;
  block->next = new;
  if (new->next)
    new->next->prev = new;
  new->padded_size = block->size - sizeof(t_block) - new_size;
  new->size = new->padded_size;
  block->padded_size = new_size;
  block->size = size;
  block->free = 0;
  new->free = 1;
  if (block == g_last)
    g_last = new;
}

static void		*find_empty_space(size_t size)
{
  t_block	*tmp;
  t_block	*ret;

  tmp = g_last;
  ret = NULL;
  while (tmp)
    {
      if (tmp->size >= power_more(size) + sizeof(*tmp) && tmp->free == 1)
	ret = tmp;
      tmp = tmp->prev;
    }
  return (ret);
}

static void		set_sizes(size_t size, t_block *new)
{
  if (power_more(size) < PAGE_SIZE)
    {
      new->size = PAGE_SIZE;
      new->padded_size = PAGE_SIZE;
      split_block(new, size);
      g_last = new->next;
    }
  else
    {
      new->padded_size = power_more(size);
      new->size = size;
      g_last = new;
    }
}

static void		*add_new_space(size_t size)
{
  t_block	*new;
  size_t	block;

  block = (size <= PAGE_SIZE) ? PAGE_SIZE + sizeof(*new)
    : power_more(size) + sizeof(*new);
  if ((new = sbrk(block)) == (void *) -1)
    return (NULL);
  new->prev = g_last;
  if (g_last)
    g_last->next = new;
  new->next = NULL;
  set_sizes(size, new);
  new->free = 0;
  return (new);
}

void		*malloc(size_t size)
{
  t_block	*new;

  if (g_last && (new = find_empty_space(size)))
    split_block(new, size);
  else
    new = add_new_space(size);
  if (new)
    return (&new->free + PADDING);
  return (NULL);
}
