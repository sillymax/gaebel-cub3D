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

typedef struct s_map
{
	size_t	used_rows;
	size_t	alloc_rows;	
	char	**map2d;
}	t_map;

typedef struct s_main
{
	t_data	data;
	t_map	map;
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

// int	set_resolution(t_data *data)
// {
// 	char	*width_str;
// 	char	*height_str;

// 	width_str = ft_strtok(NULL, " ");
// 	height_str = ft_strtok(NULL, " ");
// 	if (!(width_str && height_str))
// 		return (error_with_message("error: resolution must have both width and height."));
// 	if (!(is_all_digits(width_str) && is_all_digits(height_str)))
// 		return (error_with_message("error: resolution dimensions must be valid number."));
// 	if (!(is_within_unsigned_short(width_str) && is_within_unsigned_short(height_str)))
// 		return (error_with_message("error: resolution dimensions are out of range."));
// 	data->width = (unsigned short)ft_atoi(width_str);
// 	data->height = (unsigned short)ft_atoi(height_str);
// 	data->is_width_set = true;
// 	data->is_height_set = true;
// 	return (SUCCESS);
// }

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

// //  1111
// // 110011
// //  1  1
// //  1111

// // need to check for newline at the end of a map
// int	validate_top_and_bottom_border(t_map *map)
// {
// 	char	*first_line;
// 	char	*last_line;

// 	first_line = ft_strtrim(map->map2d[0], " ");
// 	last_line = ft_strtrim(map->map2d[map->used_rows - 1], " ");
// 	if (!(ft_strspn(first_line, "1 ") == ft_strlen(first_line)))
// 		return (error_with_message("error: has invalid character in top row"));
// 	if (!(ft_strspn(last_line, "1 ") == ft_strlen(last_line)))
// 		return (error_with_message("error: has invalid character in bottom row"));
// 	return (SUCCESS);
// }

// int	validate_left_and_right_border(t_map *map)
// {
// 	size_t	i;
// 	size_t	curr_line_len;
// 	char	first_char;
// 	char	last_char;

// 	i = 1;
// 	while (i < (map->used_rows - 1))
// 	{
// 		curr_line_len = ft_strlen(map->map2d[i]);
// 		first_char = map->map2d[i][0];
// 		last_char = map->map2d[i][curr_line_len - 1];
// 		if (!(first_char == '1'))
// 			return (error_with_message("error: first column is not all 1"));
// 		if (!(last_char == '1'))
// 			return (error_with_message("error: last column is not all 1"));
// 		i++;
// 	}
// 	return (SUCCESS);
// }

// int	validate_map_content(t_map *map)
// {
// 	size_t	i;
// 	size_t	player_count;
// 	char	*current_line;

// 	i = 1;
// 	player_count = 0;
// 	while (i < (map->used_rows - 1))
// 	{
// 		current_line = map->map2d[i];
// 		if (!(ft_strspn(current_line, "01NSEW ") == ft_strlen(current_line)))
// 			return (error_with_message("error: has invalid characters in map content."));
// 		if (ft_strpbrk(current_line, "NSWE"))
// 		{
// 			player_count++;
// 			if (player_count > 1)
// 				return (error_with_message("error: has more than 1 player in map."));
// 		}
// 		i++;
// 	}
// 	return (SUCCESS);
// }

int	validate_2dmap(t_map *map)
{
	if (!map->map2d)
		return (error_with_message("error: no map."));
	// if (validate_top_and_bottom_border(map) == -1)
	// 	return (false);
	// if (validate_left_and_right_border(map) == -1)
	// 	return (false);
	// if (validate_map_content(map) == -1)
	// 	return (false);
	
	return (true);
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
	ft_memset(*row + curr_len, 'c', max_col - curr_len);
	(*row)[max_col] = '\0';
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
	// printf("%s\n", main->map.map2d[0]);
	// printf("%s\n", main->map.map2d[1]);
	// printf("%s\n", main->map.map2d[2]);
	// return (false);
	return (validate_2dmap(&main->map));
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
}


void	initialize_main(t_main *main)
{
	initialize_data(&main->data);
	initialize_map(&main->map);
}

int main(int argc, char **argv)
{
	(void)argc;
	t_main	main;

	// if (!(argc == 2))
		// return (write_error());
	initialize_main(&main);
	parse_map(&main, argv[1]);
}
