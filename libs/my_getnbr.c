#include	"../my_printf.h"

char		*my_itoa(int i)
{
  int		sizeofint;
  int		i_size;
  char		*nb;
  char		flag;

  sizeofint = (i < 0 ? 1 : 0);
  flag = (sizeofint ? '-' : ' ');
  i *= (sizeofint ? -1 : 1);
  i_size = i;
  while (i_size > 0)
    {
      i_size /= 10;
      ++sizeofint;
    }
  nb = xmalloc(sizeofint * sizeof(*nb));
  while (i > 0)
    {
      --sizeofint;
      nb[sizeofint] = i % 10 + '0';
      i /= 10;
    }
  if (flag == '-')
    nb[0] = flag;
  return (nb);
}

char		*my_utoa(unsigned int i)
{
  int		sizeofint;
  unsigned int	i_size;
  char		*nb;

  sizeofint = 0;
  i_size = i;
  while (i_size >= 1)
    {
      i_size /= 10;
      ++sizeofint;
    }
  nb = xmalloc(sizeofint * sizeof(*nb));
  while (i >= 1)
    {
      --sizeofint;
      nb[sizeofint] = i % 10 + '0';
      i /= 10;
    }
  return (nb);
}

char		*my_itoa_base(unsigned int i, char *base)
{
  int		base_len;
  char		*p;
  char		*ptr;
  char		buffer[32];

  my_bzero(buffer, '\0', 32);
  if (!i)
    return ("0");
  base_len = my_strlen(base);
  for (ptr = buffer + 31; i > 0; i /= base_len)
    {
      --ptr;
      *ptr = base[i % base_len];
    }
  p = my_strdup(ptr);
  return (p);
}
/*
void		my_putnbr_base_unsigned(unsigned int nb, char *base, int *nb_write)
{
  int		len;
  int		mod;
  int		nbr;

  nbr = 0;
  len = my_strlen(base);
  mod = nb % len;
  nbr = (nb - mod) / len;
  if (nbr)
    my_putnbr_base_unsigned(nbr, base, nb_write);
  my_putchar(base[mod], nb_write);
}
*/
