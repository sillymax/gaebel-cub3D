/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:43:34 by ychng             #+#    #+#             */
/*   Updated: 2024/06/25 15:00:07by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.h"

# define ERROR -1
# define SUCCESS 0
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define TILE_SIZE 20

typedef struct s_data
{
	char			*north_texture;
	char			*south_texture;
	char			*west_testure;
	char			*east_texture;
	unsigned short	floorcolor[3];
	unsigned short	ceilingcolor[3];
	bool			is_width_set;
	bool			is_height_set;
	bool			is_north_texture_set;
	bool			is_south_texture_set;
	bool			is_west_texture_set;
	bool			is_east_texture_set;
	bool			is_floorcolor_set;
	bool			is_ceilingcolor_set;
}	t_data;

typedef struct s_player
{
	size_t	x;
	size_t	y;
	size_t	keys[255];
}	t_player;

typedef struct s_map
{
	size_t		used_rows;
	size_t		alloc_rows;
	char		**map2d;
	t_player	player;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_img	data;
}	t_var;

typedef struct s_main
{
	t_data	data;
	t_map	map;
	t_var	var;
}	t_main;

int	error_with_message(char	*msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchr_fd('\n', 2);
	return (ERROR);
}

void	exit_with_message(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchr_fd('\n', 2);
	exit(-1);
}

bool	extension_is_cub(char *mapname)
{
	size_t	count;
	char	*token;

	count = 0;
	token = ft_strdup(mapname);
	token = ft_strtok(token, ".");
	while (!(token == NULL))
	{
		if (ft_strcmp(token, "cub") == 0)
			count++;
		token = ft_strtok(NULL, ".");
	}
	free(token);
	return (count == 1);
}

bool	is_all_digits(char *str)
{
	size_t	i;
	bool	all_digits;

	i = 0;
	all_digits = true;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			all_digits = false;
			break ;
		}
		i++;
	}
	return (all_digits);
}

bool	is_within_unsigned_short(char *value_str)
{
	int	value;

	value = ft_atoi(value_str);
	return (value >= 0 && value <= USHRT_MAX);
}

bool	is_valid_path(char *path)
{
	return (!ft_strncmp(path, "./", 2) && ft_isalnum(path[2]));
}

int	set_texture(char **texture, bool *is_set)
{
	char	*path;

	path = ft_strtok(NULL, " ");
	if (!path)
		return (error_with_message("error: missing path."));
	if (!is_valid_path(path))
		return (error_with_message("error: invalid path."));
	*texture = path;
	*is_set = true;
	return (SUCCESS);
}

bool	is_in_rgb_range(char *value_str)
{
	int	value;

	value = ft_atoi(value_str);
	return (value >= 0 && value <= 255);
}

int	validate_color_format(char *rgb)
{
	unsigned short	count;
	char			*token;

	count = 0;
	while (count < 3)
	{
		if (count == 0)
			token = ft_strtok(rgb, ",");
		else
			token = ft_strtok(NULL, ",");
		if (!(token && is_all_digits(token) && is_in_rgb_range(token)))
			return (ERROR);
		count++;
	}
	token = ft_strtok(NULL, ",");
	if (token)
		return (ERROR);
	return (SUCCESS);
}

int	set_color(unsigned short *color, bool *is_color_set)
{
	char	*rgb;
	char	*rgb_cpy;

	rgb = ft_strtok(NULL, " ");
	if (!rgb)
		return (error_with_message("error: missing either floor or ceiling color."));
	if (ft_strchr(rgb, '\n') && rgb[0] != '\n')
		rgb_cpy = ft_strtrim(rgb, "\n");
	if (validate_color_format(rgb_cpy) == ERROR)
		return (error_with_message("error: invalid color format."));
	free(rgb_cpy);
	color[0] = (unsigned short)ft_atoi(ft_strtok(rgb, ","));
	color[1] = (unsigned short)ft_atoi(ft_strtok(NULL, ","));
	color[2] = (unsigned short)ft_atoi(ft_strtok(NULL, ","));
	*is_color_set = true;
	return (SUCCESS);
}

int	set_identifiers_value(t_data *data, char *line)
{
	char	*token;

	token = ft_strtok(line, " ");
	if (token)
	{
		// if (ft_strcmp(token, "R"))
		// 	return (set_resolution(data));
		if (ft_strcmp(token, "NO") == 0)
			return (set_texture(&data->north_texture, &data->is_north_texture_set));
		else if (ft_strcmp(token, "SO") == 0)
			return (set_texture(&data->south_texture, &data->is_south_texture_set));
		else if (ft_strcmp(token, "WE") == 0)
			return (set_texture(&data->west_testure, &data->is_west_texture_set));
		else if (ft_strcmp(token, "EA") == 0)
			return (set_texture(&data->east_texture, &data->is_east_texture_set));
		else if (ft_strcmp(token, "F") == 0)
			return (set_color(data->floorcolor, &data->is_floorcolor_set));
		else if (ft_strcmp(token, "C") == 0)
			return (set_color(data->ceilingcolor, &data->is_ceilingcolor_set));
	}
	// free(token);
	return (SUCCESS);
}

bool	all_identifiers_set(t_data *data)
{
	return (data->is_north_texture_set && \
			data->is_south_texture_set && \
			data->is_west_texture_set && \
			data->is_east_texture_set && \
			data->is_floorcolor_set && \
			data->is_ceilingcolor_set);
}

bool	can_parse_mapdata(t_main *main, int fd)
{
	char	*line;

	while (true)
	{
		if (all_identifiers_set(&main->data))
			break ;
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (set_identifiers_value(&main->data, line) == ERROR)
		{
			free(line);
			return (false);
		}
		free(line);
	}
	return (all_identifiers_set(&main->data));
}

bool	is_empty_line(char *line)
{
	return (*line == '\0' || *line == '\n');
}

bool	has_valid_characters(char *line)
{
	char	*trimmed_line;
	size_t	trim_len;
	size_t	span_len;

	trimmed_line = ft_strtrim(line, " ");
	trim_len = ft_strlen(trimmed_line);
	span_len = ft_strspn(line, "01NSEW");
	free(trimmed_line);
	return (trim_len == span_len);
}

int	store_map_in_2d_array(t_map *map, char *line)
{
	size_t	old_size;
	size_t	new_size;
	size_t	new_alloc_rows;
	char	**new_map2d;

	if (map->used_rows >= map->alloc_rows)
	{
		if (map->alloc_rows == 0)
			new_alloc_rows = 1;
		else
			new_alloc_rows = map->alloc_rows * 2;
		old_size = map->alloc_rows * sizeof(char *);
		new_size = new_alloc_rows * sizeof(char *);
		new_map2d = ft_realloc(map->map2d, old_size, new_size);
		if (!new_map2d)
			return (error_with_message("error: failed to realloc memory."));
		map->map2d = new_map2d;
		map->alloc_rows = new_alloc_rows;
	}
	map->map2d[map->used_rows] = ft_strtrim(line, "\n");
	map->used_rows++;
	return (SUCCESS);
}

size_t	get_longest_row_len(t_map *map)
{
	size_t	max_col;
	size_t	i;

	max_col = ft_strlen(map->map2d[0]);
	i = 0;
	while (i < map->used_rows)
	{
		if (max_col < (size_t)ft_strlen(map->map2d[i]))
			max_col = ft_strlen(map->map2d[i]);
		i++;
	}
	return (max_col);
}

int	validate_left_and_right_border(t_map *map)
{
	size_t	row;
	size_t	col;
	char	first_char;
	char	last_char;

	row = 0;
	while (row < map->used_rows)
	{
		first_char = '\0';
		last_char = '\0';
		col = 0;
		while (col < get_longest_row_len(map))
		{
			if (first_char == '\0' && map->map2d[row][col] != ' ')
				first_char = map->map2d[row][col];
			if (map->map2d[row][col] != ' ')
				last_char = map->map2d[row][col];
			col++;
		}
		if (!(first_char == '1' && last_char == '1'))
			return (error_with_message("error: there is left / right border gap."));
		row++;
	}
	return (SUCCESS);
}

int	validate_map_content(t_map *map)
{
	size_t	i;
	size_t	player_count;
	char	*current_line;

	i = 1;
	player_count = 0;
	while (i < (map->used_rows - 1))
	{
		current_line = map->map2d[i];
		if (!(ft_strspn(current_line, "01NSEW ") == ft_strlen(current_line)))
			return (error_with_message("error: has invalid characters in map content."));
		if (ft_strpbrk(current_line, "NSWE"))
		{
			player_count++;
			if (player_count > 1)
				return (error_with_message("error: has more than 1 player in map."));
		}
		i++;
	}
	if (player_count == 0)
		return (error_with_message("error: no player in map."));
	return (SUCCESS);
}


int	pad_row(char** row, size_t max_col)
{
	size_t	curr_len;
	size_t	old_size;
	size_t	new_size;

	curr_len = ft_strlen(*row);
	old_size = (curr_len + 1) * sizeof(char);
	new_size = (max_col + 1) * sizeof(char);
	*row = ft_realloc(*row, old_size, new_size);
	if (*row == NULL)
		return (error_with_message("error: failed to realloc."));
	ft_memset(*row + curr_len, ' ', max_col - curr_len);
	(*row)[max_col] = '\0';
	return (SUCCESS);
}

int	validate_top_and_bottom_border(t_map *map)
{
	size_t	row;
	size_t	col;
	size_t	max_col;
	char	first_char;
	char	last_char;

	col = 0;
	max_col = get_longest_row_len(map);
	while (col < max_col)
	{
		first_char = '\0';
		last_char = '\0';
		row = 0;
		while (row < map->used_rows)
		{
			if (first_char == '\0' && map->map2d[row][col] != ' ')
				first_char = map->map2d[row][col];
			if (map->map2d[row][col] != ' ')
				last_char = map->map2d[row][col];
			row++;
		}
		if (!(first_char == '1' && last_char == '1'))
			return (error_with_message("error: there is top / bottom border gap."));
		col++;
	}
	return (SUCCESS);
}

int	validate_top_to_bottom(t_map *map)
{
	size_t	col;
	size_t	row;
	char	curr_col;
	char	top_col;
	char	bottom_col;

	col = 0;
	while (col < get_longest_row_len(map))
	{
		row = 1;
		while (row < (map->used_rows - 1))
		{
			curr_col = map->map2d[row][col];
			top_col = map->map2d[row - 1][col];
			bottom_col = map->map2d[row + 1][col];
			if (ft_strchr("0NSEW", curr_col) && !(top_col != ' ' && bottom_col != ' '))
				return (error_with_message("error: there are top / bottom gap."));
			row++;
		}
		col++;
	}
	return (SUCCESS);
}

int	validate_left_to_right(t_map *map)
{
	size_t	row;
	size_t	col;
	char	curr_col;
	char	left_col;
	char	right_col;

	row = 0;
	while (row < map->used_rows)
	{
		col = 1;
		while (col < (get_longest_row_len(map) - 1))
		{
			curr_col = map->map2d[row][col];
			left_col = map->map2d[row][col - 1];
			right_col = map->map2d[row][col + 1];
			if (ft_strchr("0NSEW", curr_col) && !(left_col != ' ' && right_col != ' '))
				return (error_with_message("error: there are left / right gap."));
			col++;
		}
		row++;
	}
	return (SUCCESS);
}

int	validate_2dmap(t_map *map)
{
	if (!map->map2d)
		return (error_with_message("error: no map."));
	if (validate_top_and_bottom_border(map) == ERROR)
		return (ERROR);
	if (validate_left_and_right_border(map) == ERROR)
		return (ERROR);
	if (validate_top_to_bottom(map) == ERROR)
		return (ERROR);
	if (validate_left_to_right(map) == ERROR)
		return (ERROR);
	if (validate_map_content(map) == -1)
		return (ERROR);
	return (SUCCESS);
}


bool	pad_2d_map(t_map *map)
{
	size_t	max_col;
	size_t	i;
	size_t	curr_row_len;

	max_col = get_longest_row_len(map);
	i = 0;
	while (i < map->used_rows)
	{
		curr_row_len = ft_strlen(map->map2d[i]);
		if (curr_row_len < max_col)
		{
			if (pad_row(&map->map2d[i], max_col) == ERROR)
				return (false);
		}
		i++;
	}
	return (true);
}

void	set_player_pos(t_main *main)
{
	t_player	*player;
	size_t		i;
	size_t		j;
	char		curr_col;

	player = &main->map.player;
	i = 0;
	while (i < main->map.used_rows)
	{
		j = 0;
		while (j < (size_t)ft_strlen(main->map.map2d[i]))
		{
			curr_col = main->map.map2d[i][j];
			if (ft_strchr("NSEW", curr_col))
			{
				player->x = j;
				player->y = i;
			}
			j++;
		}
		i++;
	}
}

bool	can_parse_mapcontent(t_main *main, int fd)
{
	char	*line;
	bool	map_started;

	map_started = false;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if ((map_started == false) && (is_empty_line(line)))
			continue ;
		map_started = true;
		if ((map_started == true) && (is_empty_line(line)))
		{
			free(line);
			return (false);
		}
		if (store_map_in_2d_array(&main->map, line) == ERROR)
		{
			free(line);
			return (false);
		}
		free(line);
	}
	pad_2d_map(&main->map);
	if (validate_2dmap(&main->map) == ERROR)
		return (false);
	set_player_pos(main);
	return (true);
}

void	parse_map(t_main *main, char *mapname)
{
	int	fd;

	if (!extension_is_cub(mapname))
		exit_with_message("error: invalid map extension.");
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		exit_with_message("error: opening map.");
	if (!can_parse_mapdata(main, fd))
	{
		close(fd);
		exit_with_message("error: parsing map data.");
	}
	if (!can_parse_mapcontent(main, fd))
	{
		close(fd);
		exit_with_message("error: parsing map content.");
	}
	close(fd);
}

void	initialize_data(t_data *data)
{
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_testure = NULL;
	data->east_texture = NULL;
	data->floorcolor[0] = 0;
	data->floorcolor[1] = 0;
	data->floorcolor[2] = 0;
	data->ceilingcolor[0] = 0;
	data->ceilingcolor[1] = 0;
	data->ceilingcolor[2] = 0;
	data->is_width_set = false;
	data->is_height_set = false;
	data->is_north_texture_set = false;
	data->is_south_texture_set = false;
	data->is_west_texture_set = false;
	data->is_east_texture_set = false;
	data->is_floorcolor_set = false;
	data->is_ceilingcolor_set = false;
}

void	initialize_map(t_map *map)
{
	map->used_rows = 0;
	map->alloc_rows = 0;
	map->map2d = NULL;
	ft_memset(map->player.keys, 0, sizeof(map->player.keys));
}

void	initialize_img(t_var *var)
{
	t_img	*data;

	data = &var->data;
	data->img = mlx_new_image(var->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_len, &data->endian);
}

void	initialize_var(t_var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	initialize_img(var);
}


void	initialize_main(t_main *main)
{
	initialize_data(&main->data);
	initialize_map(&main->map);
	initialize_var(&main->var);
}

void	my_mlx_pixel_put(t_img *data, size_t x, size_t y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Bitshifting color
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	draw_tile(t_img *data, size_t x, size_t y, int color)
{
	size_t	start_x;
	size_t	start_y;
	size_t	x_span;
	size_t	y_span;

	start_x = x * TILE_SIZE;
	start_y = y * TILE_SIZE;
	x_span = 0;
	while (x_span < TILE_SIZE)
	{
		y_span = 0;
		while (y_span < TILE_SIZE)
		{
			my_mlx_pixel_put(data, start_x + x_span, start_y + y_span, color);
			y_span++;
		}
		x_span++;
	}
}

void	draw_minimap(t_main *main)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < main->map.used_rows)
	{
		y = 0;
		while (y < (size_t)ft_strlen(main->map.map2d[x]))
		{
			if (main->map.map2d[x][y] == '1')
				draw_tile(&main->var.data, y, x, create_trgb(1, 255, 255, 255));
			else if (main->map.map2d[x][y] == '0')
				draw_tile(&main->var.data, y, x, create_trgb(1, 0, 0, 255));
			else if (main->map.map2d[x][y] == 'N')
				draw_tile(&main->var.data, y, x, create_trgb(1, 255, 0, 0));
			y++;
		}
		x++;
	}
}

void	move_player(t_main *main, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = main->map.player.x + dx;
	new_y = main->map.player.y + dy;
	if (new_x >= 0 && new_x < ft_strlen(main->map.map2d[new_y]) && new_y >= 0 && new_y < main->map.used_rows && main->map.map2d[new_y][new_x] != '1')
	{
		main->map.map2d[main->map.player.y][main->map.player.x] = '0';
		main->map.map2d[new_y][new_x] = 'N';
		main->map.player.x = new_x;
		main->map.player.y = new_y;
	}
}

int	key_press(int keycode, t_main *main)
{
	if (keycode < 256)
		main->map.player.keys[keycode] = 1;
	else if (keycode == 65307)
	{
		mlx_destroy_window(main->var.mlx, main->var.win);
		exit(0);
	}
	return (SUCCESS);
}

void	process_movement(t_main *main)
{
	if (main->map.player.keys[119]) // W
	{
		move_player(main, 0, -1);
		main->map.player.keys[119] = 0;
	}
	if (main->map.player.keys[97]) // A
	{
		move_player(main, -1, 0);
		main->map.player.keys[97] = 0;
	}
	if (main->map.player.keys[100]) // D
	{
		move_player(main, 1, 0);
		main->map.player.keys[100] = 0;
	}
	if (main->map.player.keys[115]) // S
	{
		move_player(main, 0, 1);
		main->map.player.keys[115] = 0;
	}
}

int	render_next_frame(void *s_main)
{
	t_main	*main;
	t_var	*var;

	main = (t_main *)s_main;
	var = &main->var;
	process_movement(main);
	draw_minimap(main);
	mlx_put_image_to_window(var->mlx, var->win, var->data.img, 0, 0);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_main	main;

	if (!(argc == 2))
		return (error_with_message("error: too many arguments."));
	initialize_main(&main);
	parse_map(&main, argv[1]);
	mlx_hook(main.var.win, 2, 1L<<0, key_press, &main);
	mlx_loop_hook(main.var.mlx, render_next_frame, &main);
	mlx_loop(main.var.mlx);
}
