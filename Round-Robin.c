/*  C Program to implement Round Robin Process Scheduling Algorithm.
 *  Arrival time of the processes is not considered.
 *  This program draws the Gantt Chart for the list of processes.
 *  Number of processes is limited to 10.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void roundRobin(int burst_time[], int no_of_processes, int quantum);
void drawGanttChart(int burst_time[], int no_of_processes, int quantum);

int main(void)
{
    int no_of_processes, bt[MAX], quantum;
    
    printf("Enter the number of processes (Max 10): ");
    scanf("%d", &no_of_processes);
    
    printf("\nEnter the burst time of each process:\n");
    for (int i = 0; i < no_of_processes; ++i)
    {
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    
    printf("\nEnter the time quantum: ");
    scanf("%d", &quantum);
    
    printf("\n");
    
    roundRobin(bt, no_of_processes, quantum);
    
    printf("\n\n");
    
    return 0;
}

void drawGanttChart(int burst_time[], int no_of_processes, int quantum)
{
    /* This function works the same way as 'roundRobin()' does,
    difference being that this function draws the Gantt chart. */
    
    int remaining_time[MAX];
    int total = 0;
    int remain = no_of_processes;
    int flag = 0;
    int i;
    
    printf("\nGantt Chart:\n\n");
    
    for (int i = 0; i < no_of_processes; ++i)
    {
        total += burst_time[i];
    }
    
    for (int i = 0; i < no_of_processes; ++i)
    {
        remaining_time[i] = burst_time[i];
    }
    
    for (int process = 0; remain != 0; )
    {
        if (remaining_time[process] <= quantum && remaining_time[process])
        {
            printf("|P%d ", process + 1);
            remaining_time[process] = 0;
            
            flag = 1;
        }
        
        else if (remaining_time[process] > 0)
        {
            printf("|P%d ", process + 1);
            remaining_time[process] -= quantum;
        }
        
        if (flag == 1)
        {
            --remain;
            
            flag = 0;
        }
        
        if (process == no_of_processes - 1)
        {
            process = 0;
        }
        
        else
        {
            ++process;
        }
    }
    
    printf("|");
    
    flag = 0;
    
    // Print the timeline.
    printf("\n");
    for (i = 0; i <= total ; i += quantum)
    {
        printf("%d\t", i);
        
        flag = 1;
    }
    
    /* If the last process's end time is not the multiple of the quantum,
     Then print it straight away. */
    if ((i % total) != 0)
    {
        printf("%d", total);
    }
    
    printf("\n\n");
}

void roundRobin(int burst_time[], int no_of_processes, int quantum)
{
    int remaining_time[MAX];     //Temporary array for storing the remaining time of each process.
    int waiting_time = 0;       //Total waiting time.
    int turnaround_time = 0;    //Total turnaround time.
    int flag = 0;
    
    // Copy the burst times of each process into the temporary array.
    for (int i = 0; i < no_of_processes; ++i)
    {
        remaining_time[i] = burst_time[i];
    }
    
    int process = 0;            //Current process.
    int time = 0;               //Turnaround around time of each process.
    int remain = no_of_processes;
    
    printf("Process No.\t\tWaiting Time\tTurnaround Time\n");
    
    while (remain != 0)
    {
        // Remaining time is less than the quantum and also greater than 0.
        if (remaining_time[process] <= quantum && remaining_time[process] > 0)
        {
            time += remaining_time[process]; // The remaining time is added to the turnaround time of the process.
            remaining_time[process] = 0;    //Since the remaining time is lower than the quantum we set it to 0.
            
            flag = 1;
        }
        
        // Remaining time is greater than 0.
        else if (remaining_time[process] > 0)
        {
            time += quantum;
            remaining_time[process] -= quantum;
        }
        
        // Execute only if the remaining time of a process is set to 0.
        // Cannot enter this statement if the remaining time evaluates to 0 in line 155.
        if (flag == 1)
        {
            --remain;
            printf("Process[%d]\t\t\t%d\t\t\t\t%d\n", process + 1, time - burst_time[process], time);
            waiting_time += time - burst_time[process];
            turnaround_time += time;
            
            flag = 0;
        }
        
        // Check if the maximum number of processes is reached.
        if (process == no_of_processes - 1)
        {
            process = 0;    // If yes, go back to the first process.
        }
        
        else
        {
            ++process;  // Else, go to the next process.
        }
    }
    
    drawGanttChart(burst_time, no_of_processes, quantum);
    
    printf("Average turnaround time: %.2f\n", (float) turnaround_time / no_of_processes);
    printf("Average waiting time: %.2f", (float) waiting_time / no_of_processes);
}

