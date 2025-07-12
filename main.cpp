/**** Problem 12.4 - Chapter 12, Project C
*---------------------------------------------
***** The radix sort algorithm sorts an array of n integers with d digits,
***** using ten auxiliary arrays. First place each value v into the auxiliary array whose
***** index corresponds to the last digit of v. Then move all values back into the original array,
***** preserving their order. Repeat the process, now using the next-to-last (tens) digit,
***** then the hundreds digit, and so on. What is the big-Oh time of this algorithm
***** in terms of n and d? When is this algorithm preferable to merge sort?

// Programmer - Ashley Jacobson
// Tester - Giannfranco Brance

// Group Project C //
/***** Members *****/
/***** Ashley Jacobson *****/
/***** Giannfranco Brance *****/
/***** Audrey Tapia *****/
/***** Heily Cabrera Guerrero *****/

#include <iostream>
#include <string>

#include <iostream>
using namespace std;

void initialize_array(int* array, int digits);
void print_array(int* array, int digits);
void insert_array(int* to_array, int* from_array, int digits);
void radix_sort(int *array, int digits);

int main()
{
    const int SIZE1 = 10;
    int array1[SIZE1] = {63, 82, 389, 720, 732, 736, 277, 436, 157, 16};
    cout << "Before sort: " << endl;
    print_array(array1, SIZE1);
    cout << endl;
    cout << "After sort: " << endl;
    radix_sort(array1,SIZE1);
    print_array(array1, SIZE1);
    cout << endl;

    return 0;
}
void initialize_array(int* array, int digits)
{
    for (int i = 0; i < digits; i++)
    {
        array[i] = 0;
    }
}
void print_array(int* array, int digits)
{
    for(int i = 0; i < digits; i++)
    {
        cout << array[i] << " ";
    }
}

void insert_array(int* to_array, int* from_array, int digits)
{
    for(int i = 0; i < digits; i++)
    {
        to_array[i] = from_array[i];
    }
}
void radix_sort(int *array, int digits)
{
    /************* 1s place *************/
    int count[10];
    int temp_array[digits];
    initialize_array(count, 10);
    initialize_array(temp_array, digits);
    // int max = 0;

    for(int i = 0; i < digits; i++)
    {
        int digit_value = array[i] % 10;
        count[digit_value]++;
    }

    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }

    for(int i = digits-1; i >=  0; i--)
    {
        int digit_value = array[i] % 10;
        temp_array[count[digit_value]-1] = array[i];
        count[digit_value]--;
    }
    insert_array(array,temp_array, digits);

    /************* 10s place *************/

    initialize_array(count, 10);
    initialize_array(temp_array, digits);

    for(int i = 0; i < digits; i++)
    {
        int digit_value = (array[i] / 10) % 10;
        count[digit_value]++;
    }

    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }

    for(int i = digits-1; i >=  0; i--)
    {
        int digit_value = (array[i] / 10) % 10;
        temp_array[count[digit_value]-1] = array[i];
        count[digit_value]--;
    }
    insert_array(array,temp_array, digits);

    /************* 100s place *************/

    initialize_array(count, 10);
    initialize_array(temp_array, digits);

    for(int i = 0; i < digits; i++)
    {
        int digit_value = (array[i] / 100) % 10;
        count[digit_value]++;
    }

    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }

    for(int i = digits-1; i >=  0; i--)
    {
        int digit_value = (array[i] / 100)% 10;
        temp_array[count[digit_value]-1] = array[i];
        count[digit_value]--;
    }
    insert_array(array,temp_array, digits);
}