#include "task_scheduler.h"

// Helper: inizializza e valida le strutture di base
static int	init_scheduler_structs(struct TaskList *tasks, struct TaskProfile **profile, struct PriorityMap **priorities, int *core_count)
{
	if (!tasks || !tasks->tasks || tasks->count <= 0)
		return (0);
	*profile = profile_tasks(tasks);
	if (!*profile)
		return (0);
	*priorities = compute_priorities_mock(*profile);
	if (!*priorities)
	{
		free_task_profile(*profile);
		return (0);
	}
	*core_count = get_available_core_count();
	if (*core_count <= 0)
	{
		free_task_profile(*profile);
		free_priority_map(*priorities);
		return (0);
	}
	return (1);
}

// Helper: esegue la schedulazione vera e propria
static void	assign_tasks_to_cores(struct ScheduleResult *result, struct TaskProfile *profile, struct PriorityMap *priorities, int core_count, int task_count)
{
	int	current_core;
	int selected_task;
	int	i;
	
	current_core = 0;
	i = 0;
	while (i < task_count)
	{
		selected_task = select_best_task_for_current_priorities(profile, priorities);
		if (selected_task >= 0)
		{
			update_schedule_entry(result, current_core, selected_task);
			update_priorities_after_assignment(priorities, selected_task);
			current_core = (current_core + 1) % core_count;
		}
		i++;
	}
}

// Helper: libera le risorse allocate
static void	free_scheduler_structs(struct TaskProfile *profile, struct PriorityMap *priorities)
{
	free_task_profile(profile);
	free_priority_map(priorities);
}

struct ScheduleResult	*schedule_tasks(struct TaskList *tasks)
{
	struct TaskProfile		*profile = NULL;
	struct PriorityMap		*priorities = NULL;
	struct ScheduleResult	*result = NULL;
	int						core_count;

	if (!init_scheduler_structs(tasks, &profile, &priorities, &core_count))
		return (NULL);
	result = create_schedule_result(core_count);
	if (!result)
	{
		free_scheduler_structs(profile, priorities);
		return (NULL);
	}
	assign_tasks_to_cores(result, profile, priorities, core_count, tasks->count);
	free_scheduler_structs(profile, priorities);
	return (result);
}