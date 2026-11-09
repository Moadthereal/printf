#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdio.h>//--> just for debuging <--
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>//INT_MAX



#define DECIMAL_BASE ("0123456789")
#define HEXA_LOWER ("0123456789abcdef")
#define HEXA_UPEER ("0123456789ABCDEF")



void	ft_print_all(char **format, va_list *ap, int *count);
int	print_char(int c);
int print_digit(long digit, int base, char *b);
int	print_format(char format, va_list ap);
int	print_str(char *s);
int print_void(void *n, int base, char *b);
int print_u(unsigned int digit, int base, char *b);








#endif
