#include	"my_printf.h"

void		var_o(va_list *list, t_struct *st)
{
  char		*o;

  o = my_itoa_base(va_arg(*list, unsigned int), BASE_8);
  manager_buffer(st, o, -1);
  free(o);
}

void		var_u(va_list *list, t_struct *st)
{
  char		*o;

  o = my_utoa(va_arg(*list, unsigned int));
  manager_buffer(st, o, -1);
  free(o);
}

void		var_x(va_list *list, t_struct *st)
{
  char		*x;

  x = my_itoa_base(va_arg(*list, unsigned int), BASE_16_MIN);
  manager_buffer(st, x, -1);
  free(x);
}

void		var_xx(va_list *list, t_struct *st)
{
  char		*x;

  x = my_itoa_base(va_arg(*list, unsigned int), BASE_16_CAP);
  manager_buffer(st, x, -1);
  free(x);
}
