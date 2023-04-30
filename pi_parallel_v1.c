#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define TOTAL_POINTS 10000000


void pi_montecarlo(int iterations){
    // seed the random number generator with the current time
    srand(time(NULL));

    double start_time, end_time;
    double time_used;
    int dots_inside_circle = 0;

    start_time = omp_get_wtime();

    #pragma omp parallel reduction(+:dots_inside_circle)
    {

        int t_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();
        int iterations_per_thread = iterations / total_threads;

        #pragma omp for
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

        double pi = 4.0 * dots_inside_circle/iterations_per_thread;

        printf("Treahd_id: %d  in: %d totales: %d  pi = %f\n", t_id, dots_inside_circle, iterations_per_thread, pi);
    }


    double pi = 4.0 * dots_inside_circle/iterations;
    printf("Considerando todos los hilos, in: %d totales: %d  pi = %f\n", dots_inside_circle, dots_inside_circle, pi);

    end_time = omp_get_wtime();
    time_used = end_time - start_time;

    printf("Tiempo total: %f segundos \n", time_used);

}


int main(){
    
    pi_montecarlo(TOTAL_POINTS);

    return 0;
}