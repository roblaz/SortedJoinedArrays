// SortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define FIRSTARRAY_SIZE 5
#define SECONDARRAY_SIZE 9

void joinSortedArray(int* pFirstArray, int pFirstArray_Size, int* pSecondArray, int pSecondArray_Size, int* pMergedArray);

using namespace std;

int compare(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int iFirstArray[FIRSTARRAY_SIZE] = { 4, 2, 10, 8, 9 };
    int iSecondArray[SECONDARRAY_SIZE] = { 12, 7, 10, 8, 13, 23, 22, 30 };
    int iMergedArray[sizeof(iFirstArray) / sizeof(int) + sizeof(iSecondArray) / sizeof(int)];

    cout << "Merge sorted arrays\n";

    cout << "\n first array rolls:";
    for (int i = 0; i < FIRSTARRAY_SIZE; i++) {
        qsort(iFirstArray, FIRSTARRAY_SIZE, sizeof(int), compare);
        cout << " " << iFirstArray[i];
    }

    cout << "\n\n second array rolls:";
    for (int i = 0; i < SECONDARRAY_SIZE; i++) {
        qsort(iSecondArray, SECONDARRAY_SIZE, sizeof(int), compare);
        cout << " " << iSecondArray[i];
    }

    joinSortedArray(iFirstArray, FIRSTARRAY_SIZE, iSecondArray, SECONDARRAY_SIZE, iMergedArray);

}



void joinSortedArray(int* pFirstArray, int pFirstArray_Size, int* pSecondArray, int pSecondArray_Size, int* pMergedArray) {
    char chAnswer;
    int iMergedArray_Size = pFirstArray_Size + pSecondArray_Size;

    for (int i = 0; i < pFirstArray_Size; i++) {
        pMergedArray[i] = pFirstArray[i];
    }

    for (int i = 0; i < pSecondArray_Size; i++) {
        pMergedArray[i + pFirstArray_Size] = pSecondArray[i];
    }

    do
    {

        cout << "\nDo you want to see 2 sorted and joined arrays (Yes/No)? ";
        cin >> chAnswer;

        switch (toupper(chAnswer))
        {
            case 'Y':
                for (int i = 0; i < iMergedArray_Size; i++) {
                        cout << pMergedArray[i]; cout << " ";
                    }
                cout << endl;
                break;
            case 'N':
                break;
            default: cout << "\nPlease enter Y or N";
        }
    } while (toupper(chAnswer) != 'Y' & toupper(chAnswer) != 'N');
}
