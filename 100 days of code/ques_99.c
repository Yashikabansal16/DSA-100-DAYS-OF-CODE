/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets
reaching the destination.Sort cars by position in descending order and calculate time
to reach target.*/

#include <stdlib.h>

// Pair struct
typedef struct {
    int pos;
    int speed;
} Car;

// Comparator: sort by position descending
int cmp(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->pos - c1->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed) {
    // Create array of cars
    Car* cars = (Car*)malloc(positionSize * sizeof(Car));

    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    // Sort by position descending
    qsort(cars, positionSize, sizeof(Car), cmp);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < positionSize; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > lastTime) {
            fleets++;          // new fleet
            lastTime = time;   // update slowest time
        }
        // else: joins existing fleet
    }

    free(cars);
    return fleets;
}