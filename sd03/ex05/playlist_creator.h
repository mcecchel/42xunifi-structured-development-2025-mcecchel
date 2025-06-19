#ifndef PLAYLIST_CREATOR_H
#define PLAYLIST_CREATOR_H

#include <stdlib.h>

struct MoodSettings
{
	char	*primary_mood;
	int		intensity;
	char	**secondary_moods;
};

struct FilterSettings
{
	char	*genre;
	int		tempo_min;
	int		tempo_max;
	int		popularity_threshold;
};

struct SongData
{
	char	*title;
	char	*artist;
	char	*genre;
	int		tempo;
	int		popularity;
};

struct Playlist
{
	struct SongData	**songs;
	int				count;
	char			*name;
};

// Helper functions
struct MoodSettings		*analyze_user_mood(void);
struct FilterSettings	*default_filters(void);
int						get_mood_variations(struct MoodSettings *mood);
struct FilterSettings	*refine_filters(struct FilterSettings *current);
int						filters_require_popular_song(struct FilterSettings *filters);
struct SongData			*fetch_popular_song(void);
struct SongData			*fetch_niche_song(void);
struct Playlist			*combine_with_mood_playlist(struct SongData *song, struct MoodSettings *mood);
void					free_mood_settings(struct MoodSettings *mood);
void					free_filter_settings(struct FilterSettings *filters);
void					free_song_data(struct SongData *song);
void					free_playlist(struct Playlist *playlist);

// Main function
struct Playlist	*create_playlist(void);

#endif