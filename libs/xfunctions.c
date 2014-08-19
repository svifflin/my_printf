#include	"../my_printf.h"

void		*xmalloc(size_t size)
{
  void		*ptr;

  if ((ptr = malloc(size)) != NULL)
    return (ptr);
  my_printf("Insufficient memory\n");
  exit(EXIT_FAILURE);
}
