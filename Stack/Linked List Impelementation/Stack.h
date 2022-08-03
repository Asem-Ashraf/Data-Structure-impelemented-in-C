
// file gaurd
#ifndef THIS_FILE_LLIMP
#define THIS_FILE_LLIMP
#define StackEntry int /* PUT STACK DATA TYPE HERE */
#define MAXSTACK 1000 /* PUT MAX STACK SIZE HERE*/

typedef struct stack{
    int top; // the index that an entry is going to be inserted at on pushing
    linkedlist entrys;
}stack;

typedef struct node{
    StackEntry value;
    node* prev;
    node* next;
}node;

typedef struct LinkedList{
    node head;
    node tail;
}linkedlist;


/* Precondition: The stack is intialized and not full
 * Postcondition: The element has been stored at the top of the stack;
 * and e does not change
 */
void push(StackEntry,stack*);


/* Precondition: The stack is intialized and not empty
 * Postcondition: The last element in the stack is returned.
 */
void pop(StackEntry*,stack*);


/* Precondition: The stack is intialized.
 * Postcondition: none
 */
int  StackEmpty(stack*);


/* Precondition: The stack is intialized.
 * Postcondition: none
 */
int  StackFull(stack*);


/* Precondition: none
 * Postcondition: The stack is empty
 */
void ClearStack(stack*);


/* Precondition: The stack is intialized and not empty
 * Postcondition: The element stored at the top of the stack is
 * returned without being removed.
 */
void StackTop(StackEntry*,stack*);


/* Precondition: The stack is intialized.
 * Postcondition: none
 */
int  StackSize(stack*);


/* Precondition: none
 * Postcondition: The stack is intialized.
 */
void CreateStack(stack*);


/* Precondition: The stack is intialized and not empty.
 * Postcondition: none
 */
void TraverseStack(stack*,void (*pf)(StackEntry));


#endif