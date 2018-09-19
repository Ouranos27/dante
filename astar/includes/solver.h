/*
** solver.h for dante in /home/amaury/delivery/dante/solver
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sat May 13 18:38:25 2017 Amaury Bernard
** Last update Sat May 13 18:38:25 2017 Amaury Bernard
*/

#ifndef SOLVER_H_
# define SOLVER_H_

# define MAX_PLACE	4
# define ERR_FATAL	84
# define ERR_NO_SOL	42
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

typedef struct		s_map
{
  char			**tab;
  t_co			max;
}			t_map;

typedef struct	s_radar
{
  t_co		*free_place;
  int		nb_free;
}		t_radar;

int		solver(t_map *map);

t_map		*map_filling(char *path);

void		update_radar(t_radar *to_up, const int x,
			     const int y, char **map);

t_lst_co	*add_to_stack(int x, int y, t_lst_co *stack);
t_lst_co	*back_in_stack(t_co *new_co, t_lst_co *stack);
void		free_stack(t_lst_co *stack);

#endif /* SOLVER_H_ */
