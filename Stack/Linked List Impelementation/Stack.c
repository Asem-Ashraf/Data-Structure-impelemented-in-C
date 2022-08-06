#include "Stack.h"

void push(StackEntry e ,stack* ps){
    node* pNode;
    allocNode(pNode);
    pNode->value=e;
    insertFirst(&(ps->entrys),pNode);
    ps->top=ps->entrys.head;
}
void pop(StackEntry* pe,stack* ps){
    node* pNode = deleteFirst(&ps->entrys);
    *pe=&pNode->value;
    ps->top=ps->entrys.head;
    freeNode(pNode);
}

int  StackEmpty(stack* ps){
    return !len(&ps->entrys);
}
int  StackFull(stack* ps){
    return len(&ps->entrys)==MAXSTACK;
}
void ClearStack(stack* ps){
    intializeDoublyLinkedList(&ps->entrys);
    ps->top=ps->entrys.head;
}
void StackTop(StackEntry* pe,stack* ps){
    *pe=ps->top->value;
}
int  StackSize(stack* ps){
   return len(&ps->entrys); 
}
void CreateStack(stack* ps){
   ps->top=ps->entrys.head; 
}
void TraverseStack(stack* ps,void (*pf)(StackEntry)){
   iterateElements(&ps->entrys,pf);
}

