#include	<stdio.h>
#include	"my_printf.h"

static void	last_process(t_struct *st)
{
  if (st->size_str)
    {
      write_str(st->buffer, st->size_str);
      free(st->buffer);
    }
}

int		my_printf(char *txt, ...)
{
  t_struct	st;
  va_list	list;

  st.buffer = NULL;
  st.char_printed = 0;
  va_start(list, txt);
  main_process(&st, txt, &list);
  va_end(list);
  last_process(&st);
  return (st.char_printed ? st.char_printed : -1);
}
