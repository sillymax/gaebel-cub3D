/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:43:34 by ychng             #+#    #+#             */
/*   Updated: 2024/06/25 04:02:46 by ychng            ###   ########.fr       */
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
}	t_data;

typedef struct s_map
{
	size_t	rows;
	size_t	columns;
	char	**map2d;
}	t_map;

typedef struct s_main
{
	t_data	data;
	t_map	map;
}	t_main;

bool	exetension_is_cub(char *mapname)
{
	short	count;
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

bool	is_within_unsigned_short(char *value_str)
{
	int	value;

	value = ft_atoi(value_str);
	return (value >= 0 && value <= USHRT_MAX);
}

void	set_resolution(t_main *main, char *line)
{
	char	*width_str;
	char	*height_str;

	width_str = ft_strtok(NULL, " ");
	height_str = ft_strtok(NULL, " ");
	if (!(width_str && height_str))
	{
		free(line);
		exit_with_message("error: resolution must have both width and height.");
	}
	if (!(is_all_digits(width_str) && is_all_digits(height_str)))
	{
		free(line);
		exit_with_message("error: resolution dimensions must be valid number.");
	}
	if (!(is_within_unsigned_short(width_str) && is_within_unsigned_short(height_str)))
	{
		free(line);
		exit_with_messsage("error: resolution dimensions are out of range.");
	}
	main->data.width = (unsigned short)ft_atoi(width_str);
	main->data.height = (unsigned short)ft_atoi(height_str);
}

bool	is_valid_path(char *path)
{
	return (!ft_strncmp(path, "./", 2) && ft_isalnum(path[2]));
}

void	set_texture(char **texture, char *line)
{
	char	*path;

	path = ft_strtok(NULL, " ");
	if (!path)
	{
		free(line);
		exit_with_messahe("error: missing path.");
	}
	if (!is_valid_path(path))
	{
		free(line);
		exit_with_message("error: invalid path.");
	}
	*texture = path;
}

void	validate_floorcolor_format(char *floorcolor, char *line)
{
	size_t	count;
	char	*token;

	count = 0;
	while (count < 3)
	{
		if (count == 0)
			token = ft_strtok(floorcolor, ",");
		else
			token = ft_strtok(NULL, ",");
		if (!(token && is_all_digits(token) && is_valid_path(token)))
		{
			free(line);
			exit_with_message("error: invalid floor color format.");
		}
	}
	token = ft_strtok(NULL, ",");
	if (token)
	{
		free(line);
		exit_with_message("error: invalid floor color format.");
	}
}

void	set_floorcolor(t_main *main, char *line)
{
	char	*floorcolor;
	char	*floorcolor_copy;

	floorcolor = ft_strtok(NULL, " ");
	if (!floorcolor)
	{
		free(line);
		exit_with_message("error: missing floor color.");
	}
	floorcolor_copy = ft_strdup(floorcolor);
	validate_floorcolor_format(floorcolor_copy, line);
	free(floorcolor_copy);
	main->data.floorcolor[0] = (unsigned short)ft_atoi(ft_strtok(floorcolor, ","));
	main->data.floorcolor[1] = (unsigned short)ft_atoi(ft_strtok(NULL, ","));
	main->data.floorcolor[2] = (unsigned short)ft_atoi(ft_strtok(NULL, ","));
}

void	set_identifiers_value(t_main *main, char *line)
{
	char	*token;

	token = ft_strtok(line, " ");
	if (token)
	{
		if (ft_strcmp(token, "R"))
			set_resolution(main, line);
		else if (ft_strcmp(token, "NO"))
			set_texture(&main->data.north_texture, line);
		else if (ft_strcmp(token, "SO"))
			set_texture(&main->data.south_texture, line);
		else if (ft_strcmp(token, "WE"))
			set_texture(&main->data.west_testure, line);
		else if (ft_strcmp(token, "EA"))
			set_texture(&main->data.east_texture, line);
		else if (ft_strcmp(token, "S"))
			set_texture(&main->data.sprite_texture, line);
		else if (ft_strcmp(token, "F"))
			set_floorcolor(main, line);
	}
	free(token);
}

bool	parse_mapdata(t_main *main, char *mapname)
{
	int		fd;
	char	*line;

	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		exit_with_message("error: opening file.");
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		set_identifiers_value(main, line);
		free(line);
	}
}

void	parse_map(t_main *main, char *mapname)
{
	if (!extension_is_cub(mapname))
		exit_with_message("error: invalid map extension.");
	if (!parse_mapdata(main, mapname))
		exit_with_message("");
	if (!parse_mapcontent())
		exit_with_message("");
}

int main(int argc, char **argv)
{
	t_main	main;

	// if (!(argc == 2))
		// return (write_error());
	parse_map(&main, argv[1]);
}
