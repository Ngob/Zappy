/*
** str_fmt.c for  in /home/capot_r//tek2/c/zappy/serveursrc
** 
** Made by romain capot
** Login   <capot_r@epitech.net>
** 
** Started on  Thu Jul  7 10:16:27 2011 romain capot
** Last update Thu Jul  7 10:16:27 2011 romain capot
*/

#include	<stdarg.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"x.h"

char		*vstr_fmt(const char *fmt, va_list ap)
{
  char		*str;
  char		c;
  int		written;

  written = vsnprintf(&c, 0, fmt, ap);
  str = Xmalloc(written + 1);
  vsnprintf(str, written + 1, fmt, ap);
  return (str);
}

char		*str_fmt(const char *fmt, ...)
{
  va_list	ap;
  char		*str;

  va_start(ap, fmt);
  str = vstr_fmt(fmt, ap);
  va_end(ap);
  return (str);
}
