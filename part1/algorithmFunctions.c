/* Το αρχείο αυτό περιέχει τις συναρτήσεις με τις οποίες υλοποιούνται
οι αλγόριθμοι μας καθώς και επιπλέον βοηθητικές συναρτήσεις. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <windows.h>
#include "algorithmFunctions.h"


/* Αρχικοποιεί τον μονοδιάστατο πίνακα με τυχαίους ακέραιους αριθμούς
που είναι αποθηκευμένοι στα dataSet αρχεία. */

void initArray(int *pinakas, int megethos, int dataSet){

    FILE *fp = NULL;

    switch(dataSet){
        case 1:
            /* Ανοίγουμε το αρχείο dataSet.txt με όρισμα "r" για να το διαβάσουμε */
            fp = fopen("dataSetRandom.txt", "r");
            break;

        case 2:
            /* Ανοίγουμε το αρχείο dataSet.txt με όρισμα "r" για να το διαβάσουμε */
            fp = fopen("dataSetNormal.txt", "r");
            break;

        case 3:
            /* Ανοίγουμε το αρχείο dataSet.txt με όρισμα "r" για να το διαβάσουμε */
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

    /* Γεμίζουμε τον πίνακα με τους τυχαίους ακέραιους */
    int i;
    for(i=0; i<megethos; i++){
        fscanf(fp, "%d", &pinakas[i]);
    }

    if(fp != NULL){
        fclose(fp);
    }

}


/* Εκτυπώνει τα στοιχεία του πίνακα χωρισμένα με κόμματα. */

void printArray(int *pinakas, int megethos){

    int i;
    printf("Elements of array: \n[");
    for(i=0; i<megethos-1; i++){
        printf("%d, ", pinakas[i]);
    }
    printf("%d]\n\n", pinakas[megethos-1]);
}


/* Συνάρτηση που εκτελεί τον αλγόριθμο ταξινόμησης ανάλογα με το όρισμα algorithmSelection και
μετράει τον χρόνο που χρειάζεται για να εκτελεστεί σε δευτερόλεπτα. */

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


/* Συνάρτηση που εκτελεί τον αλγόριθμο αναζήτησης ανάλογα με το όρισμα algorithmSelection και
μετράει τον χρόνο που χρειάζεται για να εκτελεστεί σε δευτερόλεπτα. */

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


/* Βοηθητική συνάρτηση που κάνει swap μεταξύ 2 ακέραιων αριθμών. Τα ορίσματα
δηλαδή οι δύο αριθμοί περνιούνται με αναφορά(κάνοντας χρήση δεικτών) για να
αλλάξουν οι τιμές τους. */

void swapNumbers(int *number1, int *number2){
    int temp;
    temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}


/* Υλοποιεί τον αλγόριθμο Bubble Sort. Χρησιμοποιείται η ακέραια μεταβλητή
didSwap σαν boolean(με true=1 και false=0) έτσι ώστε αν δεν γίνει καθόλου swap
σε κάποιο loop να ξέρουμε ότι ο πίνακας είναι sorted. */

void bubbleSort(int *pinakas, int megethos){

    /* Η μεταβλητή toDo δηλώνει τον αριθμό των συγκρίσεων που πρέπει να γίνουν. */
    int toDo, index, didSwap=1;

    for(toDo=megethos-1; toDo>0; toDo--){
        didSwap=0;
        for(index=0; index<toDo; index++){
            if(pinakas[index]>pinakas[index+1]){
                swapNumbers(&pinakas[index], &pinakas[index+1]);
                didSwap=1;
            }
        }
        /* Αν δεν έγινε swapping(δηλαδή αν ισχύει ότι didSwap=0), θέλουμε ο
        αλγόριθμος να τελείωσει γιατί ο πίνακας μας είναι sorted. */
        if(didSwap==0){
            break;
        }
    }
}


/* Υλοποιεί τον αλγόριθμο Insertion Sort. */

void insertionSort(int *pinakas, int megethos){

    /* Το temp χρησιμοποιείται για την προσωρινή αποθήκευση του i-οστού στοιχείου. */
    int i, j, temp;

    for(i=1; i<megethos; i++){
        /* Αποθηκεύει το στοιχείο του πίνακα στην temp. */
        temp=pinakas[i];

        for(j=i-1; j>=0 && temp<pinakas[j]; j--){
            pinakas[j+1]=pinakas[j]; //Shift
        }

        pinakas[j+1]=temp;
    }
}


/* Υλοποιεί τον αλγόριθμο Selection Sort. */

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


/* Υλοποιεί την συνάρτηση merge που είναι απαραίτητη για
τον αλγόριθμο Merge Sort. */

void mergeFunction(int *pinakas, int min, int mid, int max){

    /* Η μεταβλητή i είναι counter για τον μεγάλο (αδιαίρετο) πίνακα,
    η μεταβλητή j είναι counter για τον αριστερό πίνακα ενώ η μεταβλητή k
    είναι counter για τον δεξιό πίνακα. Ο αριστερός και ο δεξιός πίνακας
    δεν είναι πραγματικοί αλλά νοητοί. */
    int i, j, k;
    int size=max+1;
    int tempArray[size];

    j=min;
    k=mid+1;


    /* Γίνεται σύγκριση στοιχείων μεταξύ αριστερού και δεξιού πίνακα.
    Παράλληλα αυξάνονται οι counters αναλόγως. */
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

    /* Από την παραπάνω σύγκριση προκύπτουν στοιχεία είτε του αριστερού
    είτε του δεξιού πίνακα που δεν έχουν ταξινομηθεί. Αυτά αντιγράφονται στον
    πίνακα μας ως έχουν. */
    if(j>mid){ /* Στοιχεία δεξιού πίνακα που δεν ταξινομήθηκαν. */
        while(k<=max){
            tempArray[i]=pinakas[k];
            k++;
            i++;
        }
    }
    else{ /* Στοιχεία αριστερού πίνακα που δεν ταξινομήθηκαν. */
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


/* Υλοποιεί τον αλγόριθμο Merge Sort. */

void mergeSort(int *pinakas, int min, int max){

    int mid;

    /* Η συνάρτηση mergeSort θα καλείται αναδρομικά μέχρι το
    μέγεθος του πίνακα να γίνει ίσο με μονάδα δηλαδή μέχρι να
    ισχύει min=max. */

    if(min<max){
        mid=(min+max)/2;

        mergeSort(pinakas, min, mid);

        mergeSort(pinakas, mid+1, max);

        mergeFunction(pinakas, min, mid, max);
    }
}


/* Υλοποιεί τον αλγόριθμο Quick Sort. */

void quickSort(int *pinakas, int min, int max){

    int pivot, leftArrow, rightArrow;

    leftArrow=min;
    rightArrow=max;
    pivot=pinakas[(min+max)/2];

    /* Ψάχνουμε να βρούμε αριθμό μικρότερο ή ίσο του pivot ξεκινώντας από δεξιά
    και αριθμό μεγαλύτερο ή ίσο του pivot ξεκινώντας από αριστερά. Κάνουμε swap
    τους δύο αριθμούς και συνεχίζουμε την ίδια διαδικασία μέχρι το rightArrow
    να γίνει μικρότερο του leftArrow. */
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


/* Υλοποιεί τον αλγόριθμο Heap Sort. */

void heapSort(int *pinakas, int megethos){

    int i;
    /* Κατασκευάζουμε τον Max-Heap καλώντας την heapify για όλα
    τα στοιχεία του πίνακα εκτός από τα φύλλα του δέντρου. */
    for(i=megethos/2-1; i>=0; i--){
        heapify(pinakas, megethos, i);
    }

    /* Κάνουμε swap την ρίζα με το τελευταίο στοιχείο παίρνοντας έτσι
    τον μεγαλύτερο αριθμό του πίνακα και κάνουμε τις απαραίτητες αλλαγές
    καλώντας την heapify. */
    for(i=megethos-1; i>=0; i--){
        swapNumbers(&pinakas[0], &pinakas[i]);
        heapify(pinakas, i, 0);
    }
}


/* Υλοποιεί την συνάρτηση heapify που είναι απαραίτητη για τον
αλγόριθμο HeapSort. */

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

        /* Πρέπει να κάνουμε heapify και στον κόμβο που επηρεάστηκε. */
        heapify(pinakas, megethos, max);
    }
}


/* Υλοποιεί τον αλγόριθμο Linear Search. Αν βρεθεί το στοιχείο επιστρέφεται
η θέση του στον πίνακα αλλιώς επιστρέφεται η τιμή -1. */

int linearSearch(int *pinakas, int megethos, int z){

    int i;
    for(i=0; i<megethos; i++){
        if(pinakas[i]==z){
            return i;
        }
    }

    return -1;
}


/* Υλοποιεί τον αλγόριθμο Binary Search. Αν βρεθεί το στοιχείο επιστρέφεται
η θέση του στον πίνακα αλλιώς επιστρέφεται η τιμή -1. Το mid παίρνει την τιμή
της θέσης που βρίσκεται στη μέση του πίνακα. */

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


/* Υλοποιεί τον αλγόριθμο Interpolation Search. Αν βρεθεί το στοιχείο επιστρέφεται
η θέση του στον πίνακα αλλιώς επιστρέφεται η τιμή -1. Το next παίρνει την τιμή που
προκύπτει από τον τύπο της παρεμβολής. */

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


/* Υλοποιεί τον αλγόριθμο Binary Interpolation Search. Αν βρεθεί το στοιχείο επιστρέφεται
η θέση του στον πίνακα αλλιώς επιστρέφεται η τιμή -1. */

int binaryInterpolationSearch(int *pinakas, int megethos, int z){

    int start, end, next, biggerTemp, smallerTemp;
    int size = megethos;

    start = 0;
    end = size-1;
    size = end-start+1;

    /* Παίρνουμε ξεχωριστά την περίπτωση που αναζητούμε το 0. */
    if (z == 0){
        next = 0;
    }
    else{
        next = (int)(size*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start])) + 1);
    }

    /* Έλεγχος αν το next είναι μέσα στα όρια του πίνακα. */
    if(next > end ){
        next = end;
    }
    if(next < start ){
        next = start;
    }

    /* Έλεγχος αν το ζητούμενο στοιχείο είναι εντός των ορίων του πίνακα. */
    if(z<pinakas[start] || z>pinakas[end]){
        return -1;
    }

    while(z!=pinakas[next]){

        int i=0;
        size=end-start;

        if(size<=3){
            /* Κάνουμε γραμμική αναζήτηση στις θέσεις του πίνακα μεταξύ start και end. */
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

                /* Αν σε κάποια πρόσθεση i-οστής ρίζας στο next περάσουμε την τιμή του
                end θέλουμε να μειωθεί το i κατά 1. */
                biggerTemp = (int)((next+(i*(sqrt(size))))-1);
                if(biggerTemp > end ){
                        i--;
                        break;
                }
            }

            /* Περιορισμοί και έλεγχοι ώστε η τιμή που υπολογίσαμε να είναι εντός
            των start και end. */
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

                /* Αν σε κάποια αφαίρεση i-οστής ρίζας στο next περάσουμε την τιμή του
                end θέλουμε να μειωθεί το i κατά 1. */
                smallerTemp = (int)(next-(i*(sqrt(size)))+1);
                if(smallerTemp > end ){
                        i--;
                        break;
                }
            }

            /* Περιορισμοί και έλεγχοι ώστε η τιμή που υπολογίσαμε να είναι εντός
            των start και end. */
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

        /* Έλεγχος αν το next είναι εντός των start και end. */
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


/* Υλοποιεί τον αλγόριθμο Improved Binary Interpolation Search. Αν βρεθεί το στοιχείο επιστρέφεται
η θέση του στον πίνακα αλλιώς επιστρέφεται η τιμή -1. */

int improvedBinaryInterpolationSearch(int *pinakas, int megethos, int z){
    int start, end, next;
    int biggerTemp;
    int smallerTemp;
    int size = megethos;
    int i=1;
    start = 0;
    end = size-1;
    size = end-start+1;


    if (z == 0){ //Για να επιλύσουμε το πρόβλημα με το undefined behavior
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
    /* Έλεγχος αν το ζητούμενο στοιχείο είναι εντός των ορίων του πίνακα. */
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
