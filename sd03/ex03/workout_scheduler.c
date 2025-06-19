#include "workout_scheduler.h"

struct WorkoutPlan	*create_workout_schedule(char *username)
{
	int					duration;
	int					day;
	struct UserData		*user_data;
	struct WorkoutPlan	*plan;
	
	user_data = NULL;
	plan = NULL;
	if (!username || username[0] == '\0')
		return (NULL);
	user_data = get_user_data(username);
	if (!user_data)
		return (NULL);
	plan = build_base_plan(user_data);
	if (!plan)
	{
		free_user_data(user_data);
		return (NULL);
	}
	plan = refine_plan(plan, user_data);
	if (!plan)
	{
		free_user_data(user_data);
		return (NULL);
	}
	duration = determine_duration(plan);
	if (duration <= 0)
	{
		free_user_data(user_data);
		free_workout_plan(plan);
		return (NULL);
	}
	day = 0;
	while (day < duration)
	{
		assign_daily_exercises(plan, day);
		assign_daily_tips(plan, day);
		day++;
	}
	plan->current_day = day;
	free_user_data(user_data);
	return (plan);
}