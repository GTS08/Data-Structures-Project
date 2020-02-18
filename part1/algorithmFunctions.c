/* �� ������ ���� �������� ��� ����������� �� ��� ������ ������������
�� ���������� ��� ����� ��� �������� ���������� �����������. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <windows.h>
#include "algorithmFunctions.h"


/* ����������� ��� ������������ ������ �� �������� ��������� ��������
��� ����� ������������� ��� dataSet ������. */

void initArray(int *pinakas, int megethos, int dataSet){

    FILE *fp = NULL;

    switch(dataSet){
        case 1:
            /* ��������� �� ������ dataSet.txt �� ������ "r" ��� �� �� ���������� */
            fp = fopen("dataSetRandom.txt", "r");
            break;

        case 2:
            /* ��������� �� ������ dataSet.txt �� ������ "r" ��� �� �� ���������� */
            fp = fopen("dataSetNormal.txt", "r");
            break;

        case 3:
            /* ��������� �� ������ dataSet.txt �� ������ "r" ��� �� �� ���������� */
            fp = fopen("dataSetUniform.txt", "r");
            break;

        default:
            printf("Default case of timeCounter1 function.\n");
            break;
    }

    if(fp == NULL){
        printf("ERROR: Data set wasn't opened. Exiting...\n");
        exit(0);
    }

    /* ��������� ��� ������ �� ���� �������� ��������� */
    int i;
    for(i=0; i<megethos; i++){
        fscanf(fp, "%d", &pinakas[i]);
    }

    if(fp != NULL){
        fclose(fp);
    }

}


/* ��������� �� �������� ��� ������ ��������� �� �������. */

void printArray(int *pinakas, int megethos){

    int i;
    printf("Elements of array: \n[");
    for(i=0; i<megethos-1; i++){
        printf("%d, ", pinakas[i]);
    }
    printf("%d]\n\n", pinakas[megethos-1]);
}


/* ��������� ��� ������� ��� ��������� ����������� ������� �� �� ������ algorithmSelection ���
������� ��� ����� ��� ���������� ��� �� ���������� �� ������������. */

double timeCounter1(int algorithmSelection, int *pinakas, int megethos){

    LARGE_INTEGER startingTime, endingTime, timeSpent, frequency;

    QueryPerformanceFrequency(&frequency);

    switch(algorithmSelection){
        case 1:
            QueryPerformanceCounter(&startingTime);
            bubbleSort(pinakas, megethos);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        case 2:
            QueryPerformanceCounter(&startingTime);
            insertionSort(pinakas, megethos);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        case 3:
            QueryPerformanceCounter(&startingTime);
            selectionSort(pinakas, megethos);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        case 4:
            QueryPerformanceCounter(&startingTime);
            mergeSort(pinakas, 0, megethos-1);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        case 5:
            QueryPerformanceCounter(&startingTime);
            quickSort(pinakas, 0, megethos-1);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        case 6:
            QueryPerformanceCounter(&startingTime);
            heapSort(pinakas, megethos);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        default:
            printf("Default case of timeCounter function.\n");
            break;
    }

    return (double)timeSpent.QuadPart/1000000000;
}


/* ��������� ��� ������� ��� ��������� ���������� ������� �� �� ������ algorithmSelection ���
������� ��� ����� ��� ���������� ��� �� ���������� �� ������������. */

double timeCounter2(int algorithmSelection, int *pinakas, int megethos, int value, int printResult){

    int res;
    LARGE_INTEGER startingTime, endingTime, timeSpent, frequency;

    QueryPerformanceFrequency(&frequency);

    switch(algorithmSelection){
        case 1:
            QueryPerformanceCounter(&startingTime);
            res=linearSearch(pinakas, megethos, value);
            QueryPerformanceCounter(&endingTime);

            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;

            if(printResult==1){
                if(res==-1)
                    printf("Value %d was not found.", value);
                else
                    printf("Value %d was found at location %d.", value, res);
            }
            break;

        case 2:
            heapSort(pinakas, megethos);

            QueryPerformanceCounter(&startingTime);
            res=binarySearch(pinakas, megethos, value);
            QueryPerformanceCounter(&endingTime);

            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;

            if(printResult==1){
                if(res==-1)
                    printf("Value %d was not found.", value);
                else
                    printf("Value %d was found at location %d.", value, res);
            }
            break;

        case 3:
            heapSort(pinakas, megethos);

            QueryPerformanceCounter(&startingTime);
            res=interpolationSearch(pinakas, megethos, value);
            QueryPerformanceCounter(&endingTime);

            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;

            if(printResult==1){
                if(res==-1)
                    printf("Value %d was not found.", value);
                else
                    printf("Value %d was found at location %d.", value, res);
            }
            break;

        case 4:
            heapSort(pinakas, megethos);

            QueryPerformanceCounter(&startingTime);
            res=binaryInterpolationSearch(pinakas, megethos, value);
            QueryPerformanceCounter(&endingTime);

            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;

            if(printResult==1){
                if(res==-1)
                    printf("Value %d was not found.", value);
                else
                    printf("Value %d was found at location %d.", value, res);
            }
            break;

        case 5:
            heapSort(pinakas, megethos);

            QueryPerformanceCounter(&startingTime);
            res=improvedBinaryInterpolationSearch(pinakas, megethos, value);
            QueryPerformanceCounter(&endingTime);

            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;

            if(printResult==1){
                if(res==-1)
                    printf("Value %d was not found.", value);
                else
                    printf("Value %d was found at location %d.", value, res);
            }
            break;

        default:
            printf("Default case of timeCounter2 function.\n");
            break;
    }

    return (double)timeSpent.QuadPart/1000000000;
}


/* ��������� ��������� ��� ����� swap ������ 2 �������� �������. �� ��������
������ �� ��� ������� ����������� �� �������(�������� ����� �������) ��� ��
�������� �� ����� ����. */

void swapNumbers(int *number1, int *number2){
    int temp;
    temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}


/* �������� ��� ��������� Bubble Sort. ��������������� � ������� ���������
didSwap ��� boolean(�� true=1 ��� false=0) ���� ���� �� ��� ����� ������� swap
�� ������ loop �� ������� ��� � ������� ����� sorted. */

void bubbleSort(int *pinakas, int megethos){

    /* � ��������� toDo ������� ��� ������ ��� ���������� ��� ������ �� ������. */
    int toDo, index, didSwap=1;

    for(toDo=megethos-1; toDo>0; toDo--){
        didSwap=0;
        for(index=0; index<toDo; index++){
            if(pinakas[index]>pinakas[index+1]){
                swapNumbers(&pinakas[index], &pinakas[index+1]);
                didSwap=1;
            }
        }
        /* �� ��� ����� swapping(������ �� ������ ��� didSwap=0), ������� �
        ���������� �� ��������� ����� � ������� ��� ����� sorted. */
        if(didSwap==0){
            break;
        }
    }
}


/* �������� ��� ��������� Insertion Sort. */

void insertionSort(int *pinakas, int megethos){

    /* �� temp ��������������� ��� ��� ��������� ���������� ��� i-����� ���������. */
    int i, j, temp;

    for(i=1; i<megethos; i++){
        /* ���������� �� �������� ��� ������ ���� temp. */
        temp=pinakas[i];

        for(j=i-1; j>=0 && temp<pinakas[j]; j--){
            pinakas[j+1]=pinakas[j]; //Shift
        }

        pinakas[j+1]=temp;
    }
}


/* �������� ��� ��������� Selection Sort. */

void selectionSort(int *pinakas, int megethos){

    int i, j, min;
    for(i=0; i<megethos-1; i++){
        min=i;

        for(j=i+1; j<megethos; j++){
            if(pinakas[j]<pinakas[min]){
                min=j;
            }
        }

        if(min!=i){
            swapNumbers(&pinakas[min], &pinakas[i]);
        }
    }
}


/* �������� ��� ��������� merge ��� ����� ���������� ���
��� ��������� Merge Sort. */

void mergeFunction(int *pinakas, int min, int mid, int max){

    /* � ��������� i ����� counter ��� ��� ������ (���������) ������,
    � ��������� j ����� counter ��� ��� �������� ������ ��� � ��������� k
    ����� counter ��� ��� ����� ������. � ��������� ��� � ������ �������
    ��� ����� ����������� ���� ������. */
    int i, j, k;
    int size=max+1;
    int tempArray[size];

    j=min;
    k=mid+1;


    /* ������� �������� ��������� ������ ��������� ��� ������ ������.
    ��������� ���������� �� counters ��������. */
    for(i=min; j<=mid && k<=max; i++){
        if(pinakas[j]<=pinakas[k]){
            tempArray[i]=pinakas[j];
            j++;
        }
        else{
            tempArray[i]=pinakas[k];
            k++;
        }
    }

    /* ��� ��� �������� �������� ���������� �������� ���� ��� ���������
    ���� ��� ������ ������ ��� ��� ����� �����������. ���� ������������� ����
    ������ ��� �� �����. */
    if(j>mid){ /* �������� ������ ������ ��� ��� �������������. */
        while(k<=max){
            tempArray[i]=pinakas[k];
            k++;
            i++;
        }
    }
    else{ /* �������� ��������� ������ ��� ��� �������������. */
        while(j<=mid){
            tempArray[i]=pinakas[j];
            j++;
            i++;
        }
    }

    for(i=min; i<size; i++){
        pinakas[i]=tempArray[i];
    }
}


/* �������� ��� ��������� Merge Sort. */

void mergeSort(int *pinakas, int min, int max){

    int mid;

    /* � ��������� mergeSort �� �������� ���������� ����� ��
    ������� ��� ������ �� ����� ��� �� ������ ������ ����� ��
    ������ min=max. */

    if(min<max){
        mid=(min+max)/2;

        mergeSort(pinakas, min, mid);

        mergeSort(pinakas, mid+1, max);

        mergeFunction(pinakas, min, mid, max);
    }
}


/* �������� ��� ��������� Quick Sort. */

void quickSort(int *pinakas, int min, int max){

    int pivot, leftArrow, rightArrow;

    leftArrow=min;
    rightArrow=max;
    pivot=pinakas[(min+max)/2];

    /* �������� �� ������ ������ ��������� � ��� ��� pivot ���������� ��� �����
    ��� ������ ���������� � ��� ��� pivot ���������� ��� ��������. ������� swap
    ���� ��� �������� ��� ����������� ��� ���� ���������� ����� �� rightArrow
    �� ����� ��������� ��� leftArrow. */
    do{
        while(pinakas[rightArrow]>pivot){
            rightArrow--;
        }
        while(pinakas[leftArrow]<pivot){
            leftArrow++;
        }
        if(leftArrow<=rightArrow){
            swapNumbers(&pinakas[leftArrow], &pinakas[rightArrow]);
            leftArrow++;
            rightArrow--;
        }
    }
    while(rightArrow>=leftArrow);

    if(min<rightArrow){
        quickSort(pinakas, min, rightArrow);
    }

    if(leftArrow<max){
        quickSort(pinakas, leftArrow, max);
    }
}


/* �������� ��� ��������� Heap Sort. */

void heapSort(int *pinakas, int megethos){

    int i;
    /* �������������� ��� Max-Heap �������� ��� heapify ��� ���
    �� �������� ��� ������ ����� ��� �� ����� ��� �������. */
    for(i=megethos/2-1; i>=0; i--){
        heapify(pinakas, megethos, i);
    }

    /* ������� swap ��� ���� �� �� ��������� �������� ���������� ����
    ��� ���������� ������ ��� ������ ��� ������� ��� ����������� �������
    �������� ��� heapify. */
    for(i=megethos-1; i>=0; i--){
        swapNumbers(&pinakas[0], &pinakas[i]);
        heapify(pinakas, i, 0);
    }
}


/* �������� ��� ��������� heapify ��� ����� ���������� ��� ���
��������� HeapSort. */

void heapify(int *pinakas, int megethos, int i){

    int max=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<megethos && pinakas[left]>pinakas[max]){
        max=left;
    }

    if(right<megethos && pinakas[right]>pinakas[max]){
        max=right;
    }

    if(max!=i){
        swapNumbers(&pinakas[i], &pinakas[max]);

        /* ������ �� ������� heapify ��� ���� ����� ��� �����������. */
        heapify(pinakas, megethos, max);
    }
}


/* �������� ��� ��������� Linear Search. �� ������ �� �������� ������������
� ���� ��� ���� ������ ������ ������������ � ���� -1. */

int linearSearch(int *pinakas, int megethos, int z){

    int i;
    for(i=0; i<megethos; i++){
        if(pinakas[i]==z){
            return i;
        }
    }

    return -1;
}


/* �������� ��� ��������� Binary Search. �� ������ �� �������� ������������
� ���� ��� ���� ������ ������ ������������ � ���� -1. �� mid ������� ��� ����
��� ����� ��� ��������� ��� ���� ��� ������. */

int binarySearch(int *pinakas, int megethos, int z){

    int start, mid, end;

    start=0;
    end=megethos-1;
    mid=(start+end)/2;

    while(start<=end && z>=pinakas[start] && z<=pinakas[end]){

        if(z==pinakas[mid]){
            return mid;
        }
        else if(z<pinakas[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }

        mid=(start+end)/2;
    }

    return -1;
}


/* �������� ��� ��������� Interpolation Search. �� ������ �� �������� ������������
� ���� ��� ���� ������ ������ ������������ � ���� -1. �� next ������� ��� ���� ���
��������� ��� ��� ���� ��� ����������. */

int interpolationSearch(int *pinakas, int megethos, int z){
    int start = 0;
    int end = (megethos - 1);

    while (start <= end && z >= pinakas[start] && z <= pinakas[end]){
        if (start == end){
            if (pinakas[start] == z)
                return start;
            return -1;
        }

        int next = start + (((double)(end-start) / (pinakas[end]-pinakas[start]))*(z - pinakas[start]));

        if (pinakas[next] == z)
            return next;

        if (pinakas[next] < z)
            start = next + 1;

        else
            end = next - 1;
    }
    return -1;
}


/* �������� ��� ��������� Binary Interpolation Search. �� ������ �� �������� ������������
� ���� ��� ���� ������ ������ ������������ � ���� -1. */

int binaryInterpolationSearch(int *pinakas, int megethos, int z){

    int start, end, next, biggerTemp, smallerTemp;
    int size = megethos;

    start = 0;
    end = size-1;
    size = end-start+1;

    /* ��������� ��������� ��� ��������� ��� ���������� �� 0. */
    if (z == 0){
        next = 0;
    }
    else{
        next = (int)(size*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start])) + 1);
    }

    /* ������� �� �� next ����� ���� ��� ���� ��� ������. */
    if(next > end ){
        next = end;
    }
    if(next < start ){
        next = start;
    }

    /* ������� �� �� ��������� �������� ����� ����� ��� ����� ��� ������. */
    if(z<pinakas[start] || z>pinakas[end]){
        return -1;
    }

    while(z!=pinakas[next]){

        int i=0;
        size=end-start;

        if(size<=3){
            /* ������� �������� ��������� ���� ������ ��� ������ ������ start ��� end. */
            int j;
            for(j=start; j<=end; j++){
                if(z==pinakas[j]){
                    return j;
                }
            }
            return -1;
        }

        if(z>=pinakas[next]){
            while(z>pinakas[(int)((next+(i*(sqrt(size))))-1)]){
                i++;

                /* �� �� ������ �������� i-����� ����� ��� next ��������� ��� ���� ���
                end ������� �� ������� �� i ���� 1. */
                biggerTemp = (int)((next+(i*(sqrt(size))))-1);
                if(biggerTemp > end ){
                        i--;
                        break;
                }
            }

            /* ����������� ��� ������� ���� � ���� ��� ����������� �� ����� �����
            ��� start ��� end. */
            if ((int)(next+(i*(sqrt(size)))) <= end)
                end=(int)(next+(i*(sqrt(size))));

            if ( (int)(next+((i-1)*(sqrt(size)))) >= start)
                start=(int)(next+((i-1)*(sqrt(size))));

            if(biggerTemp>end)
                end = megethos-1;

            if(biggerTemp<0)
                start = 0;

        }
        else if(z<pinakas[next]){
            while(z<pinakas[(int)(next-(i*(sqrt(size)))+1)]){
                i++;

                /* �� �� ������ �������� i-����� ����� ��� next ��������� ��� ���� ���
                end ������� �� ������� �� i ���� 1. */
                smallerTemp = (int)(next-(i*(sqrt(size)))+1);
                if(smallerTemp > end ){
                        i--;
                        break;
                }
            }

            /* ����������� ��� ������� ���� � ���� ��� ����������� �� ����� �����
            ��� start ��� end. */
            if( (int)(next-((i-1)*(sqrt(size)))) <= end)
                end=(int)(next-((i-1)*(sqrt(size))));

            if ( (int)(next-(i*(sqrt(size)))) >= start )
                start=(int)(next-(i*(sqrt(size))));

            if(smallerTemp>end)
                end = megethos-1;

            if(smallerTemp<0)
                start = 0;

        }


        if(pinakas[end]-pinakas[start] == 0)
            next = (int)(start + ((end-start+1)*(double)(z-pinakas[start])) - 1);
        else{

        next = (int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1);

        /* ������� �� �� next ����� ����� ��� start ��� end. */
        if ((int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1) > end)
            next = end;
        if ((int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1) < start )
            next = start;
        }
    }


    if(z==pinakas[next]){
        return next;
    }
    else{
        return -1;
    }
}


/* �������� ��� ��������� Improved Binary Interpolation Search. �� ������ �� �������� ������������
� ���� ��� ���� ������ ������ ������������ � ���� -1. */

int improvedBinaryInterpolationSearch(int *pinakas, int megethos, int z){
    int start, end, next;
    int biggerTemp;
    int smallerTemp;
    int size = megethos;
    int i=1;
    start = 0;
    end = size-1;
    size = end-start+1;


    if (z == 0){ //��� �� ���������� �� �������� �� �� undefined behavior
        next = 0;
    }
    else{
        next = (int)(size*(double)((z-pinakas[start]) / (pinakas[end]-pinakas[start])) + 1);
    }
    if( (int)(size*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start])) + 1) > end ){
        next = end;
    }
    if( (int)(size*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start])) + 1) < start ){
        next = start;
    }
    /* ������� �� �� ��������� �������� ����� ����� ��� ����� ��� ������. */
    if(z<pinakas[start] || z>pinakas[end]){
        return -1;
    }

    int sizeAfter = -1;

    while(z!=pinakas[next]){
        i=1;
        size=end-start-1;


        if(size<=3 || (size >= sizeAfter && size>=0)){
            // Linear Searching
            for(int j=start; j<=end; j++){
                if(z==pinakas[j]){
                    return j;
                }
            }
            return -1;
        }

        sizeAfter = size;

        if(z>=pinakas[next]){
            while(z>pinakas[(int)((next+(i*(sqrt(size))))-1)]){
                i=i*2;
                biggerTemp = (int)((next+(i*(sqrt(size))))-1);
                if(biggerTemp > end ){
                        i=i/2;
                        break;
                }
            }


            if ((int)(next+(i*(sqrt(size)))) <= end)
                end=(int)(next+(i*(sqrt(size))));

            if ( (int)(next+((i-1)*(sqrt(size)))) >= start)
                start=(int)(next+((i-1)*(sqrt(size))));


            if(biggerTemp>end)
                end = megethos-1;

            if(biggerTemp<0)
                start = 0;


        }
        else if(z<pinakas[next]){
            while(z<pinakas[(int)(next-(i*(sqrt(size)))+1)]){
                i=i*2;
                smallerTemp = (int)(next-(i*(sqrt(size)))+1);
                if(smallerTemp > end ){
                        i=i/2;
                        break;
                }
            }


            if( (int)(next-((i-1)*(sqrt(size)))) <= end)
                end=(int)(next-((i-1)*(sqrt(size))));

            if ( (int)(next-(i*(sqrt(size)))) >= start )
                start=(int)(next-(i*(sqrt(size))));

            if(smallerTemp>end)
                end = megethos-1;

            if(smallerTemp<0)
                start = 0;


        }


        if(pinakas[end]-pinakas[start] == 0){
            next = (int)(start + ((end-start+1)*(double)(z-pinakas[start])) - 1);
        }
        else{

            next = (int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1);

            if ((int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1) > end){
                next = end;

            }
            if ((int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1) < start ){
                next = start;
            }
        }

    }
    if(z==pinakas[next]){
        return next;
    }
    else{
        return -1;
    }
}
