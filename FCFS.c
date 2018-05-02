/*  C Program to implement FCFS Process Scheduling Algorithm.
 *  Number of processes is limited to 10.
 *  This program draws Gantt Chart for the given processes.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void drawGanttChart(int burst_time[], int no_of_processes);
void firstComeFirstServe(int burst_time[], int no_of_processes);

int main(void)
{
    int burst_time[MAX], no_of_processes;
    
    printf("Enter the number of processes: ");
    scanf("%d", &no_of_processes);
    printf("\n");
    
    printf("Enter the burst time of each process:\n");
    for (int i = 0; i < no_of_processes; ++i)
    {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    
    firstComeFirstServe(burst_time, no_of_processes);
    
    printf("\n");
    
    return 0;
}

void drawGanttChart(int burst_time[], int no_of_processes)
{
    /*  In FCFS, as processes come they are served.
     *  The Gantt Chart hence shows the burst time of each process in the same
        order as they came.
    */
    
    int total = burst_time[0];
    
    printf("Gantt Chart:\n");
    
    for (int i = 0; i < no_of_processes; ++i)
    {
        printf("|P%d ", (i + 1));
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

void firstComeFirstServe(int burst_time[], int no_of_processes)
{
    int waiting_time = 0, turnaround_time = 0;
    int total = 0;
    
    printf("\nProcess No.\t\tWaiting Time\t\tTurnaround Time\n");
    for (int i = 0; i < no_of_processes; ++i)
    {
        total += burst_time[i];
        
        printf("\t%d\t\t\t\t%d\t\t\t\t\t%d\n", (i + 1), (total - burst_time[i]), total);
        
        waiting_time += (total - burst_time[i]);
        turnaround_time += total;
    }
    printf("\n");
    
    drawGanttChart(burst_time, no_of_processes);
    
    printf("The average waiting time is: %.2f\n", ((float) waiting_time / no_of_processes));
    printf("The average turnaround time is: %.2f\n", ((float) turnaround_time / no_of_processes));
}
