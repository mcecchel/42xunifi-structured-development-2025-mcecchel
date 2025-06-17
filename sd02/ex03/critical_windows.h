#ifndef CRITICAL_WINDOWS_H
#define CRITICAL_WINDOWS_H

#define WINDOW_SIZE 5
#define HIGH_THRESHOLD 70
#define MAX_THRESHOLD 150
#define AVG_THRESHOLD 90

#include <stdio.h>

int	count_critical_windows(const int *readings, int size);

#endif