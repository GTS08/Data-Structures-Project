#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"


struct person *readFile(){

    FILE *fp = fopen("foititesVathmologio.txt", "r"); // Άνοιγμα αρχείου

    // Περίπτωση αποτυχείας ανοίγματος αρχείου
    if(fp == NULL){
        printf("Error: File foititesVathmologio.txt wasn't opened. Exiting...\n");
        exit(0);
    }

    static person arr[30]; // Πίνακας τύπου person

    char c;
    int i=0;

    // Διάβασμα και καταχώρηση των στοιχείων στον πίνακα
    while(c != EOF){

        fscanf(fp, "%s", &arr[i].am);
        fscanf(fp, "%s", &arr[i].name);
        fscanf(fp, "%s", &arr[i].lastname);
        fscanf(fp, "%f", &arr[i].grade);

        c = fgetc(fp);

        if (c == '\n')
            i++;
    }

    arraySize = i; // Μέγετηος των καταχωρήσεων

    fclose(fp);

    return arr;
}


// Συνάρτηση για τη δημιουργία μιάς καταχώρησης στο δέντρο
node* bstInit(person x){
    node *p;
    p = malloc(sizeof(node));
    p->data = x;
    p->leftChild = NULL;
    p->rightChild = NULL;

    return p;
}


// Συνάρτηση για την εύρεση της μικρότερης τιμής στο δέντρο
node* bstMin(node *root){
    if(root == NULL)
        return NULL;
    else if(root->leftChild != NULL) // Όσο το αριστερό παιδί δεν είναι κενό, θα συνεχίσει να ψάχνει
        return bstMin(root->leftChild);
    return root;
}


// Συνάρτηση για την εύρεση της μεγαλύτερης τιμής στο δέντρο
node* bstMax(node *root){
    if(root == NULL)
        return NULL;
    else if(root->rightChild != NULL) // Όσο το δεξί παιδί δεν είναι κενό, θα συνεχίσει να ψάχνει
        return bstMax(root->rightChild);
    return root;
}


// Συνάρτηση για την εισαγωγή καταχωρήσεων στο δέντρο
node* bstInsert(node *root, person x){
    //Αναζήτηση για τη σωστή καταχώρηση
    if(root==NULL)
        return bstInit(x);
    else if(strcmp(x.am, root->data.am) > 0) //Αν το x.am είναι μεγαλύτερο, θα πάει στο δεξί παιδί
        root->rightChild = bstInsert(root->rightChild, x);
    else // Αν είναι μικρότερο το x.am θα πάει στο αριστερό παιδί
        root->leftChild = bstInsert(root->leftChild, x);

    return root;
}


// Συνάρτηση για την ανάζητηση ενός στοιχείου
node* bstSearch(node *root, char s[]){
    if(root==NULL || strcmp(root->data.am, s)==0) // Αν το root->data.am είναι ίσο με s τότε το στοιχείο βρέθηκε
        return root;
    else if(strcmp(s, root->data.am) > 0) // Αν το s είναι μεγαλύτερο θα ψάξει το δεξί υποδέντρο
        return bstSearch(root->rightChild, s);
    else // Αν το s είναι μικρότερο θα ψάξει το αριστερό υποδέντρο
        return bstSearch(root->leftChild, s);
}


// Συνάρτηση για διαγραφή κατα
node* bstDelete(node *root, char s[]){
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (strcmp(s, root->data.am) > 0)
        root->rightChild = bstDelete(root->rightChild, s);
    else if(strcmp(s, root->data.am) < 0)
        root->leftChild = bstDelete(root->leftChild, s);
    else{
        // Αν δεν έχει παιδιά
        if(root->leftChild==NULL && root->rightChild==NULL){
            free(root);
            return NULL;
        }

        // Αν έχει ένα παιδί
        else if(root->leftChild==NULL || root->rightChild==NULL){
            node *temp;
            if(root->leftChild==NULL)
                temp = root->rightChild;
            else
                temp = root->leftChild;
            free(root);
            return temp;
        }

        // Αν έχει δύο παιδιά
        else{
            node *temp = bstMin(root->rightChild);
            root->data = temp->data;
            root->rightChild = bstDelete(root->rightChild, temp->data.am);
        }
    }

    return root;
}


// Εκτύπωση των καταχωρήσεων σε ενδοδιατεταγμένη σειρά
void bstInorder(node *root){
    if(root!=NULL){ // Ελέγχει αν η ρίζα είναι κενή
        bstInorder(root->leftChild); // Θα κοιτάξει το αριστερό παιδί
        // Θα εκτυπώσει τη τρεχούμενη ρίζα του δέντρου
        printf("\nID: %s\n", root->data.am);
        printf("Name: %s\n", root->data.name);
        printf("LastName: %s\n", root->data.lastname);
        printf("Grade: %.2f\n", root->data.grade);
        bstInorder(root->rightChild); // Θα κοιτάξει το δεξί παιδί
    }
}


// Συνάρτηση για την εισαγωγή καταχωρήσεων στο δέντρο με βάση το βαθμό
node* bstInsertByGrade(node *root, person x){
    if(root==NULL)
        return bstInit(x);
    else if(x.grade >= root->data.grade) // Αν το x.grade είναι μεγαλύτερο ή ισο, θα πάει στο δεξί παιδί
        root->rightChild = bstInsert(root->rightChild, x);
    else // Αν το x.grade είναι μικρότερο, θα πάει στο δεξί παιδί
        root->leftChild = bstInsert(root->leftChild, x);
    return root;
}


//Συνάρτηση για την εκτύπωση των αποτελεσμάτων για το μερος Β
void bstPrint(node *root, float fNum){
    if(root!=NULL){
        bstPrint(root->leftChild, fNum); // Θα κοιτάξει το αριστερό παιδί
        // Αν ο βαθμός είναι ίδιος με αυτόν που βρέθηκε ως μικρότερος ή μεγαλύτερις τότε τον εκτυπώνει
        if (root->data.grade == fNum){
            printf("\nID: %s\n", root->data.am);
            printf("Name: %s\n", root->data.name);
            printf("LastName: %s\n", root->data.lastname);
            printf("Grade: %.2f\n", root->data.grade);

        }
        bstPrint(root->rightChild, fNum); // Θα κοιτάξει το δεξί παιδί
    }
}


//Συνάρτηση για την εφαρμογή του hashing
int hashFunction(char s[]){
    char id[20];

    strcpy(id, s);

    int i = 0;
    int hashID = 0;

    //Ο κάθε χαρακτήρας θα μετατρέπεται σε int και γίνεται πρόσθεση με το προηγόυμενο άθροισμα
    while(id[i] != '\0'){
        hashID = hashID + (int)id[i];
        i++;
    }

    //Εκτελούμε το modulo με βάση τα buckets
    hashID = hashID % B;

    return hashID;
}


//Συνάρτηση για την εισαγωγή καταχωρήσεων στο hash table
hashNode* hashInsert(hashNode *hashTable[], person x){
    int hashedID;
    hashNode *entry;

    hashedID = hashFunction(x.am); //Μετατροπή του am σε hash value

    //Δέσμευση μνήμης και καταχώρση των δεδομένων sto entry
    entry = malloc(sizeof(hashNode));
    entry->data = x;
    entry->next = hashTable[hashedID];

    //Εισαγωγή του entry στο hashTable
    hashTable[hashedID] = entry;

    return hashTable;
}


//Συνάρτηση για την αναζήτηση στοιχείων στο hash table
hashNode* hashSearch(hashNode *hashTable[], char s[]){
    int hashedID;
    hashNode *entry;

    hashedID = hashFunction(s); //Μετατροπή του am σε hash value

    entry = hashTable[hashedID]; //Αναθέτηση του στοιχείου μέσα στο πίνακα

    //Σύγκριση του am του στοιχείου με αυτό που δόθηκε από τον χρήστη
    while(entry != NULL){
        if(strcmp(entry->data.am, s) == 0){
            return entry;
        }
        entry = entry->next;
    }

    return NULL;

}


//Συνάρτηση για την διαγραφή στοιχείων στο hash table
hashNode* hashDelete(hashNode *hashTable[], char s[]){
    int hashedID;
    hashNode *entry;
    hashNode *temp = NULL;

    hashedID = hashFunction(s);
    entry = hashTable[hashedID];


    if(entry==NULL){
        return NULL;
    }

    //Αν το am από τον χρήστη είναι ίδιο τότε το διαγράφουμε
    if(strcmp(hashTable[hashedID]->data.am, s) == 0){
        temp = hashTable[hashedID];
        hashTable[hashedID] = hashTable[hashedID]->next;
        free(temp);
        return;
    }

    //Αν δεν είναι προχωράμε στην επόμενη καταχώρηση στη θέση του πίνακα
    while(entry->next != NULL){
        if(strcmp(entry->next->data.am, s) == 0){
              temp = entry->next;
              entry->next = temp->next;
              free(temp);
              return;
        }
        entry = entry->next;
    }

    return NULL;
}


//Συνάρτηση για την εκτύπωση του hash table
void hashPrint(hashNode *hashTable[]){
    int i;
    hashNode *entry;

    for(i=0; i<B; i++){
        printf("[%d]", i);

        if(hashTable[i] != NULL){
            entry = hashTable[i];

            while(entry != NULL){
                printf(" %s ", entry->data.am);
                entry = entry->next;
            }
        }
        printf("\n");
    }

}





















