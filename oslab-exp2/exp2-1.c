#include <stdio.h>

int main()
{
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;
    printf("\033[H\033[J"); // ANSI escape code to clear screen
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    for (i=0;i<n;i++) {
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for (i=1;i<n;i++) {
        wt[i] = wt[i-1] +bt[i-1];
        tat[i] = tat[i-1] +bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    
    for(i=0;i<n;i++) {
        printf("\t P%d \t\t %d \t\t %d \t\t %d\n", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time -- %f", wtavg/n);
    printf("\nAverage Turnaround Time -- %f", tatavg/n);
    printf("\n");
    getchar(); // Use getchar() instead of getch()
    return 0;
}