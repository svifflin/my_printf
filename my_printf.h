#include	<stdlib.h>
#include	<unistd.h>
#include	<stdarg.h>

#ifndef		_MY_PRINTF_H_
# define	_MY_PRINTF_H_

# define	SIZE_BUF	4096
# define	BASE_16_MIN	"0123456789abcdef"
# define	BASE_16_CAP	"0123456789ABCDEF"
# define	BASE_8		"01234567"
# define	BASE_2		"01"

typedef struct	s_struct
{
  int		char_printed;
  int		size_str;
  char		*buffer;
}		t_struct;

typedef struct	s_var_args
{
  char		sym;
  void		(*f)(va_list *, t_struct *);
}		t_var_args;

int		my_printf(char *, ...);
void		main_process(t_struct *, char *, va_list *);
void		manager_buffer(t_struct *, char *, int);
void		init_buf(t_struct *, char *);
int		copy_into_buf(t_struct *, char *, int);

/*
** FC VAR
*/

void		var_s(va_list *, t_struct *);
void		var_c(va_list *, t_struct *);
void		var_i(va_list *, t_struct *);
void		var_d(va_list *, t_struct *);
void		var_o(va_list *, t_struct *);
void		var_u(va_list *, t_struct *);
void		var_x(va_list *, t_struct *);
void		var_xx(va_list *, t_struct *);
void		var_percent(va_list *, t_struct *);

/*
** UTILS FC
*/

int		get_pos_substring(t_struct *, char *, int);

/*
** LIBS
*/

int		write_str(char *, int);
void		my_putstr(char *);
void		my_putchar(char);
char		*my_itoa(int);
char		*my_utoa(unsigned int);
char		*my_itoa_base(unsigned int, char *);
int		my_strlen(char *);
void		my_bzero(char *, int, char);
char		*my_strcat(char *, char *);
int		my_strncat(char *, char *, int);
char		*my_strcpy(char *, char *);
char		*my_strdup(char *);

/*
** XFUNCTIONS
*/

void		*xmalloc(size_t);

#endif
