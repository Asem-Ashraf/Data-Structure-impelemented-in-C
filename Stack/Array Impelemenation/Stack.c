#include "Stack.h"

void push(StackEntry e ,stack* ps){
    ps->entry[ps->top]=e;
    ps->top++;
}
void pop(StackEntry* pe,stack* ps){
    pe=ps->entry[--ps->top];
}

int  StackEmpty(stack* ps){
    if(ps->top==0) return 1;
    else return 0;
}
int  StackFull(stack* ps){
    if(ps->top==MAXSTACK) return 1;
    else return 0;
}
void ClearStack(stack* ps){
    ps->top = 0;
}
void StackTop(StackEntry* pe,stack* ps){
    *pe = ps->entry[ps->top-1];
}
int  StackSize(stack* ps){
    return ps->top;
}
void CreateStack(stack* ps){
    ps->top=0;
}
void TraverseStack(stack* ps,void (*pf)(StackEntry)){
    for (int i = ps->top-1; i >=0; i--)
    {
        (*pf)(ps->entry[i]);
    }
    
}

