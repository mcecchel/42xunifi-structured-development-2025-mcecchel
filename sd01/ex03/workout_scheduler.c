#include "workout_scheduler.h"

struct WorkoutPlan *create_workout_schedule(char *username) {
	// Validate input
	if (!username) {
		return NULL;
	}
	
	// Step 1: Get user data
	struct UserData *user_data = get_user_data(username);
	if (!user_data) {
		return NULL;  // Failed to get user data
	}
	
	// Step 2: Build base workout plan
	struct WorkoutPlan *plan = build_base_plan(user_data);
	if (!plan) {
		free_user_data(user_data);
		return NULL;  // Failed to build base plan
	}
	
	// Step 3: Refine the plan with user preferences
	struct WorkoutPlan *refined_plan = refine_plan(plan, user_data);
	if (!refined_plan) {
		free_workout_plan(plan);
		free_user_data(user_data);
		return NULL;  // Failed to refine plan
	}
	
	// Update plan pointer if refine_plan returned a new one
	if (refined_plan != plan) {
		free_workout_plan(plan);
		plan = refined_plan;
	}
	
	// Step 4: Determine workout duration
	int duration = determine_duration(plan);
	if (duration <= 0) {
		free_workout_plan(plan);
		free_user_data(user_data);
		return NULL;  // Invalid duration
	}
	
	// Step 5: Assign daily exercises and tips for each day
	for (int day = 1; day <= duration; day++) {
		assign_daily_exercises(plan, day);
		assign_daily_tips(plan, day);
	}
	
	// Cleanup user data (no longer needed)
	free_user_data(user_data);
	
	return plan;  // Return complete workout schedule
}