#include "recipe_generator.h"

struct Recipe	*create_custom_recipe()
{
	struct Ingredients *ingredients;
	struct TasteProfile *taste_profile;
	struct Recipe *recipe;
	int approved;
	int creation_failed;

	ingredients = NULL;
	taste_profile = NULL;
	recipe = NULL;
	approved = 0;
	creation_failed = 0;

	ingredients = get_current_ingredients();
	if (!ingredients)
		return (NULL);
	taste_profile = get_user_taste_profile();
	if (!taste_profile)
	{
		free_ingredients(ingredients);
		return (NULL);
	}
	while (!approved && !creation_failed)
	{
		if (recipe)
		{
			free_recipe(recipe);
			recipe = NULL;
		}
		recipe = create_recipe(ingredients, taste_profile);
		if (!recipe)
			creation_failed = 1;
		else
			approved = get_user_approval(recipe);
	}
	free_ingredients(ingredients);
	ingredients = NULL;
	free_taste_profile(taste_profile);
	taste_profile = NULL;
	if (creation_failed)
		return (NULL);
	return (recipe);
}