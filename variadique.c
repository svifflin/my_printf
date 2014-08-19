#include	"my_printf.h"

t_var_args	g_var_args[] =
{
  {'s', var_s},
  {'c', var_c},
  {'i', var_i},
  {'d', var_d},
  {'o', var_o},
  {'u', var_u},
  {'x', var_x},
  {'X', var_xx},
  {'%', var_percent},
  {0, 0}
};

static void	call_select_var(t_struct *st, va_list *list, char *str,
				int *pos)
{
  int		i;

  if (str[*pos] == '\n')
    copy_into_buf(st, "\n", 1);
  if (str[(*pos)++] != '%')
    return;
  for (i = 0; g_var_args[i].sym && g_var_args[i].sym != str[(*pos)]; i++);
  if (!g_var_args[i].sym)
    return ;
  g_var_args[i].f(list, st);
  ++(*pos);
}

void		main_process(t_struct *st, char *txt, va_list *list)
{
  int		old_pos;
  int		new_pos;
  int		size_str;

  init_buf(st, txt);
  size_str = my_strlen(txt);
  for (old_pos = 0; old_pos < size_str; old_pos = new_pos)
    {
      new_pos = get_pos_substring(st, txt, old_pos);
      manager_buffer(st, txt + old_pos, new_pos - old_pos);
      call_select_var(st, list, txt, &new_pos);
    }
}
