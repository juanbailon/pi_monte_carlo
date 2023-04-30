#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_POINTS 10000000


double pi_montecarlo(int iterations){
    // seed the random number generator with the current time
    srand(time(NULL));

    clock_t start_time, end_time;
    double total_time;
    int dots_inside_circle = 0;

    start_time = clock();

    for(int i=0; i<iterations; i++){
        // generate a random number between the interval (0, 1)
        double x = (double) rand()/RAND_MAX;
        double y = (double) rand()/RAND_MAX;

        double p = x*x + y*y;
        
        //checks if the point (x,y) is inside the circle
        if(p<=1){
            dots_inside_circle++;
        }
    }

    double pi = 4.0 * dots_inside_circle/iterations;

    end_time = clock();
    total_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Total execution time: %lf seconds. \n", total_time);

    return pi; 
}


int main(){
    
    double pi = pi_montecarlo(TOTAL_POINTS);

    printf("pi = %f \n", pi);

    return 0;
}