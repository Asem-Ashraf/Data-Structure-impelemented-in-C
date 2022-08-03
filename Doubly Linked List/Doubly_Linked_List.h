#ifndef THIS_FILE_DLL
#define THIS_FILE_DLL
#define datatype int
typedef struct node{
    datatype value;
    node* prev;
    node* next;
}node;

typedef struct DoublyLinkedList{
    int size;
    node* head;
    node* tail;
}doublylinkedlist;

doublylinkedlist createDoublyLinkedList();
int   len(doublylinkedlist*);
void  insertLast(doublylinkedlist*,node*);
void  insertFirst(doublylinkedlist*,node*);
node* deleteFirst(doublylinkedlist*);
node* deleteLast(doublylinkedlist*);
node* deleteAt(doublylinkedlist*,int);
void  insertAt(doublylinkedlist*,node*,int);
void  iter_seq(doublylinkedlist*);
node* getAt(doublylinkedlist*,int);
#endif