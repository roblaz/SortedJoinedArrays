// SortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define FIRSTARRAY_SIZE 5
#define SECONDARRAY_SIZE 9

int JoinArrays(int* pFirstArray, int pFirstArray_Size, int* pSecondArray, int pSecondArray_Size, int* pMergedArray);

using namespace std;

int main()
{
    int iFirstArray[FIRSTARRAY_SIZE] = { 1, 2, 5, 8, 9 };
    int iSecondArray[SECONDARRAY_SIZE] = { 5, 7, 10, 15, 19, 22, 25, 30, 33 };
    int iMergedArray[sizeof(iFirstArray) / sizeof(int) + sizeof(iSecondArray) / sizeof(int)];

    JoinArrays(iFirstArray, FIRSTARRAY_SIZE, iSecondArray, SECONDARRAY_SIZE, iMergedArray);
}

int JoinArrays(int* pFirstArray, int pFirstArray_Size, int* pSecondArray, int pSecondArray_Size, int* pMergedArray) {
    int iMergedArray_Size = pFirstArray_Size + pSecondArray_Size;
    int iTemp;

    for (int i = 0; i < pFirstArray_Size; i++) {
        pMergedArray[i] = pFirstArray[i];
    }

    for (int i = 0; i < pSecondArray_Size; i++) {
        pMergedArray[i + pFirstArray_Size] = pSecondArray[i];
    }


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

    for (int i = 0; i < iMergedArray_Size; i++) {
        cout << pMergedArray[i] << " ";
    }
}


