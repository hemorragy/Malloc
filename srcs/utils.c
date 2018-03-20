/*
** split.c for split in /home/chouik_e/Tek/Tek2/PSU_2016_malloc/srcs
**
** Made by Eddy Chouikha
** Login   <chouik_e@chouik-e-pc>
**
** Started on  Wed Jan 25 17:55:44 2017 Eddy Chouikha
** Last update Sun Feb 12 14:41:30 2017 Loïs Antoine
*/

#include <unistd.h>
#include "malloc.h"

static int	my_strlen(const char *str)
{
  register int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

void	my_putchar(char a, int fd)
{
  write(fd, &a, 1);
}

void	my_putstr(const char *str, int fd)
{
  write(fd, str, my_strlen(str));
}

void	my_put_nbr(const char *str, int nb, int fd)
{
  long	a;

  my_putstr(str, fd);
  a = 1;
  while (a <= nb / 10)
    a = a * 10;
  while (a > 0)
    {
      my_putchar(nb / a % 10 + 48, fd);
      a = a / 10;
    }
}

void		my_pointnbr(const char *str, long nbr, int fd)
{
  unsigned long		div;
  unsigned long		size;
  static const char	base[] = EXA_BASE;

  my_putstr(str, fd);
  div = 1;
  size = my_strlen(base);
  my_putstr("0x", fd);
  while ((nbr / div) >= size)
    div = div * size;
  while (div > 0)
    {
      my_putchar(base[nbr / div % size], fd);
      div = div / size;
    }
}
