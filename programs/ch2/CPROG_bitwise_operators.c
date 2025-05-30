#include <stdio.h>

int is_in_use(int car_num);
void set_in_use(int car_num);
void set_unused(int car_num);
void flip_use_state(int car_num);

int in_use = 0;

int main(void)
{

    char cars[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    set_in_use(cars[0]);
    printf("car in use is: %d\n", is_in_use(cars[0]));
    set_in_use(cars[1]);
    printf("car in use is: %d\n", is_in_use(cars[1]));
    set_in_use(cars[2]);
    printf("car in use is: %d\n", is_in_use(cars[2]));
    set_in_use(cars[3]);
    printf("car in use is: %d\n", is_in_use(cars[3]));
    set_in_use(cars[4]);
    printf("car in use is: %d\n", is_in_use(cars[4]));
    set_in_use(cars[5]);
    printf("car in use is: %d\n", is_in_use(cars[5]));
    set_in_use(cars[6]);
    printf("car in use is: %d\n", is_in_use(cars[6]));
    set_in_use(cars[7]);
    printf("car in use is: %d\n", is_in_use(cars[7]));
    
    set_in_use(cars[4]);
    printf("car in use is: %d\n", is_in_use(cars[5]));
    printf("\n\n");
    set_unused(cars[4]);
    printf("car in use is: %d\n", is_in_use(cars[5]));
}

int is_in_use(int car_num)
{

    return in_use & 1 << car_num;
}

void set_in_use(int car_num)
{

    in_use = in_use | 1 << car_num;
}

void set_unused(int car_num)
{

    in_use = in_use & ~(1 << car_num);
}

void flip_use_state(int car_num)
{
    in_use = in_use ^ (1 << car_num);
}
