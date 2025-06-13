#include "recipe_generator.h"

struct Recipe	*create_custom_recipe(void)
{
	
	struct Ingredients	*ingredients;
	struct TasteProfile	*taste_profile;
	
	// Ottiene gli ingredienti attuali
	ingredients = get_current_ingredients();
	if (!ingredients)
		return (NULL);
	// Ottengo il profilo di gusto dell'utente
	taste_profile = get_user_taste_profile();
	if (!taste_profile)
	{
		free_ingredients(ingredients);
		return NULL;
	}
	struct Recipe *recipe = NULL;
	int approved = 0;
	while (!approved)
	{
		// Genera una nuova ricetta candidata
		recipe = create_recipe(ingredients, taste_profile);
		if (!recipe)
			break;
		// Chiede l'approvazione dell'utente
		approved = get_user_approval(recipe);
		if (!approved)
		{
			free_recipe(recipe);
			recipe = NULL;
		}
	}
	free_ingredients(ingredients);
	free_taste_profile(taste_profile);
	return (recipe);
}