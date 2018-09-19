/*
** generator.h for dante in /home/amaury/delivery/dante/generator
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Tue May  9 14:15:56 2017 Amaury Bernard
** Last update Tue May  9 14:15:56 2017 Amaury Bernard
*/

#ifndef GENERATOR_H_
# define GENERATOR_H_

# define ERR_FATAL	84
# define MAX_PLACE	8
# define TRUE		1
# define FALSE		0

typedef struct	s_co
{
  int		x;
  int		y;
}		t_co;

typedef struct		s_lst_co
{
  t_co			co;
  struct s_lst_co	*prev;
}			t_lst_co;

typedef struct	s_radar
{
  t_co		*free_place;
  int		nb_free;
}		t_radar;

int		generator_imperfect(int x, int y, char **map);
int		generator_perfect(int x, int y, char **map);

t_lst_co	*add_to_stack(int x, int y, t_lst_co *stack);
t_lst_co	*back_in_stack(t_co *new_co, t_lst_co *stack);
void		free_stack(t_lst_co *stack);

void		update_radar(t_radar *to_up, const int x,
			     const int y, char **map);

int		my_str_isnum(char *str);

#endif /* GENERATOR_H_ */
