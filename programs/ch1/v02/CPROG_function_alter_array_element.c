#include <stdio.h>

void print_array(int array[], int limit);

main() {
    int array_size = 10;
    int my_array[array_size];
    int i;
    for (i=0; i<10; ++i) {
	my_array[i] = i+1;
    }
    printf("Now printing array:\n");
    print_array(my_array, array_size);
    printf("array_size remains the same: %d\n", array_size);
    return 0;
}

void print_array(int array[], int limit) {
    int i;
    --limit;
    array[4] = 100;//randomly alter 5th element of array, to prove it's possible
    for (i = 0; i <= limit; --limit) {
	printf("array[i] = %d\n", array[limit]);
    }
}
    
