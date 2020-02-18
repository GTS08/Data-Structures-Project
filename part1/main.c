/* Το συγκεκριμένο αρχείο περιέχει την συνάρτηση main του προγράμματος μας. */

#include <stdio.h>
#include "algorithmFunctions.h"

/* Κάνουμε define τα μεγέθη του πίνακα και τα βάζουμε ίσα με τον αριθμό
των ακεραίων αριθμών των αρχειών dataSet. */
#define size1 5000
#define size2 100000

int main(){

    int array1[size1], array2[size2];

    printf("Random Numbers: 5000 at [1, 10000]\n\nRunning all sorting algorithms: \n\n");

    initArray(array1, size1, 1);
    printf("Time taken for bubble sort: %.9f seconds\n", timeCounter1(1, array1, size1));

    initArray(array1, size1, 1);
    printf("Time taken for insertion sort: %.9f seconds\n", timeCounter1(2, array1, size1));

    initArray(array1, size1, 1);
    printf("Time taken for selection sort: %.9f seconds\n", timeCounter1(3, array1, size1));

    initArray(array1, size1, 1);
    printf("Time taken for merge sort: %.9f seconds\n", timeCounter1(4, array1, size1));

    initArray(array1, size1, 1);
    printf("Time taken for quick sort: %.9f seconds\n", timeCounter1(5, array1, size1));

    initArray(array1, size1, 1);
    printf("Time taken for heap sort: %.9f seconds\n", timeCounter1(6, array1, size1));

    char printIt;

    printf("\nDo you want to print the sorted array? (y/n)\n");
    scanf("%c", &printIt);

    if(printIt == 'y'){
        printArray(array1, size1);
    }

    printf("\n<----------------------------------------------------------------------------------------------------->\n\n");
    printf("Normal Distributed Numbers: 100000 - Mean: 50000 - Sigma: 10000\n\nRunning all searching algorithms: \n\n");

    int value1;
    printf("Search for: ");
    scanf("%d", &value1);

    initArray(array2, size2, 2);
    printf(" Time taken for linear search: %.9f seconds\n", timeCounter2(1, array2, size2, value1, 1));

    initArray(array2, size2, 2);
    printf(" Time taken for binary search: %.9f seconds\n", timeCounter2(2, array2, size2, value1, 1));

    initArray(array2, size2, 2);
    printf(" Time taken for interpolation search: %.9f seconds\n", timeCounter2(3, array2, size2, value1, 1));

    initArray(array2, size2, 2);
    printf(" Time taken for binary interpolation search(BIS): %.9f seconds\n", timeCounter2(4, array2, size2, value1, 1));

    initArray(array2, size2, 2);
    printf(" Time taken for improved binary interpolation search(improved BIS): %.9f seconds\n", timeCounter2(5, array2, size2, value1, 1));

    printf("\n<----------------------------------------------------------------------------------------------------->\n\n");
    printf("Uniformly Distributed Numbers: 100000 at [1, 100000]\n\nRunning all searching algorithms: \n\n");

    int value2;
    printf("Search for: ");
    scanf("%d", &value2);

    initArray(array2, size2, 3);
    printf(" Time taken for linear search: %.9f seconds\n", timeCounter2(1, array2, size2, value2, 1));

    initArray(array2, size2, 3);
    printf(" Time taken for binary search: %.9f seconds\n", timeCounter2(2, array2, size2, value2, 1));

    initArray(array2, size2, 3);
    printf(" Time taken for interpolation search: %.9f seconds\n", timeCounter2(3, array2, size2, value2, 1));

    initArray(array2, size2, 3);
    printf(" Time taken for binary interpolation search(BIS): %.9f seconds\n", timeCounter2(4, array2, size2, value2, 1));

    initArray(array2, size2, 3);
    printf(" Time taken for improved binary interpolation search(improved BIS): %.9f seconds\n", timeCounter2(5, array2, size2, value2, 1));

    return 0;
}
