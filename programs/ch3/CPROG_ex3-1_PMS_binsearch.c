/*
  Exercise 3-1. Our binary search makes two tests inside the loop,
  when one would suffice (at the price of more tests outside.)
  Write a version with only one test inside the loop and measure
  the difference in run-time.
*/

#include <stdio.h>
#include <time.h>


int binsearch(int x, int v[], int n);
int PMS_binsearch(int x, int v[], int n);

int COUNT;
//#define ARRAY_MAX 65535
#define ARRAY_MAX 1073741

int main()
{

    int i, v;
    int array[ARRAY_MAX];

    for (i = 0, v = 0; i < ARRAY_MAX; i++, v += 2) {
	array[i] = v;
    }
    /* for (i = 0; i < ARRAY_MAX; i++) */
    /* 	printf("%4d%c", array[i], i%10==9 ? '\n' : ' '); */

    
    int x = 9; // the value we're trying to find in array[]

    clock_t start, end;

    printf("calling PMS_binsearch()...\n");
    start = clock(); // start the clock
    int result = PMS_binsearch(x, array, ARRAY_MAX); // do the search
    end = clock(); // stop the clock
    printf("start time: %lu\n",start);
    printf("end time: %lu\n",end);
    printf("total time taken: %lu\n", end - start);
    printf("CLOCKS_PER_SEC %lu\n",CLOCKS_PER_SEC);


    if (result >= 0)
	printf("found number %d at index: %d\n",x, result);
    else
	printf("number %d not found in array\n", x);
    printf("COUNT = %d\n", COUNT);

    return 0;
}


/* K&R binsearch */
int binsearch(int x, int v[], int n)
{
    
    int low, high, mid;
    low = 0;
    high = n - 1;
    COUNT = 0;
    while (low <= high) {
	mid = (low + high) / 2;
	if (x < v[mid]) {
	    high = mid - 1;
	    COUNT++;
	}
	else if (x > v[mid]) {
	    low = mid + 1;
	    COUNT++;
	}
	else return mid;
    }
    return -1; //failed to find x in v[]
}

/* PMS binsearch */
int PMS_binsearch(int x, int v[], int n)
{

    int low, high, mid;
    low = 0;
    high = n - 1;
    COUNT = 0;
    while (low < high) {
	mid = (low + high) / 2;
	if (x <= v[mid]) {
	    high = mid;
	    COUNT++;
	}
	else low = mid + 1;
    }
    if (x == v[mid])
	return mid;
    else if (x == v[low]) // or x == v[high]
	return low;
    else
	return -1; // failed to find x in v[]
}

