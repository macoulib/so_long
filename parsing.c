#include "so_long.h"


char	*get_file_content(const char *filename)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*content = NULL;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = calloc(1, 1);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		tmp = content;
		content = malloc(strlen(tmp) + bytes_read + 1);
		if (!content)
			return (NULL);
		strcpy(content, tmp);
		strcat(content, buffer);
		free(tmp);
	}
	close(fd);
	return (content);
}

char	**load_map(const char *filename)
{
	char	*file_content;
	char	**map;

	file_content = get_file_content(filename);
	if (!file_content)
		return (NULL);
	map = ft_split(file_content, '\n'); 
	free(file_content);
	return (map);
}