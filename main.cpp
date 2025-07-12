#include <iostream>
using namespace std;
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
void sort(int* array_to, int* array_from, int digits, int place, int index)
{
    int max = place;
    if(array_to[place] == 0)
    {
        array_to[place] = array_from[index];
    }
    else
    {

        int j = place;
        while(array_to[j] != 0 && j >= 0)
        {
            if(j > 0 && j >= max)
            {
                j--;
            }
            else
            {
                j = digits-1;
            }
        }
        array_to[j] = array_from[index];
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
    int array2[digits];
    initialize_array(array2, digits);

    // int array2[digits];
    // int array3[digits];
    // int array4[digits];
    // int array5[digits];
    // int array6[digits];
    // int array7[digits];
    // int array8[digits];
    // int array9[digits];
    // int array10[digits];

    for(int i = 0; i < digits; i++)
    {
        int digit_value = array[i] % 10;
        sort(array2, array, digits, digit_value, i);
    }
    print_array(array2, digits);
    cout << endl;
    insert_array(array, array2, digits);

    print_array(array2, digits);
    cout << endl;
    initialize_array(array2, digits);
    for(int i = 0; i < digits; i++)
    {
        int digit_value = 0;
        if(array[i] >= 10)
        {
            digit_value = array[i] % 100;
            digit_value = (digit_value / 10) % 10;
        }
        else
        {
            digit_value = i;
        }
        sort(array2, array, digits, digit_value, i);

}
    insert_array(array, array2, digits);
    print_array(array, digits);
    cout << endl;
    for(int i = 0; i < digits; i++)
    {
        array[i] = array2[i];
    }
    initialize_array(array2, digits);
    for(int i = 0; i < digits; i++)
    {
        int digit_value = 0;
        if(array[i] >= 100)
        {
            digit_value = array[i] % 1000;
            digit_value = (digit_value / 100) % 10;
        }
        else
        {
            digit_value = i;
        }
        sort(array2, array, digits, digit_value, i);
    }
        insert_array(array2, array2, digits);
        print_array(array, digits);
        cout << endl;

    }
int main()
{
    const int SIZE1 = 10;
    int array1[SIZE1] = {63, 82, 389, 720, 732, 736, 277, 436, 157, 16};
    radix_sort(array1,SIZE1);
    print_array(array1, SIZE1);

    return 0;
}
