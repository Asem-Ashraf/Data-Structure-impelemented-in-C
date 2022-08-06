#ifndef THIS_FILE_DLL
#define THIS_FILE_DLL
#define datatype int
typedef struct node{
    datatype value;
    node* prev;
    node* next;
}node;


/* Precondition: None
 * Postcondition: None
 */
/* Description: Allocate a node space from memory,
                Given the node pointer.
*/
void allocNode(node*);


/* Precondition: None
 * Postcondition: None
 */
/* Description: Deallocate a node space from memory,
                completely deleteing it and its content.
                Given the node pointer.
*/
void freeNode(node*);



typedef struct DoublyLinkedList{
    int noElements;
    node* head;
    node* tail;
}doublylinkedlist;


/* Precondition: None
 * Postcondition: None
 */
/* Description: Intializes the head, tail and number of elements
                of the list to NULL, NULL and 0.
                Returns an intialized doubly linked list.
*/
doublylinkedlist createDoublyLinkedList();


/* Precondition: None
 * Postcondition: None
 */
/* Description: Given a doubly linked list datatype.
                Intializes the head, tail and number of elements
                of the list to NULL, NULL and 0.
*/
void intializeDoublyLinkedList(doublylinkedlist*);


/* Precondition: The list has been intialized.
 * Postcondition: None
 */
/* Description: Given a doubly linked list datatype.
                Return the number of elements in the list.
*/
int   len(const doublylinkedlist*);


/* Precondition: None
 * Postcondition: The element inserted at the end of the list.
 */
/* Description: Given a doubly linked list datatype
                and a doubly pointing node.
                Inserts the node at the end of the list.
*/
void  insertLast(doublylinkedlist*,node*);


/* Precondition: The list must not be empty.
 * Postcondition: The element inserted at the beginning of the list.   
 */
/* Description: Given a doubly linked list datatype
                and a doubly pointing node.
                Inserts the node at the beginning of the list.
*/
void  insertFirst(doublylinkedlist*,node*);


/* Precondition: The list must not be empty.
 * Postcondition: The first element is deleted.
                  The size of the list is decremented.
 */
/* Description: Given a doubly linked list datatype.
                Deletes the node at the beginning of the list.
                Returns the deleted node.
*/
node* deleteFirst(doublylinkedlist*);


/* Precondition: The list must not be empty.
 * Postcondition: The last element is deleted.
                  the size of the list is decremented.
 */
/* Description: Given a doubly linked list datatype.
                Deletes the node at the end of the list.
                Returns the deleted node.
*/
node* deleteLast(doublylinkedlist*);


/* Precondition: The input index is less than the size of the list.
                 The list must not be empty.
 * Postcondition: The element is removed from the list and returned.
                  The size of the list is decremented.
 */
/* Description: Given a doubly linked list datatype
                and a 0-based index in the list.
                Deletes the node at the index.
                Returns the deleted node.
*/
node* deleteAt(doublylinkedlist*,int);


/* Precondition: The input index is less than the size of the list.
 * Postcondition: The node is inserted in the list at the input index.
                  The size of the list is incremented.
 */
/* Description: Given a doubly linked list datatype
                , a doubly pointing node
                and a 0-based index in the list.
                Inserts the node at the index.
*/
void  insertAt(doublylinkedlist*,node*,int);


/* Precondition: Given a pointer to a doubly linked list and a function 
                 for the values of the doubly linked list.
                 The function is ran on each value in the list from the
                 head to tail in order.
 * Postcondition: 
 */
void  iterateElements(const doublylinkedlist*,void (*pfunc)(datatype));


/* Precondition: The input index is less than the size of the list.
 * Postcondition: None
 */
node* getAt(doublylinkedlist*,int);


/* Precondition: The input index is less than the size of the list.
 * Postcondition: The input replaces the value at the index.
 */
void  setAt(doublylinkedlist*,datatype,int);

/* Precondition: None
 * Postcondition: None
 */
/* Description: Given a doubly linked list datatype.
                Returns 1 if the list is empty
                        0 if the list is not empty.
*/
int listEmpty(doublylinkedlist*);
#endif