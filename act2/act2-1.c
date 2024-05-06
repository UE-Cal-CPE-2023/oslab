#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *proc_ids, *burst_times, *arrival_times;
    int i, n_proc, time_quantum, remaining_proc, current_time;
    float waiting_time_avg, turnaround_time_avg;

    // Get the number of processes and allocate memory for burst_times, waiting_times, and turnaround_times
    printf("\nNumber of processes: ");
    scanf("%d", &n_proc);
    proc_ids = (int *)malloc(n_proc * sizeof(int));
    burst_times = (int *)malloc(n_proc * sizeof(int));
    arrival_times = (int *)malloc(n_proc * sizeof(int));
    if (burst_times == NULL || arrival_times == NULL || proc_ids == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Fill process ids
    for (i = 0; i < n_proc; i++)
    {
        proc_ids[i] = i + 1;
    }
    
    // Get the burst times for each process
    for (i = 0; i < n_proc; i++)
    {
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &burst_times[i]);
    }

    // Get arrival time for each process
    for (i = 0; i < n_proc; i++)
    {
        printf("Arrival time for P%d: ", i + 1);
        scanf("%d", &arrival_times[i]);
    }

    // Get the time quantum
    printf("Time quantum per process: ");
    scanf("%d", &time_quantum);

    // Print the table header
    printf("\n\t CURRENT TIME \t PROCESS \t EXEC TIME \t INITL BURST \t RMNG BURST\n");

    // Simulate the round robin scheduling
    // if proc_id = 0, then the process is already completed
    // for each proc_id, execute the process for time_quantum or until the process is completed
    remaining_proc = n_proc;
    current_time = 0;
    waiting_time_avg = 0;
    turnaround_time_avg = 0;
    while (remaining_proc > 0)
    {
        for (i = 0; i < n_proc; i++)
        {
            // if the process is not yet completed and the arrival time is less than or equal to the current time,
            if (proc_ids != 0 && arrival_times[i] <= current_time && burst_times[i] > 0)
            {
                // if the burst time is greater than the time quantum, execute the process for time quantum
                if (burst_times[i] > time_quantum)
                {
                    printf("\t %d \t\t P%d \t\t %d \t\t %d \t\t %d\n", current_time, proc_ids[i], time_quantum, burst_times[i], burst_times[i] - time_quantum);
                    current_time += time_quantum;
                    burst_times[i] -= time_quantum;
                }
                // if the burst time is less than or equal to the time quantum, execute the process for the remaining burst time
                else
                {
                    printf("\t %d \t\t P%d \t\t %d \t\t %d \t\t %d\n", current_time, proc_ids[i], burst_times[i], burst_times[i], 0);
                    current_time += burst_times[i];
                    burst_times[i] = 0;
                    proc_ids[i] = 0;
                    remaining_proc--;
                }

                // if the process is completed, add to waiting time and turnaround time
                waiting_time_avg += current_time - arrival_times[i] - burst_times[i];
                turnaround_time_avg += current_time - arrival_times[i];
            }
            
        }
    }

    // Print the average waiting time and turnaround time
    printf("\nAverage waiting time: %.2f\n", waiting_time_avg / n_proc);
    printf("Average turnaround time: %.2f\n", turnaround_time_avg / n_proc);

    // Free the allocated memory
    free(proc_ids);
    free(burst_times);
    free(arrival_times);

    return 0;
}