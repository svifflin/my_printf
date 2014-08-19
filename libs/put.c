#include	<stdio.h>
#include	<unistd.h>
#include	"../my_printf.h"

int		write_str(char *s, int len)
{
  int		i;

  i = write(1, s, len);
  return (i);
}

void		my_putstr(char *s)
{
  int		i;

  for (i = 0; s[i]; ++i)
    my_putchar(s[i]);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}
