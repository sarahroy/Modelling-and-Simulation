//===========================================================file: 4470A1_1====
//=  Simulation of booting-up multiple server with failure probability        =
//=============================================================================
//=  Notes: This is assignment #1 question 1 for COIS 4470H                    =
//=  Name: Sarah Ann Roy                                                      =
//=  Student Number: 0650615                                                  =
//=---------------------------------------------------------------------------=

//----- Include files ---------------------------------------------------------
#include <stdio.h>  // Needed for printf()
#include <stdlib.h> // Needed for rand() and RAND_MAX

//----- Constants -------------------------------------------------------------
#define FALSE 0           // Boolean false
#define TRUE 1            // Boolean true
#define NUM_DAYS 10000    // Number of days to simulate 10000
#define NUM_SERVERS 10    // Number of servers
#define FAIL_PERCENT 0.03 // Percent of time a boot-up fails

//----- Function prototypes ---------------------------------------------------
double rand_val(void); // Generate random value between 0.0 and 1.0

//===== Main program ==========================================================
int main(void)
{
    int i, j;                // Loop counters
    int sum_fail;            // Counter for fail days
    int fail;                // Failure flag (set to TRUE or FALSE)
    double on_time;          // Percentage of days on which the company has business
                             // on time (all the ten server are successfully re-booted)
    int fail_servers_number; // number of failed servers (counted each day) initialized to zero

    // Initialize sum_fail to zero
    sum_fail = 0; /* &&& insert code here &&& */

    // Output a "running" banner
    printf(">>> The simulation is running for %d days... \n", NUM_DAYS);

    // Run the simulation for NUM_DAYS
    for (i = 0; i < NUM_DAYS; i++)
    {
        // Loop through a boot-up of NUM_SERVERS setting fail to TRUE on failure
        fail = FALSE;
        fail_servers_number = 0;
        for (j = 0; j < NUM_SERVERS; j++) // looping through the servers 1-10
        {
            double val = rand_val(); // get random number for the server
            // printf("Random value generated = %6.3f \n", val);
            if (val < FAIL_PERCENT) /* &&& insert code here &&& */
            {
                fail = TRUE;
                fail_servers_number++; // increment the number of failed servers
            }
        }
        // Increment the number of days with a failure
        if (fail == TRUE && fail_servers_number > 1)
            sum_fail++; /* &&& insert code here &&& */
    }
    printf("Number of failed days = %d \n", sum_fail);

    // Compute percent of days on which the company has business on time
    on_time = (((double)NUM_DAYS - sum_fail) / (double)NUM_DAYS) * 100; /* &&& insert code here &&& */

    // Output results
    printf("============================================================= \n");
    printf("==     *** Results from server boot-up simulation ***     == \n");
    printf("============================================================= \n");
    printf("=  PROBLEM INPUT:                                             \n");
    printf("=    Number of days simulated = %d days    \n", NUM_DAYS);
    printf("=    Number of servers        = %d servers \n", NUM_SERVERS);
    printf("=    Boot-up failure percent  = %6.3f %%   \n", FAIL_PERCENT);
    printf("============================================================= \n");
    printf("=  PROBLEM OUTPUT:                                            \n");
    printf("=    Days the business is on time = %6.3f %%   \n", on_time);
    printf("============================================================= \n");

    return 0;
}

//=============================================================================
//= Function to return a random value between 0.0 and 1.0                     =
//=============================================================================
double rand_val(void)
{
    double z; // Random value to be generated and returned

    // Use rand() and RAND_MAX defined in stdlib()
    z = (double)rand() / RAND_MAX;

    return (z);
}