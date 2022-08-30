#include "Stack.h"

 struct stack{
    int top; // the index that an entry is going to be inserted at on pushing
    StackEntry entry[MAXSTACK];
};

void push(StackEntry e ,Pstack ps){
    ps->entry[ps->top]=e;
    ps->top++;
}
void pop(StackEntry* pe,Pstack ps){
    pe=ps->entry[--ps->top];
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

