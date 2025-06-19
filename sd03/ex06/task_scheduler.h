#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include <stdlib.h>

struct Task
{
	int			id;
	int			load;
	int			io_intensity;
	int			priority;
};

struct TaskList
{
	struct Task	*tasks;
	int			count;
};

struct TaskProfile
{
	int			total_load;
	int			avg_io_intensity;
	int			complexity_score;
};

struct PriorityMap
{
	int			*priorities;
	int			count;
};

struct ScheduleResult
{
	int			**core_assignments;
	int			core_count;
	int			*tasks_per_core;
};

// Helper functions
struct TaskProfile		*profile_tasks(struct TaskList *tasks);
struct PriorityMap		*compute_priorities_mock(struct TaskProfile *profile);
int						get_available_core_count(void);
int						select_best_task_for_current_priorities(struct TaskProfile *profile, struct PriorityMap *priorities);
struct ScheduleResult	*create_schedule_result(int core_count);
void					update_schedule_entry(struct ScheduleResult *result, int core_id, int task_id);
void					free_task_profile(struct TaskProfile *profile);
void					free_priority_map(struct PriorityMap *priorities);
void					free_schedule_result(struct ScheduleResult *result);

// Main function
struct ScheduleResult *schedule_tasks(struct TaskList *tasks);

#endif