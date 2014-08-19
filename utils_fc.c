#include	<stdlib.h>
#include	<string.h>
#include	"my_printf.h"

int		copy_into_buf(t_struct *st, char *str, int n)
{
  n = my_strncat(st->buffer, str, n);
  st->char_printed += n;
  st->size_str += n;
  return (n);
}

void		init_buf(t_struct *st, char *str)
{
  if (st->buffer && (my_strlen(str) + st->size_str) < SIZE_BUF &&
      *(st->buffer) != '\n')
    return ;
  if ((st->buffer && *(st->buffer) == '\n') ||
      (st->size_str == SIZE_BUF))
    write_str(st->buffer, st->size_str);
  if (st->buffer && *st->buffer)
    free(st->buffer);
  st->buffer = xmalloc((SIZE_BUF + 1) * sizeof(*st->buffer));
  *(st->buffer) = '\0';
  st->size_str = 0;
}

void		manager_buffer(t_struct *st, char *str, int n)
{
  int		i;

  if (!n)
    return ;
  n = (n < 0 ? my_strlen(str) : n);
  for (i = 0; i < n; )
    {
      init_buf(st, str + i);
      if (SIZE_BUF > (n - i + st->size_str))
	i += copy_into_buf(st, str + i, n);
      else
	i += copy_into_buf(st, str + i, SIZE_BUF);
    }
}

int		get_pos_substring(__attribute__((unused))t_struct *st,
				  char *str, int old_pos)
{
  int		new_pos;
  char		*sub;
  char		*sub_key;
  char		*sub_flush;

  new_pos = old_pos;
  sub_key = strchr(str + old_pos, '%');
  sub_flush = strchr(str + old_pos, '\n');
  if (!sub_key && !sub_flush)
    return (my_strlen(str));
  if ((sub_flush && sub_key && (size_t)sub_flush < (size_t)sub_key) ||
      (sub_flush && !sub_key))
    sub = sub_flush;
  else
    sub = sub_key;
  new_pos = (sub ? (int)(sub - str) : my_strlen(str));
  return (new_pos);
}
