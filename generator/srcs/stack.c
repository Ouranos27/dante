/*
** stack.c for dante in /home/amaury/delivery/dante/generator
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sat May 13 10:48:52 2017 Amaury Bernard
** Last update Sat May 13 10:48:52 2017 Amaury Bernard
*/

#include <stdlib.h>
#include "generator.h"

t_lst_co	*add_to_stack(int x, int y, t_lst_co *stack)
{
  t_lst_co	*new;

  if (!(new = malloc(sizeof(t_lst_co))))
    return (NULL);
  new->prev = stack;
  new->co.x = x;
  new->co.y = y;
  return (new);
}

t_lst_co	*back_in_stack(t_co *new_co, t_lst_co *stack)
{
  t_lst_co	*to_free;

  if (stack == NULL || stack->prev == NULL)
    return (0);
  to_free = stack;
  stack = stack->prev;
  free(to_free);
  new_co->x = stack->co.x;
  new_co->y = stack->co.y;
  to_free = stack;
  stack = stack->prev;
  free(to_free);
  return (stack);
}

void		free_stack(t_lst_co *stack)
{
  t_lst_co	*to_free;

  while (stack != NULL)
    {
      to_free = stack;
      stack = stack->prev;
      free(to_free);
    }
}
