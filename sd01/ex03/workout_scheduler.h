#ifndef WORKOUT_SCHEDULER_H
#define WORKOUT_SCHEDULER_H

#include <stdlib.h>

struct UserData;
struct WorkoutPlan;

struct UserData		*get_user_data(char *username);
struct WorkoutPlan	*build_base_plan(struct UserData *data);
struct WorkoutPlan	*refine_plan(struct WorkoutPlan *plan, struct UserData *data);
int					determine_duration(struct WorkoutPlan *plan);
void				assign_daily_exercises(struct WorkoutPlan *plan, int day);
void				assign_daily_tips(struct WorkoutPlan *plan, int day);
void				free_user_data(struct UserData *data);
void				free_workout_plan(struct WorkoutPlan *plan);

struct WorkoutPlan	*create_workout_schedule(char *username);

#endif