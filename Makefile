NAME			=	libmy_printf_`uname -m`-`uname -s`
my_printf_static	=	$(NAME).a
my_printf_dynamic	=	$(NAME).so

##
## DIRECTORY
##
LIBS			= 	./libs/

SRCS			=	my_printf.c		\
				variadique.c		\
				fc_var_scid.c		\
				fc_var_ouxx.c		\
				utils_fc.c		\
				$(LIBS)put.c		\
				$(LIBS)f_str.c		\
				$(LIBS)my_strcat.c	\
				$(LIBS)my_getnbr.c	\
				$(LIBS)my_strcpy.c	\
				$(LIBS)my_strdup.c	\
				$(LIBS)xfunctions.c
OBJS			=	$(SRCS:.c=.o)

AR			=	ar r
RANLIB			=	ranlib
CFLAGS			=	-fPIC -O2 -W -Wall -Wextra -pedantic -ansi -Wformat-nonliteral -Wpointer-arith -Wmissing-declarations -Winline -Wundef -Wcast-align -Wformat-security
CC			=	gcc
RM			=	rm -f

$(NAME)			: my_printf_static my_printf_dynamic

my_printf_dynamic	: $(OBJS)
			$(CC) -shared -o $(my_printf_dynamic) $(OBJS)

my_printf_static	: $(OBJS)
			$(AR) $(my_printf_static) $(OBJS)
			$(RANLIB) $(my_printf_static)

all			: $(NAME)

clean			:
			$(RM) $(OBJS) *~ *#

fclean			: clean
			$(RM) $(my_printf_static) $(my_printf_dynamic)

re			: fclean all
