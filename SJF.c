/*	C Program to implement Shortest Job First (SJF) Process Scheduling Algorithm.
 *	Number of processes is limited to 10.
 *	This program draws the Gantt Chart for the given processes.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

/*void drawGanttChart(int pid[], int burst_time[], int no_of_processes);*/
void shortestJobFirst(int pid[], int burst_time[], int no_of_processes);

int main(void)
{
    int burst_time[MAX], pid[MAX];
    int no_of_processes;
    
    printf("Enter the number of processes: ");
    scanf("%d", &no_of_processes);
    printf("\n");
    
    printf("Enter the burst times of each process:\n");
    for (int i = 0; i < no_of_processes; ++i)
    {
        printf("Enter the burst time of process %d: ", (i + 1));
        scanf("%d", &burst_time[i]);
        
        pid[i] = (i + 1);
    }
    
    shortestJobFirst(pid, burst_time, no_of_processes);
    
    printf("\n");
    
    return 0;
}

void drawGanttChart(int pid[], int burst_time[], int no_of_processes)
{
    // Works the same way as the function in FCFS Algorithm does.
    
    int total = burst_time[0];
    
    printf("Gantt Chart:\n");
    
    for (int i = 0; i < no_of_processes; ++i)
    {
        printf("|P%d ", pid[i]);
    }
    printf("|\n");
    
    printf("0\t%d\t", total);   //Waiting time of process 1 is always 0.
    for (int i = 1; i < no_of_processes; ++i)
    {
        total += burst_time[i];
        
        printf("%d\t", total);
    }
    
    printf("\n\n");
}

void shortestJobFirst(int pid[], int burst_time[], int no_of_processes)
{
    int waiting_time = 0, turnaround_time = 0;
    int total = 0;
    
    // Sort the arrays in descending order of the burst time using bubble sort.
    for (int i = 0; i < (no_of_processes - 1); ++i)
    {
        for (int j = 0; j < (no_of_processes - i - 1); ++j)
        {
            if (burst_time[j] > burst_time[j + 1])
            {
                int temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;
                
                temp = pid[j];
                pid [j] = pid[j + 1];
                pid[j + 1] = temp;
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
    
    drawGanttChart(pid, burst_time, no_of_processes);
    
    printf("The average waiting time is: %.2f\n", ((float) waiting_time / no_of_processes));
    printf("The average turnaround time is: %.2f\n", ((float) turnaround_time / no_of_processes));
}
