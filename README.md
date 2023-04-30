# Monte Carlo π calculation

All the c files here calculate the value of pi using the monte carlo method, base in a 10 million points/values case.

<br>

## **Seqential**

`pi_sequential.c` does it in a sequential manner.
```
 gcc pi_sequential.c -o pi.out
 ./pi.out
```

<br>

## **Parallel**

`pi_parallel_v1.c` &ensp; divides generation/calculation of all the points use to make the pi stimation between all the threads
```
 gcc -fopenmp pi_parallel_v1.c -o pi_v1.out
 ./pi_v1.out
```

To specify the amount of threads you want to use, run:
```
 OMP_NUM_THREADS=12 ./pi_v1.out
```

<br>

`pi_parallel_v2.c` &ensp; generates/calculates the 10 million points in each thread, and then pools all those points together to make a final stimation of pi
```
 gcc -fopenmp pi_parallel_v2.c -o pi_v2.out
 ./pi_v2.out
```

To specify the amount of threads you want to use, run:
```
 OMP_NUM_THREADS=8 ./pi_v2.out
```