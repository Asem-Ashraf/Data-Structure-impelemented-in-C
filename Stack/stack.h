// file gaurd
#ifndef THIS_FILE_STACK
#define THIS_FILE_STACK
#define StackEntry int /* PUT STACK DATA TYPE HERE */
#define MAXSTACK 1000 /* PUT MAX STACK SIZE HERE*/
#define LIMITED_MEMORY


typedef struct stack *Pstack;


/* Precondition: The stack is intialized and not full
 * Postcondition: The element has been stored at the top of the stack;
                  and e does not change
 */
void push(StackEntry,Pstack);


/* Precondition: The stack is intialized and not empty
 * Postcondition: The last element in the stack is returned.
 */
void pop(StackEntry*,Pstack);


/* Precondition: The stack is intialized.
 * Postcondition: none
 */
int  StackEmpty(Pstack);


/* Precondition: The stack is intialized.
 * Postcondition: none
 */
int  StackFull(Pstack);


/* Precondition: none
 * Postcondition: The stack is empty
 */
void ClearStack(Pstack);


/* Precondition: The stack is intialized and not empty
 * Postcondition: The element stored at the top of the stack is
                  returned without being removed.
 */
void StackTop(StackEntry*,Pstack);


/* Precondition: The stack is intialized.
 * Postcondition: none
 */
int  StackSize(Pstack);


/* Precondition: none
 * Postcondition: The stack is intialized.
 */
void CreateStack(Pstack);


/* Precondition: The stack is intialized and not empty.
 * Postcondition: none
 */
void TraverseStack(Pstack,void (*pf)(StackEntry));


#endif