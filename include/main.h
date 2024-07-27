/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:11:02 by ychng             #+#    #+#             */
/*   Updated: 2024/07/27 22:44:02 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "system.h"
# include "libft.h"
# include "mlx.h"

# define KEY_COUNT 65536

# define PASS true
# define FAIL false

# define M_WALL '1'
# define M_PATH '0'
# define M_NORTH 'N'

# define M_SCALE_FACTOR 0.3
# define TILE_SIZE 32
# define PLAYER_SIZE 4
# define LINE_LENGTH 1500

# define PI 3.141593
# define EPSILON 0.00001

# define UBUNTU_ESC 65307
# define UBUNTU_UP_ARROW 65362
# define UBUNTU_DOWN_ARROW 65364
# define UBUNTU_LEFT_ARROW 65361
# define UBUNTU_RIGHT_ARROW 65363

# define UBUNTU_A_KEY 97
# define UBUNTU_D_KEY 100
# define UBUNTU_W_KEY 119
# define UBUNTU_S_KEY 115

typedef struct	s_mapinfo
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_testure;
	int		floorcolor[3];
	int		ceilingcolor[3];
	bool	is_north_texture_set;
	bool	is_south_texture_set;
	bool	is_east_texture_set;
	bool	is_west_texture_set;
	bool	is_floorcolor_set;
	bool	is_ceilingcolor_set;
}	t_mapinfo;

typedef struct	s_mapdata
{
	int		rows;
	int		cols;
	char	**map2d;
	int		m_width;
	int		m_height;
}	t_mapdata;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		stride;
	int		endian;
}	t_image;

typedef struct	s_minilibx
{
	void	*mlx;
	void	*win;
	t_image	image;
}	t_minilibx;

typedef struct	s_player
{
	double		center_x;
	double		center_y;
	double		topleft_x;
	double		topleft_y;
	double		rotation_angle;
	double		rotation_speed;
	double		move_speed;
}	t_player;

typedef struct	s_impact
{
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;
	double	next_x;
	double	next_y;
	double	wall_hit_x;
	double	wall_hit_y;
	bool	found_wall_hit;
}	t_impact;

typedef struct	s_ray
{
	int			columnid;
	double		ray_angle;
	bool		is_facing_up;
	bool		is_facing_down;
	bool		is_facing_left;
	bool		is_facing_right;
	t_impact	horz;
	t_impact	vert;
	double		wall_hit_x;
	double		wall_hit_y;
	double		distance;
	bool		was_hit_vert;
}	t_ray;

typedef struct	s_raycast
{
	double	fov_angle;
	int		wall_strip_width;
	int		wall_strip_height;
	int		num_of_rays;
	t_ray	*rays;
	double	correct_wall_dist;
}	t_raycast;

typedef struct	s_main
{
	t_mapinfo	mapinfo;
	t_mapdata	mapdata;
	t_minilibx	minilibx;
	t_player	player;
	t_raycast	raycast;
	int			key_states[KEY_COUNT];
}	t_main;

typedef struct	s_points
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_points;

typedef struct	s_dda
{
	long long	delta_x;
	long long	delta_y;
	long long	side_len;
	double		x_inc;
	double		y_inc;
	double		curr_x;
	double		curr_y;
}	t_dda;


// get_nextline/
bool	contains_newline(char *remaining_line);
int		read_and_check(int fd, char *buffer, int buffer_size);
char	*get_next_line(int fd);

// error_output/
void	exit_with_error(char *msg);
bool	return_with_error(char *msg);

// initialize_struct/
void	init_minilibx(t_minilibx *minilibx);
void	init_main(t_main *main);

// parse_map/
bool	extension_is_cub(char *mapname);
bool	set_direction_texture(t_mapinfo *mapinfo, char *token);
bool	set_color(t_mapinfo *mapinfo, char *token);
bool	meets_required_info(t_mapinfo *mapinfo, int fd);
int		get_max_cols(t_mapdata *mapdata);
bool	pad_2d_map(t_mapdata *mapdata);
bool	parse_data(t_main *main, int fd);
bool	validate_top_and_bottom_border(t_mapdata *mapdata);
bool	validate_left_and_right_border(t_mapdata *mapdata);
bool	validate_rows(t_mapdata *mapdata);
bool	validate_cols(t_mapdata *mapdata);
bool	validate_2d_map(t_mapdata *mapdata);
bool	meets_required_data(t_main *main, int fd);
void	parse_map(t_main *main, char *mapname);

// set_minilibx_properties
void	set_minilibx_properties(t_main *main);

// set_player_properties
void	set_player_topleft(t_main *main);
void	set_initial_position(t_main *main);
void	set_initial_movement(t_main *main);
void	set_player_properties(t_main *main);

// set_raycast_properties
void	set_raycast_properties(t_main *main);

// is_within_bounds.c
bool	is_within_win_bounds(t_main *main, int x, int y);
bool	is_within_2dmap_bounds(t_main *main, double x, double y);

// keystates/
bool	has_wall_at(t_main *main, double x, double y);
void	rotate_player(t_main *main, int turn_direction);
void	move_forward_backward(t_main *main, int walk_direction);
void	move_left_right(t_main *main, int side_direction);
int		key_press(int keycode, t_main *main);
int		key_release(int keycode, t_main *main);
void	apply_keystates(t_main *main);

// render_frame/
int		rgb(int r, int g, int b);
void	pixel_put(t_image *image, int x, int y, int color);
void	dda(t_main *main, t_points *points);
void	draw_map(t_main *main);
void	draw_player(t_main *main);
int		render_frame(void *main);

// cast_rays/
double	normalized_angle(double angle);
bool	is_ray_facing_down(double angle);
bool	is_ray_facing_right(double angle);
bool	is_close_to(double value, double target);
void	set_rays_angle(t_main *main);
void	set_horz_intersection(t_main *main, int i);
void	set_horz_wall_hit(t_main *main, int i);
void	set_vert_intersection(t_main *main, int i);
void	set_vert_wall_hit(t_main *main, int i);
void	set_horz_impact(t_main *main, int i);
void	set_vert_impact(t_main *main, int i);
void	set_closest_impact(t_main *main, int i);
void	set_rays_properties(t_main *main);

// draw_rays/
void	draw_rays(t_main *main);

// draw_walls/
int		find_color(int color[3]);
void	draw_walls(t_main *main);

#endif
