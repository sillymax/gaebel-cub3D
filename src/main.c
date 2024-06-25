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

typedef struct s_data
{
	unsigned short	width;
	unsigned short	height;
	char			*north_texture;
	char			*south_texture;
	char			*west_testure;
	char			*east_texture;
	char			*sprite_texture;
	unsigned short	floorcolor[3];
	bool			is_width_set;
	bool			is_height_set;
	bool			is_north_texture_set;
	bool			is_south_texture_set;
	bool			is_west_texture_set;
	bool			is_east_texture_set;
	bool			is_sprite_texture_set;
	bool			is_floorcolor_set;
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

bool	exetension_is_cub(char *mapname)
{
	size_t	count;
	char	*token;

	count = 0;
	token = ft_strdup(mapname);
	token = ft_strtok(token, ".");
	while (!(token == NULL))
	{
		if (ft_strcmp(token, ".cub") == 0)
			count++;
		token = ft_strtok(NULL, ".");
	}
	free(token);
	return (count == 1);
}

// bool	meet_requirements(char *mapname)
// {
// 	int		fd;
// 	char	*line;
// 	bool	flag;

// 	fd = open(mapname, O_RDONLY);
// 	if (fd < 0)
// 		exit_with_messahe("error: opening file.");
// 	while (true)
// 	{
// 		line = get_next_line(fd);
// 		if (!(has_valid_characters(line) && has_valid_border(line)))
// 		{
// 			flag = false;
// 			break ;
// 		}
// 		else if (line == NULL)
// 		{
// 			flag = true;
// 			break ;
// 		}
// 		free(line);
// 	}
// 	close(fd);
// 	free(line);
// 	return (flag);
// }

bool	is_all_digits(char *str)
{
	size_t	i;
	bool	all_digits;

	i = 0;
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

bool	is_in_unsigned_short_range(char *value_str)
{
	int	value;

	value = ft_atoi(value_str);
	return (value >= 0 && value <= USHRT_MAX);
}

int	set_resolution(t_data *data, char *line)
{
	char	*width_str;
	char	*height_str;

	width_str = ft_strtok(NULL, " ");
	height_str = ft_strtok(NULL, " ");
	if (!(width_str && height_str))
		return (error_with_message("error: resolution must have both width and height."));
	if (!(is_all_digits(width_str) && is_all_digits(height_str)))
		return (error_with_message("error: resolution dimensions must be valid number."));
	if (!(is_within_unsigned_short(width_str) && is_in_unsigned_short_range(height_str)))
		return (error_with_message("error: resolution dimensions are out of range."));
	data->width = (unsigned short)ft_atoi(width_str);
	data->height = (unsigned short)ft_atoi(height_str);
	data->is_width_set = true;
	data->is_height_set = true;
	return (SUCCESS);
}

bool	is_valid_path(char *path)
{
	return (!ft_strncmp(path, "./", 2) && ft_isalnum(path[2]));
}

int	set_texture(char **texture, bool *is_set, char *line)
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

int	validate_floorcolor_format(char *floorcolor, char *line)
{
	unsigned short	count;
	char			*token;

	count = 0;
	while (count < 3)
	{
		if (count == 0)
			token = ft_strtok(floorcolor, ",");
		else
			token = ft_strtok(NULL, ",");
		if (!(token && is_all_digits(token) && is_in_rgb_range(token)))
			return (ERROR);
	}
	token = ft_strtok(NULL, ",");
	if (token)
		return (ERROR);
	return (SUCCESS);
}

int	set_floorcolor(t_data *data, char *line)
{
	char	*floorcolor;
	char	*floorcolor_copy;

	floorcolor = ft_strtok(NULL, " ");
	if (!floorcolor)
		return (error_with_message("error: missing floor color."));
	floorcolor_copy = ft_strdup(floorcolor);
	if (validate_floorcolor_format(floorcolor_copy, line) == ERROR)
		return (error_with_message("error: invalid floor color format."));
	free(floorcolor_copy);
	data->floorcolor[0] = (unsigned short)ft_atoi(ft_strtok(floorcolor, ","));
	data->floorcolor[1] = (unsigned short)ft_atoi(ft_strtok(NULL, ","));
	data->floorcolor[2] = (unsigned short)ft_atoi(ft_strtok(NULL, ","));
	data->is_floorcolor_set = true;
	return (SUCCESS);
}

int	set_identifiers_value(t_data *data, char *line)
{
	char	*token;

	token = ft_strtok(line, " ");
	if (token)
	{
		if (ft_strcmp(token, "R"))
			return (set_resolution(data, line));
		else if (ft_strcmp(token, "NO"))
			return (set_texture(&data->north_texture, &data->is_north_texture_set, line));
		else if (ft_strcmp(token, "SO"))
			return (set_texture(&data->south_texture, &data->is_south_texture_set, line));
		else if (ft_strcmp(token, "WE"))
			return (set_texture(&data->west_testure, &data->is_west_texture_set, line));
		else if (ft_strcmp(token, "EA"))
			return (set_texture(&data->east_texture, &data->is_east_texture_set, line));
		else if (ft_strcmp(token, "S"))
			return (set_texture(&data->sprite_texture, &data->is_south_texture_set, line));
		else if (ft_strcmp(token, "F"))
			return (set_floorcolor(data, line));
	}
	free(token);
	return (SUCCESS);
}

bool	all_identifiers_set(t_data *data)
{
	return (data->is_width_set && \
			data->is_height_set && \
			data->is_north_texture_set && \
			data->is_south_texture_set && \
			data->is_west_texture_set && \
			data->is_east_texture_set && \
			data->is_sprite_texture_set && \
			data->is_floorcolor_set);
}

// Free the line before the last return, in case the loop breaks due to all_identifiers_set(main)
bool	can_parse_mapdata(t_main *main, int fd)
{
	char	*line;

	while (true)
	{
		line = get_next_line(fd);
		if (!line || all_identifiers_set(&main->data))
			break ;
		else if (set_identifiers_value(&main->data, line) == ERROR)
		{
			free(line);
			return (false);
		}
		free(line);
	}
	free(line);
	return (all_identifiers_set(&main->data));
}

bool	is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_isblank(*line))
			return (false);
		line++;
	}
	return (true);
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
		if (!map->map2d)	
			return (error_with_message("error: failed to realloc memory."));
		map->map2d = new_map2d;
		map->alloc_rows = new_size;
	}
	map->map2d[map->used_rows] = ft_strdup(line);
	map->used_rows++;
	return (SUCCESS);
}

int	validate_2dmap(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map2d[i])	
	{

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
		if (store_map_in_2d_array(&main->map, line) == ERROR);
		{
			free(line);
			return (false);
		}
		free(line);
	}
	return (validate_2dmap(&main->map) == SUCCESS);
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
	data->width = 0;
	data->height = 0;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_testure = NULL;
	data->east_texture = NULL;
	data->sprite_texture = NULL;
	data->floorcolor[0] = 0;
	data->floorcolor[1] = 0;
	data->floorcolor[2] = 0;
	data->is_width_set = false;
	data->is_height_set = false;
	data->is_north_texture_set = false;
	data->is_south_texture_set = false;
	data->is_west_texture_set = false;
	data->is_east_texture_set = false;
	data->is_sprite_texture_set = false;
	data->is_floorcolor_set = false;
}

void	initialize_data(t_map *map)
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
	t_main	main;

	// if (!(argc == 2))
		// return (write_error());
	initialize_main(&main);
	parse_map(&main, argv[1]);
}
