/*  C Progrma to implement Priority Process Scheduling Algorithm.
 *  Number of processes is limited to 10.
 *  Lower number has higher priority.
 *  This program also draws the Gantt Chart for the given processes.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void drawGanttChart(int pid[], int priority[], int burst_time[], int no_of_processes);
void priorityScheduling(int pid[], int priority[], int burst_time[], int no_of_processes);

int main(void)
{
    int pid[MAX], burst_time[MAX], priority[MAX], no_of_processes;
    
    printf("Enter the number of processes: ");
    scanf("%d", &no_of_processes);
    printf("\n");
    
    printf("Enter the burst time of each process:\n");
    for (int i = 0; i < no_of_processes; ++i)
    {
        printf("Enter the burst time of process %d: ", (i + 1));
        scanf("%d", &burst_time[i]);
        
        pid[i] = (i + 1);
    }
    printf("\n");
    
    printf("Enter the priorities of each process:\n");
    for (int i = 0; i < no_of_processes; ++i)
    {
        printf("Enter the priority of process %d: ", (i + 1));
        scanf("%d", &priority[i]);
    }
    printf("\n");
    
    priorityScheduling(pid, priority, burst_time, no_of_processes);
    
    printf("\n");
    
    return 0;
}

void drawGanttChart(int pid[], int priority[], int burst_time[], int no_of_processes)
{
    int total = burst_time[0];
    
    printf("Gantt Chart:\n\n");
    for (int i = 0; i < no_of_processes; ++i)
    {
        printf("|P%d ", pid[i]);
        
    }
    printf("|\n");
    
    printf("0\t%d\t", total);
    for (int i = 1; i < no_of_processes; ++i)
    {
        total += burst_time[i];
        
        printf("%d\t", total);
    }
    
    printf("\n\n");
}

void priorityScheduling(int pid[], int priority[], int burst_time[], int no_of_processes)
{
    int waiting_time = 0, turnaround_time = 0;
    int total = 0;
    
    // Sort the processes based on their priorities using bubble sort.
    for (int i = 0; i < (no_of_processes - 1); ++i)
    {
        for (int j = 0; j < (no_of_processes - i - 1); ++j)
        {
            if (priority[j + 1] < priority[j])
            {
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
                
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
                
                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;
            }
        }
    }
    
    // Rest of the program functions the same way as FCFS Algorithm works.
    printf("\nProcess No.\t\tWaiting Time\t\tTurnaround Time\n");
    for (int i = 0; i < no_of_processes; ++i)
    {
        total += burst_time[i];
        
        printf("\t%d\t\t\t\t%d\t\t\t\t\t%d\n", pid[i], (total - burst_time[i]), total);
        
        waiting_time += (total - burst_time[i]);
        turnaround_time += total;
    }
    printf("\n");
    
    drawGanttChart(pid, priority, burst_time, no_of_processes);
    
    printf("The average waiting time is: %.2f\n", ((float) waiting_time / no_of_processes));
    printf("The average turnaround time is: %.2f\n", ((float) turnaround_time / no_of_processes));
}
