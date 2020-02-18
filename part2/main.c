#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main()
{
    //File
    int arrSize;
    person *arr;
    arr = readFile();
    arrSize = arraySize;


    //Choices
    int mChoice;
    int m1Choice;
    int m11Choice;
    int m113Choice;
    int m12Choice;
    int m22Choice;
    int m2Choice;
    int exitChoice;

    char searchChoice[20];
    char deleteChoice[20];
    char editAttributeChar[20];
    float editAttributeFloat;

    //BST based on ID
    node *nSearch;
    node *rootA = NULL;

    for (int i=0; i<arrSize; i++)
        if (i==0)
            rootA = bstInit(arr[i]);
        else
            bstInsert(rootA,arr[i]);


    //BST based on grades
    float minGrade;
    float maxGrade;
    node *nFind;
    node *rootB = NULL;

    for (int i=0; i<arrSize; i++)
        if (i==0)
            rootB = bstInit(arr[i]);
        else
            bstInsertByGrade(rootB,arr[i]);


    //Hashing with chaining
    hashNode *hashTable[B];
    hashNode *hSearch;


    for(int i=0; i<B; i++){
        hashTable[i] = NULL;
    }

    for (int i=0; i<arrSize; i++){
        hashInsert(hashTable, arr[i]);
    }



    do{
        // Εκτύπωση menu
        printf("1.Load with Binary Search Tree\n");
        printf("2.Load with Hashing with Chaining\n");
        printf("3.Exit\n");

        printf("\nChoice: ");
        scanf("%d", &mChoice);

        system("cls");

        switch(mChoice){

            case 1:
                do{
                    printf("1.Load based on ID\n");
                    printf("2.Load based on grade\n");
                    printf("3.Back\n");
                    printf("4.Exit\n");

                    printf("\nChoice: ");
                    scanf("%d", &m1Choice);

                    system("cls");

                    switch(m1Choice){

                        case 1:
                            do{
                                printf("1.Print Inorder\n");
                                printf("2.Search Student\n");
                                printf("3.Edit Elements\n");
                                printf("4.Delete Entry\n");
                                printf("5.Back\n");
                                printf("6.Exit\n");

                                printf("\nChoice: ");
                                scanf("%d", &m11Choice);

                                system("cls");

                                switch(m11Choice){
                                    case 1:
                                        bstInorder(rootA);
                                        break;

                                    case 2:
                                        printf("Give Student ID.\n");
                                        scanf("%s", &searchChoice);

                                        nSearch = bstSearch(rootA, searchChoice);

                                        if(nSearch == NULL){
                                            printf("Person was not found.\n");
                                        }else{
                                            printf("\nID: %s\nName: %s\nLastname: %s\nGrade: %.2f\n", nSearch->data.am, nSearch->data.name, nSearch->data.lastname, nSearch->data.grade);
                                        }
                                        break;

                                    case 3:
                                        printf("Give Student ID.\n");
                                        scanf("%s", &searchChoice);

                                        nSearch = bstSearch(rootA, searchChoice);


                                        if(nSearch == NULL)
                                            printf("Person was not found.\n");
                                        else{
                                            printf("What attribute you want to edit?\n");

                                            printf("1. Name\n");
                                            printf("2. Lastname\n");
                                            printf("3. Grade\n");

                                            printf("\nChoice: ");
                                            scanf("%d", &m113Choice);

                                            system("cls");

                                            switch(m113Choice){
                                                case 1:
                                                    printf("Current Lastname: %s\n", nSearch->data.name);
                                                    printf("Enter new name.\n");
                                                    scanf("%s", &editAttributeChar);
                                                    strcpy(nSearch->data.name, editAttributeChar);
                                                    printf("New name registered: %s\n", nSearch->data.name);
                                                    break;

                                                case 2:
                                                    printf("Current Lastname: %s\n", nSearch->data.lastname);
                                                    printf("Enter new lastname.\n");
                                                    scanf("%s", &editAttributeChar);
                                                    strcpy(nSearch->data.lastname, editAttributeChar);
                                                    printf("New lastname registered: %s\n", nSearch->data.lastname);
                                                    break;

                                                case 3:
                                                    printf("Current Grade: %.2f\n", nSearch->data.grade);
                                                    printf("Enter new grade.\n");
                                                    scanf("%f", &editAttributeFloat);
                                                    nSearch->data.grade = editAttributeFloat;
                                                    printf("New grade registered: %.2f\n", nSearch->data.grade);
                                                    break;

                                                default:
                                                    printf("Something went wrong.\nYou have exited the program.\n");
                                                    exit(0);
                                                    break;
                                            }
                                        }
                                        break;

                                    case 4:
                                        printf("Give Student ID.\n");
                                        scanf("%s", &deleteChoice);

                                        nSearch = bstSearch(rootA, deleteChoice);

                                        if(nSearch == NULL){
                                            printf("Person was not found.\n");
                                        }else{
                                            bstDelete(rootA, deleteChoice);
                                            printf("Person was found and deleted with given ID: %s\n", deleteChoice);
                                        }
                                        break;

                                    case 5:
                                        break;

                                    case 6:
                                        printf("You have exited the program.\n");
                                        exit(0);
                                        break;

                                    default:
                                        printf("Something went wrong.\nYou have exited the program.\n");
                                        exit(0);
                                        break;
                                }

                                if (m11Choice!=5){

                                    printf("\n1. Go Back\n");
                                    printf("2. Exit\n");

                                    printf("\nChoice: ");
                                    scanf("%d", &exitChoice);

                                    switch(exitChoice){

                                    case 1:
                                        system("cls");
                                        break;

                                    case 2:
                                        printf("You have exited the program.\n");
                                        exit(0);
                                        break;

                                    default:
                                        printf("Something went wrong.\nYou have exited the program.\n");
                                        exit(0);
                                        break;
                                    }
                                }
                            }while(m11Choice != 5);

                            break;

                        case 2:
                            do{
                                printf("1.Find students with the minimum grade\n");
                                printf("2.Find students with the maximum grade\n");
                                printf("3.Back\n");
                                printf("4.Exit\n");

                                printf("\nChoice: ");
                                scanf("%d", &m12Choice);

                                system("cls");

                                switch(m12Choice){

                                    case 1:
                                        nFind = bstMin(rootB);
                                        minGrade = nFind->data.grade;
                                        bstPrint(rootB, minGrade);
                                        break;

                                    case 2:
                                        nFind = bstMax(rootB);
                                        maxGrade = nFind->data.grade;
                                        bstPrint(rootB, maxGrade);
                                        break;

                                    case 3:
                                        break;

                                    case 4:
                                        printf("You have exited the program.\n");
                                        exit(0);
                                        break;

                                    default:
                                        printf("Something went wrong.\nYou have exited the program.\n");
                                        exit(0);
                                        break;
                                }

                                if (m12Choice !=3){

                                    printf("\n1. Go Back\n");
                                    printf("2. Exit\n");

                                    printf("\nChoice: ");
                                    scanf("%d", &exitChoice);

                                    switch(exitChoice){

                                    case 1:
                                        system("cls");
                                        break;

                                    case 2:
                                        printf("You have exited the program.\n");
                                        exit(0);
                                        break;

                                    default:
                                        printf("Something went wrong.\nYou have exited the program.\n");
                                        exit(0);
                                        break;
                                    }
                                }

                            }while(m12Choice != 3);

                            break;

                        case 3:
                            break;

                        case 4:
                            printf("You have exited the program.\n");
                            exit(0);
                            break;

                        default:
                            printf("Something went wrong.\nYou have exited the program.\n");
                            exit(0);
                            break;
                    }

                }while(m1Choice != 3);


                break;

            case 2:
                do{
                    printf("1.Search Student\n");
                    printf("2.Edit Elements\n");
                    printf("3.Delete Entry\n");
                    printf("4.Print Hash Table\n");
                    printf("5.Back\n");
                    printf("6.Exit\n");

                    printf("\nChoice: ");
                    scanf("%d", &m2Choice);

                    system("cls");

                    switch(m2Choice){

                        case 1:
                            printf("Give Student ID.\n");
                            scanf("%s", &searchChoice);

                            hSearch = hashSearch(hashTable, searchChoice);

                            if(hSearch == NULL){
                                printf("\nPerson was not found.\n");
                            }else{
                                printf("\nID: %s\nName: %s\nLastname: %s\nGrade: %.2f\n", hSearch->data.am, hSearch->data.name, hSearch->data.lastname, hSearch->data.grade);
                            }
                            break;

                        case 2:
                            printf("Give Student ID.\n");
                            scanf("%s", &searchChoice);

                            hSearch = hashSearch(hashTable, searchChoice);


                            if(hSearch == NULL)
                                printf("Person was not found.\n");
                            else{
                                printf("What attribute you want to edit?\n");

                                printf("1. Name\n");
                                printf("2. Lastname\n");
                                printf("3. Grade\n");

                                printf("\nChoice: ");
                                scanf("%d", &m22Choice);

                                system("cls");

                                switch(m22Choice){
                                    case 1:
                                        printf("Current Lastname: %s\n", hSearch->data.name);
                                        printf("Enter new name.\n");
                                        scanf("%s", &editAttributeChar);
                                        strcpy(hSearch->data.name, editAttributeChar);
                                        printf("New name registered: %s\n", hSearch->data.name);
                                        break;

                                    case 2:
                                        printf("Current Lastname: %s\n", hSearch->data.lastname);
                                        printf("Enter new lastname.\n");
                                        scanf("%s", &editAttributeChar);
                                        strcpy(hSearch->data.lastname, editAttributeChar);
                                        printf("New lastname registered: %s\n", hSearch->data.lastname);
                                        break;

                                    case 3:
                                        printf("Current Grade: %.2f\n", hSearch->data.grade);
                                        printf("Enter new grade.\n");
                                        scanf("%f", &editAttributeFloat);
                                        hSearch->data.grade = editAttributeFloat;
                                        printf("New grade registered: %.2f\n", hSearch->data.grade);
                                        break;

                                    default:
                                        printf("Something went wrong.\nYou have exited the program.\n");
                                        exit(0);
                                        break;
                                }
                            }

                            break;

                        case 3:
                            printf("Give Student ID.\n");
                            scanf("%s", &deleteChoice);

                            hSearch = bstSearch(rootA, deleteChoice);

                            if(hSearch == NULL){
                                printf("\nPerson was not found.\n");
                            }else{
                                hashDelete(hashTable, deleteChoice);
                                printf("Person was found and deleted with given ID: %s\n", deleteChoice);
                            }
                            break;

                        case 4:
                            hashPrint(hashTable);
                            break;

                        case 5:
                            break;

                        case 6:
                            printf("You have exited the program.\n");
                            exit(0);
                            break;
                        default:
                            printf("Something went wrong.\nYou have exited the program.\n");
                            exit(0);
                            break;
                    }

                    if (m2Choice != 5){

                        printf("\n1. Go Back\n");
                        printf("2. Exit\n");

                        printf("\nChoice: ");
                        scanf("%d", &exitChoice);

                        switch(exitChoice){

                        case 1:
                            system("cls");
                            break;

                        case 2:
                            printf("You have exited the program.\n");
                            exit(0);
                            break;

                        default:
                            printf("Something went wrong.\nYou have exited the program.\n");
                            exit(0);
                            break;
                        }
                    }

                }while(m2Choice != 5);

                break;

            case 3:
                printf("You have exited the program.\n");
                exit(0);
                break;

            default:
                printf("Something went wrong.\nYou have exited the program.\n");
                exit(0);
                break;

        }

    }while(mChoice != 3);



    return 0;
}



















