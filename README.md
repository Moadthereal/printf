*This project has been created as part of the 42 curriculum by majnaou.*

# ft_printf

## Description

This projcet is the second project in the common core , The goal of this project is to recode printf(), and learn about using a `variadic functions` .

    what do you mean with variadic functions?

`variadic function`: is a function that can receive a variable of number of arguments.

so printf is a variadic function because can receive a variable of number of argument , for example :

```c 
printf("hello %s today is %d\%d\%d", "World", 11, 11, 2026);
```
to define a variadic functions u need to use an ellipsis `(...)` as the last parameter in the function declaration.

``` c
    example :
    int ft_printf(const char *format, ...);
```

To access these additional arguments, C provides the <stdarg.h> library, which contains the following macros:

* va_list: declares a variable used to access the arguments.

* va_start: initializes the argument list.

* va_arg: retrieves the next argument.

* va_end: ends the use of the argument list.
## Instructions 


To test this project use :
``` bash
- git clone   git@vogsphere-v2.1337.ma:vogsphere/intra-uuid-89adc21b-a23a-4b59-b1f7-59cdf6829ed1-7790408-majnaou ft_pritf
- cd ft_printf
- make 
- cc -Wall -Wextra -Werror  main.c libft_printf.a -o test 
- ./test
```
## Resources

- [simple video about variadic functions](https://www.youtube.com/watch?v=7Sph8JlRo0g)
- [notion page](https://app.notion.com/p/ft_printf-40a38d79bbd880cdb67bebdcd1e13bfb)

### AI usage
- I use AI to find information quickly, but understanding the concepts and debugging the code are my own responsibilities.

### chosen algorithm 

#### Format string character by character

so for example  i have this input :
``` c 
ft_printf("Hello %s, age = %d\n", mouad, 22);
```
so my algorithm goes through the format string character by character :

    H -> normal character : print it
    e -> normal character : print it 
    l -> normal character : print it 
    l -> normal character : print it 
    o -> normal character : print it 
    space -> normal character : print it 
    % -> conversion starts
        so i pass to function print_format the next charcter.
    s -> get a string argument -> print it
    ...
    d -> get an integer arguent -> print it


so my alogorithm is simple is scans the format string and handles each character according to whether it is a normal character or a format conversion.
``` c
%d && %i
 ↓
va_arg(ap, int)
 ↓
get integer
 ↓
convert integer into decimal representation
 ↓
print digits
```
```c
%x
 ↓
va_arg(ap, unsigned int)
 ↓
convert number to base 16
 ↓
print hexadecimal digits
```
``` c
%s
 ↓
va_arg(ap, char *)
 ↓
get pointer to string
 ↓
print characters until '\0'
```
``` c
   %p
    ↓
va_arg(ap, void *)
    ↓
 get adrees of void *
    ↓
 cast to unsigned long
    ↓
 print hexadecimal digit
```
#### The justification 

i chose a parsing algorithm because `ft_printf` reads the format string from left to right. each character is handled in the order it appears. this makes the code simple, clear, and suitable for handling the different conversion specifiers and their arguments.










