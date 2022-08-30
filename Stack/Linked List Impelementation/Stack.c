#include "Stack.h"
#include "Doubly_Linked_List.h"

struct stack{
    node* top; // the index that an entry is going to be inserted at on pushing
    doublylinkedlist entrys;
};

void push(StackEntry e ,Pstack ps){
    node* pNode;
    allocNode(pNode);
    pNode->value=e;
    insertFirst(&(ps->entrys),pNode);
    ps->top=ps->entrys.head;
}
void pop(StackEntry* pe,Pstack ps){
    node* pNode = deleteFirst(&ps->entrys);
    *pe=&pNode->value;
    ps->top=ps->entrys.head;
    freeNode(pNode);
}

int  StackEmpty(Pstack ps){
    return !len(&ps->entrys);
}
// int  StackFull(Pstack ps){
//     return len(&ps->entrys)==MAXSTACK;
// }
void ClearStack(Pstack ps){
    intializeDoublyLinkedList(&ps->entrys);
    ps->top=ps->entrys.head;
}
void StackTop(StackEntry* pe,Pstack ps){
    *pe=ps->top->value;
}
int  StackSize(Pstack ps){
   return len(&ps->entrys); 
}
void CreateStack(Pstack ps){
   ps->top=ps->entrys.head; 
}
void TraverseStack(Pstack ps,void (*pf)(StackEntry)){
   iterateElements(&ps->entrys,pf);
}

