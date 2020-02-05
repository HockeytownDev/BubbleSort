#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 5000

using namespace std;

// function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int comparisons = 0;
    int assignments = 0;
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        //inner loop
        for (j = 0; j < n-i-1; j++)
        {
            comparisons++;
            if (arr[j] > arr[j+1])
            {
                assignments++;
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

    cout << "Bubble Sort" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Assignments: " << assignments << endl;
}

// function to selection bubble sort
void selectionSort(int arr[], int n)
{
    int comparisons = 0;
    int assignments = 0;
    int i, j, min;

    // sorting loop
    for (i = 0; i < n-1; i++)
    {
        // inner_loop
        min = i;
        for (j = i+1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[min])
            {
                min = j;
            }

        }

        // Swap the found minimum element with the first element
        assignments++;
        swap(&arr[min], &arr[i]);
    }

    cout << "\nSelection Sort" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Assignments: " << assignments << endl;
}

// Driver program to test above functions
int main()
{
    srand((unsigned)time(0));

    int array1[MAX];
    int array2[MAX];

    // generating random list1
    for(int i=0; i < MAX; i++)
    {
        array1[i] = rand()%1000;
    }

    // copying list1 to list2
    for(int i=0; i < MAX; i++)
    {
        array2[i] = array1[i];
    }

    //sorting list1 using bubble sort
    bubbleSort(array1, MAX);

    //sorting list1 using selection sort
    selectionSort(array2, MAX);
    return 0;
}
