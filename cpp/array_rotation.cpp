//https://www.geeksforgeeks.org/array-rotation/
// C++ program to rotate an array by
// d elements
//It contains debug lines
#include <iostream>
using namespace std;

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*Fuction to get gcd of a and b*/
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    else
        return gcd(b, a % b);
}

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n)
{
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++)
    {
        cout << "i = " << i << endl;
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;

        while (1)
        {
            cout << "j = " << j << endl;
            int k = j + d;
            cout << "k = " << k << endl;
            if (k >= n)
                k = k - n;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
            // printArray(arr, n);
        }
        arr[j] = temp;
        printArray(arr, n);
    }
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function calling
    leftRotate(arr, 6, n);
    // printArray(arr, n);

    return 0;
}
