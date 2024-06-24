/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:31:43 by ychng             #+#    #+#             */
/*   Updated: 2024/06/24 23:46:27 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef struct s_map
{
	size_t	rows;
	size_t	columns;
	char	*mapname;
	char	**map2d;
}	t_map;

typedef struct s_main
{
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

bool	has_valid_characters(char *line)
{
	ft_strcpbrk(line, "012NSEW");
}

bool	meet_requirements(char *mapname)
{
	int		fd;
	char	*line;
	bool	flag;

	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		exit_with_messahe("error: opening file.");
	while (true)	
	{
		line = get_next_line(fd);
		if (!(has_valid_characters(line) && has_valid_border(line)))
		{
			flag = false;
			break ;
		}
		else if (line == NULL)
		{
			flag = true;
			break ;
		}
		free(line);
	}
	close(fd);
	free(line);
	return (flag);
}

void	parse_map(t_main *main, char *mapname)
{
	if (!extension_is_cub(mapname))
		exit_with_message("error: invalid map extension.");
	if (!meet_requirements(mapname))
		exit_with_message("error: map does not meet requirements.");
	store_info(main, mapname);
}

int main(int argc, char **argv)
{
	t_main	main;

	// if (!(argc == 2))
		// return (write_error());
	parse_map(&main, argv[1]);
}
