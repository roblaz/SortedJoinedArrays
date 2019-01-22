// SortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define FIRSTARRAY_SIZE 5
#define SECONDARRAY_SIZE 9
#define RANDOM_MIN_VALUE 1
#define RANDOM_MAX_VALUE 100


void joinSortedArray(int* pFirstArray, int pFirstArray_Size, int* pSecondArray, int pSecondArray_Size, int* pMergedArray);

using namespace std;

int compare(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int iFirstArray[FIRSTARRAY_SIZE]; // = { 2, 4, 6, 8, 9 };
    int iSecondArray[SECONDARRAY_SIZE]; //= { 6, 7, 8, 10, 13, 20, 22, 30 };
    int iMergedArray[sizeof(iFirstArray) / sizeof(int) + sizeof(iSecondArray) / sizeof(int)];

    cout << "Merge sorted arrays\n";

    cout << "\n first array rolls:";
    for (int i = 0; i < FIRSTARRAY_SIZE; i++)
        iFirstArray[i] = (rand() % ((RANDOM_MAX_VALUE + 1) - RANDOM_MIN_VALUE) + 15);
    qsort(iFirstArray, FIRSTARRAY_SIZE, sizeof(int), compare);
    for (int i = 0; i < FIRSTARRAY_SIZE; i++)
        cout << " " << iFirstArray[i];

    cout << "\n\n second array rolls:";
    for (int i = 0; i < FIRSTARRAY_SIZE; i++)
        iFirstArray[i] = (rand() % ((RANDOM_MAX_VALUE + 1) - RANDOM_MIN_VALUE) + 15);
    qsort(iSecondArray, SECONDARRAY_SIZE, sizeof(int), compare);
    for (int i = 0; i < SECONDARRAY_SIZE; i++)
        cout << " " << iSecondArray[i];

    joinSortedArray(iFirstArray, FIRSTARRAY_SIZE, iSecondArray, SECONDARRAY_SIZE, iMergedArray);

    cout << "\n\n merged array rolls:";
    for (int i = 0; i < FIRSTARRAY_SIZE + SECONDARRAY_SIZE; i++)
        cout << " " << iMergedArray[i];
}



void joinSortedArray(int* pFirstArray, int pFirstArray_Size, int* pSecondArray, int pSecondArray_Size, int* pMergedArray) {
    char chAnswer;
    int iMergedArray_Size = pFirstArray_Size + pSecondArray_Size;
    int iTemp;

    for (int i = 0; i < pFirstArray_Size; i++) {
        pMergedArray[i] = pFirstArray[i];
    }

    /*
    for (int i = pFirstArray_Size; i < iMergedArray_Size; i++) {
        pMergedArray[i] = pSecondArray[i - pFirstArray_Size];
    }
    */

    for (int i = 0; i < pSecondArray_Size; i++) {
        pMergedArray[i + pFirstArray_Size] = pSecondArray[i];
    }

    do
    {

        cout << "\nDo you want use quick sort (Yes/No)? ";
        cin >> chAnswer;

        switch (toupper(chAnswer))
        {
            case 'Y':
                qsort(pMergedArray, iMergedArray_Size, sizeof(int), compare);
                break;
            case 'N':
                for (int i = 0; i < iMergedArray_Size; i++)
                {
                    for (int j = 0; j < iMergedArray_Size - 1; j++)
                    {
                        if (pMergedArray[j] > pMergedArray[j + 1])
                        {
                            iTemp = pMergedArray[j];
                            pMergedArray[j] = pMergedArray[j + 1];
                            pMergedArray[j + 1] = iTemp;
                        }
                    }
                }
                break;
            default: cout << "\nPlease enter Y or N";
        }
    } while (toupper(chAnswer) != 'Y' & toupper(chAnswer) != 'N');
}
