#include "playlist_creator.h"

// Helper: gestisce la creazione e raffinazione dei filtri
static struct FilterSettings	*prepare_filters(struct MoodSettings *mood)
{
	struct FilterSettings *filters;
	int variations;
	struct FilterSettings *new_filters;

	filters = default_filters();
	if (!filters)
		return (NULL);
	variations = get_mood_variations(mood);
	int i = 0;
	while (i < variations)
	{
		new_filters = refine_filters(filters);
		if (!new_filters)
		{
			free_filter_settings(filters);
			return (NULL);
		}
		free_filter_settings(filters);
		filters = new_filters;
		i++;
	}
	return (filters);
}

// Helper: seleziona la canzone in base ai filtri
static struct SongData	*select_song(struct FilterSettings *filters)
{
	if (filters_require_popular_song(filters))
		return (fetch_popular_song());
	else
		return (fetch_niche_song());
}

// Main function: crea una playlist basata sull'umore dell'utent
struct Playlist	*create_playlist(void)
{
	struct MoodSettings		*mood;
	struct FilterSettings	*filters;
	struct SongData			*song;
	struct Playlist			*playlist;

	mood = analyze_user_mood();
	if (!mood)
		return (NULL);
	filters = prepare_filters(mood);
	if (!filters)
	{
		free_mood_settings(mood);
		return (NULL);
	}
	song = select_song(filters);
	if (!song)
	{
		free_mood_settings(mood);
		free_filter_settings(filters);
		return (NULL);
	}
	playlist = combine_with_mood_playlist(song, mood);
	free_mood_settings(mood);
	free_filter_settings(filters);
	free_song_data(song);
	return (playlist);
}