#include	"my_printf.h"

void		var_s(va_list *list, t_struct *st)
{
  char		*s;

  s = va_arg(*list, char *);
  manager_buffer(st, s, -1);
}

void		var_c(va_list *list, t_struct *st)
{
  char		c[2];

  c[0] = (char)va_arg(*list, int);
  c[1] = 0;
  manager_buffer(st, (char *)c, -1);
}

void		var_i(va_list *list, t_struct *st)
{
  char		*i;

  i = my_itoa(va_arg(*list, int));
  manager_buffer(st, i, -1);
  free(i);
}

void		var_d(va_list *list, t_struct *st)
{
  char		*d;

  d = my_itoa(va_arg(*list, int));
  manager_buffer(st, d, -1);
  free(d);
}

void		var_percent(__attribute__((unused))va_list *list, t_struct *st)
{
  manager_buffer(st, "%", -1);
}
