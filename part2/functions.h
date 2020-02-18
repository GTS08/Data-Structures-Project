#define B 11

typedef struct person {
    char am[20];
    char name[20];
    char lastname[20];
    float grade;
}person;

typedef struct node
{
    person data; // Η καταχώρηση, τύπου person
    struct node *rightChild; // Δεξί παιδί
    struct node *leftChild; // Αριστερό παιδί
}node;


typedef struct hashNode
{
    person data; // Η καταχώρηση, τύπου person
    struct hashNode *next; // Το επόμενο hasNode
}hashNode;


int arraySize; //Μέγεθος πίνακα καταχωρήσεων

struct person *readFile();

//Κοινές συναρτήσεις για το μέρος Α και Β
node* bstInit(person x);
node* bstMin(node *root);
node* bstMax(node *root);


//Συναρτήσεις για το μέρος Α
node* bstInsert(node *root, person x);
node* bstSearch(node *root, char *s);
node* bstDelete(node *root, char s[]);
void bstInorder(node *root);


//Συναρτήσεις για το μέρος Β
node* bstInsertByGrade(node *root, person x);
void bstPrint(node *root, float fNum);


//Συναρτήσεις για το μέρος Γ
int hashFunction(char s[]);
hashNode* hashInsert(hashNode *hashTable[], person x);
hashNode* hashSearch(hashNode *hashTable[], char s[]);
hashNode* hashDelete(hashNode *hashTable[], char s[]);
void hashPrint(hashNode *hashTable[]);











