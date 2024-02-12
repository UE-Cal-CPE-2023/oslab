#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *proc_ids, *burst_times, *proc_priorities;
    int i, n_proc, remaining_proc, current_time;
    float waiting_time_avg, turnaround_time_avg;

    // Get the number of processes and allocate memory for burst_times and proc_priorities
    printf("\nNumber of processes: ");
    scanf("%d", &n_proc);
    burst_times = (int *)malloc(n_proc * sizeof(int));
    proc_priorities = (int *)malloc(n_proc * sizeof(int));
    proc_ids = (int *)malloc(n_proc * sizeof(int));
    if (burst_times == NULL || proc_priorities == NULL || proc_ids == NULL)
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

    // Get priority for each process
    for (i = 0; i < n_proc; i++)
    {
        printf("Priority for P%d (lower integer, higher priority): ", i + 1);
        scanf("%d", &proc_priorities[i]);
    }

    // Print the table header
    printf("\n\t CURRENT TIME \t PROCESS \t PRIORITY \t BURST TIME \t WAIT TIME \t TURNAROUND TIME\n");

    // Sort the processes based on their priorities
    for (i = 0; i < n_proc; i++)
    {
        for (int j = i + 1; j < n_proc; j++)
        {
            if (proc_priorities[i] > proc_priorities[j])
            {
                int temp = proc_priorities[i];
                proc_priorities[i] = proc_priorities[j];
                proc_priorities[j] = temp;

                temp = burst_times[i];
                burst_times[i] = burst_times[j];
                burst_times[j] = temp;

                temp = proc_ids[i];
                proc_ids[i] = proc_ids[j];
                proc_ids[j] = temp;
            }
        }
    }

    // Simulate a non-preemptive priority scheduling
    // if proc_priorities is lower, then the process has higher priority
    // for each proc_id, execute the process until the process is completed
    remaining_proc = n_proc;
    current_time = 0;
    waiting_time_avg = 0;
    turnaround_time_avg = 0;
    while (remaining_proc > 0)
    {
        for (i = 0; i < n_proc; i++)
        {
            // if the process is not yet completed,
            if (burst_times[i] > 0)
            {
                printf("\t %d \t\t P%d \t\t %d \t\t %d \t\t %d \t\t %d\n", current_time, proc_ids[i], proc_priorities[i], burst_times[i], current_time, current_time + burst_times[i]);
                waiting_time_avg += current_time;
                turnaround_time_avg += current_time + burst_times[i];
                current_time += burst_times[i];
                burst_times[i] = 0;
                remaining_proc--;
            }
        }
    }

    // Print the average waiting time and turnaround time
    printf("\nAverage waiting time: %.2f\n", waiting_time_avg / n_proc);
    printf("Average turnaround time: %.2f\n", turnaround_time_avg / n_proc);

    // Free the allocated memory
    free(proc_ids);
    free(burst_times);
    free(proc_priorities);

    return 0;
}