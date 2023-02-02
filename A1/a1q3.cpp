/* -------------------------------------------------------------------------
 * This program simulates a single-server FIFO service node using arrival
 * times and service times read from a text file.  The server is assumed
 * to be idle when the first job arrives.  All jobs are processed completely
 * so that the server is again idle at the end of the simulation.   The
 * output statistics are the average interarrival time, average service
 * time, the average delay in the queue, and the average wait in the service
 * node.
 *
 * File Name              : ssq1.c  (Single Server Queue, version 1)
 * Authors           : Modified from Steve Park & Dave Geyer
 * Language          : ANSI C
 * Compile with      : gcc ssq1.c
 * Name: Sarah Ann Roy
 * Student Number: 0650615
 * COIS 4470H Assignment 1 - Question 3
 * -------------------------------------------------------------------------
 */

#include <stdio.h>

#define FILENAME "ssq1.dat" /* input data file */
#define START 0.0

/* =========================== */
double GetArrival(FILE *fp) /* read an arrival time */
/* =========================== */
{
    double a;

    fscanf(fp, "%lf", &a);
    return (a);
}

/* =========================== */
double GetService(FILE *fp) /* read a service time */
/* =========================== */
{
    double s;

    fscanf(fp, "%lf\n", &s);
    return (s);
}

/* ============== */
int main(void)
/* ============== */
{
    FILE *fp; /* input data file      */

    long index = 0;           /* job index            */
    long arrival_Num;         /* count arrival jobs */
    long departure_Num;       /* count departure jobs */
    long delay_Num;           /* count delay jobs */
    double arrival = START;   /* arrival time         */
    double delay;             /* delay in queue       */
    double service;           /* service time         */
    double wait;              /* delay + service      */
    double departure = START; /* departure time       */
    double t;                 /* add - SPECIFIED TIME 300/2000/6000 */
    double Max_delay = 0.0;   /* initial max delay time */
    double proportion = 0.0;  /* initial proportion of the delay */
    double t_num_jobs = 0;    /*Number of jobs at time = t*/
    struct
    {                        /* sum of ...           */
        double delay;        /*   delay times        */
        double wait;         /*   wait times         */
        double service;      /*   service times      */
        double interarrival; /*   interarrival times */
    } sum = {0.0, 0.0, 0.0};

    printf("Enter time for number of jobs in the system:");
    scanf("%lf\n", &t); // user inputs time t (300/2000/6000)

    fp = fopen("ssq1.dat", "r");
    // fp = fopen("q1b.dat", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Cannot open input file %s\n", FILENAME);
        return (1);
    }

    while (!feof(fp))
    {
        index++;
        arrival = GetArrival(fp);
        if (arrival <= t && departure > t)
        {
            //&&&&&-add code here
            t_num_jobs++; // increment the number of jobs at time t
        }
        if (arrival < departure)
        {
            delay = departure - arrival; /* delay in queue */
            //&&&&&&;  add code here
            delay_Num++; /*delay number */
            if (Max_delay < delay)
            {
                Max_delay = delay_Num; /*calculate maximum delay*/
            }
        }
        else
            delay = 0.0; /* no delay*/
        service = GetService(fp);
        wait = delay + service;
        departure = arrival + wait; /* time of departure */
        // if (departure <= t);
        //&&&&&&-add code here
        sum.delay += delay;
        sum.wait += wait;
        sum.service += service;
    }
    sum.interarrival = arrival - START;

    printf("\nfor %ld jobs\n", index);
    printf("   average interarrival time = %6.2f\n", sum.interarrival / index);
    printf("   average service time .... = %6.2f\n", sum.service / index);
    printf("   average delay ........... = %6.2f\n", sum.delay / index);
    printf("   average wait ............ = %6.2f\n", sum.wait / index);
    printf("   Maximum delay ............ = %6.2f\n", Max_delay);
    printf("   Proportion    ............ = %6.2f\n", proportion);
    printf("   At time %6.2f, %6.2f jobs are in the system \n", t, t_num_jobs);
    fclose(fp);
    return (0);
}