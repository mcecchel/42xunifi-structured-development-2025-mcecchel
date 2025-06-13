#include "workout_scheduler.h"

struct WorkoutPlan	*create_workout_schedule(char *username)
{	
	struct UserData		*user_data;
	struct WorkoutPlan	*plan;
	struct WorkoutPlan	*refined_plan;

	// Validazione dell'input
	if (!username)
		return (NULL);

	// Ottengo i dati dell'utente
	user_data = get_user_data(username);
	if (!user_data)
		return (NULL);
	
	// Costruisco il piano base di allenamento
	plan = build_base_plan(user_data);
	if (!plan)
	{
		free_user_data(user_data);
		return (NULL);
	}
	// Aggiungo le preferenze dell'utente
	refined_plan = refine_plan(plan, user_data);
	if (!refined_plan)
	{
		free_workout_plan(plan);
		free_user_data(user_data);
		return (NULL);
	}
	// Aggiorna il puntatore se refine_plan restituisce un nuovo piano
	if (refined_plan != plan)
	{
		free_workout_plan(plan);
		plan = refined_plan;
	}
	// Determina la durata dell'allenamento
	int duration;
	duration = determine_duration(plan);
	if (duration <= 0)
	{
		free_workout_plan(plan);
		free_user_data(user_data);
		return NULL;
	}
	// Assegna esercizi e consigli per ogni giorno
	int day;
	day = 1;
	while (day <= duration)
	{
		assign_daily_exercises(plan, day);
		assign_daily_tips(plan, day);
		day++;
	}
	free_user_data(user_data);
	return (plan);
}