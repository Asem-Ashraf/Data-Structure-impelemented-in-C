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


/* Precondition: None
 * Postcondition: None
 */
doublylinkedlist createDoublyLinkedList();


/* Precondition: None
 * Postcondition: None
 */
void intializeDoublyLinkedList(doublylinkedlist*);


/* Precondition: The list has been intialized.
 * Postcondition: None
 */
int   len(doublylinkedlist*);


/* Precondition: None
 * Postcondition: The element inserted at the end of the list.
 */
void  insertLast(doublylinkedlist*,node*);


/* Precondition: The list must not be empty.
 * Postcondition: The element inserted at the beginning of the list.   
 */
void  insertFirst(doublylinkedlist*,node*);


/* Precondition: The list must not be empty.
 * Postcondition: The first element is deleted.
 *                The size of the list is decremented.
 */
node* deleteFirst(doublylinkedlist*);


/* Precondition: The list must not be empty.
 * Postcondition: The last element is deleted.
 *                the size of the list is decremented.
 */
node* deleteLast(doublylinkedlist*);


/* Precondition: The input index is less than the size of the list.
 *               The list must not be empty.
 * Postcondition: The element is removed from the list and returned.
 *                The size of the list is decremented.
 */
node* deleteAt(doublylinkedlist*,int);


/* Precondition: The input index is less than the size of the list.
 * Postcondition: The node is inserted in the list at the input index.
 *                The size of the list is incremented.
 */
void  insertAt(doublylinkedlist*,node*,int);


/* Precondition: 
 * Postcondition: 
 */
void  iter_seq(doublylinkedlist*);


/* Precondition: The input index is less than the size of the list.
 * Postcondition: None
 */
node* getAt(doublylinkedlist*,int);


/* Precondition: None
 * Postcondition: None
 */
int listEmpty(doublylinkedlist*);
#endif