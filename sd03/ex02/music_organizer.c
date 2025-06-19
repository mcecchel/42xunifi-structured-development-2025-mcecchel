#include "music_organizer.h"
#include <stdlib.h>

struct MusicLibrary	*organize_music_library(const char *directory_path)
{
	struct MusicLibrary	*library;
	const char			**filenames;
	struct MusicFile	*music_file;
	int					i;
	
	library = NULL;
	filenames = NULL;
	music_file = NULL;
	if (!directory_path || directory_path[0] == '\0')
		return (NULL);
	library = create_music_library();
	if (!library)
		return (NULL);
	filenames = scan_directory(directory_path);
	if (!filenames)
	{
		free(library);
		return (NULL);
	}
	i = 0;
	while (filenames[i])
	{
		music_file = process_music_file(directory_path, filenames[i]);
		if (music_file) 
			update_music_library(library, music_file);
		i++;
	}
	free(filenames);
	return (library);
}