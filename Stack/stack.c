#include "Stack.h"
#ifdef LIMITED_MEMORY

 struct stack{
    int top; // the index that an entry is going to be inserted at on pushing
    StackEntry entry[MAXSTACK];
};

void push(StackEntry e ,Pstack ps){
    ps->entry[ps->top]=e;
    ps->top++;
}
void pop(StackEntry* pe,Pstack ps){
    *pe=ps->entry[--ps->top];
}

int  StackEmpty(Pstack ps){
    if(ps->top==0) return 1;
    else return 0;
}
int  StackFull(Pstack ps){
    if(ps->top==MAXSTACK) return 1;
    else return 0;
}
void ClearStack(Pstack ps){
    ps->top = 0;
}
void StackTop(StackEntry* pe,Pstack ps){
    *pe = ps->entry[ps->top-1];
}
int  StackSize(Pstack ps){
    return ps->top;
}
void CreateStack(Pstack ps){
    ps->top=0;
}
void TraverseStack(Pstack ps,void (*pf)(StackEntry)){
    for (int i = ps->top-1; i >=0; i--)
    {
        (*pf)(ps->entry[i]);
    }
    
}



#else

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


#endif