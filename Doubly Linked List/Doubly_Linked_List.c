#include "Doubly_Linked_List.h"
#include <stdlib.h>

void allocNode(node* pn){
    pn = (node*)malloc(sizeof(node));
    pn->next=pn->prev=pn->value=NULL;
}
void freeNode(node* pn){
    free(pn);
}

doublylinkedlist createDoublyLinkedList(){
    doublylinkedlist dll;
    dll.head = NULL;
    dll.tail = NULL;
    dll.noElements = 0;

}
void intializeDoublyLinkedList(doublylinkedlist* pl){
    if (!listEmpty(pl))
    {
        node* pNode = pl->head;
        for (int i = 0; i < len(pl)-1; i++)
        {
            pNode = pNode->next;
            freeNode(pNode->prev);
        }
        freeNode(pNode);
    }
    pl->head=pl->tail=NULL;
    pl->noElements=0;
}


int  len(const doublylinkedlist* pl){
    return pl->noElements;
}


void insertLast(doublylinkedlist* pl,node* pn){
    if (listEmpty(pl))
    {
        pn->prev=pn->next=NULL;
        pl->head=pl->tail=pn;
    }
    else{
        pl->tail->next=pn;
        pn->prev=pl->tail;
        pl->tail=pn;
    }
    pl->noElements++;
}


void insertFirst(doublylinkedlist* pl,node* pn){
    if (listEmpty(pl))
    {
        pn->prev=pn->next=NULL;
        pl->head=pl->tail=pn;
    }
    else{
        pn->prev=NULL;
        pl->head->prev=pn;
        pn->next=pl->head;
        pl->head=pn;
    }
    pl->noElements++;
}


node* deleteFirst(doublylinkedlist* pl){
    if(pl->head->next==NULL){
        node* pOldHeadNode=pl->head;
        pl->head=pl->tail=NULL;
        pl->noElements=0;
        pOldHeadNode->prev=pOldHeadNode->next=NULL;
        return pOldHeadNode;
    }
    else{
    pl->head->next->prev=NULL;
    node* pOldHeadNode=pl->head;
    pl->head=pl->head->next;
    pl->noElements--;
    pOldHeadNode->next=NULL;
    return pOldHeadNode;
    }
}


node* deleteLast(doublylinkedlist* pl){
    if(pl->tail->prev==NULL){
        node* pOldTailNode=pl->tail;
        pl->head=pl->tail=NULL;
        pl->noElements=0;
        pOldTailNode->prev=pOldTailNode->next=NULL;
        return pOldTailNode;
    }
    else{
    pl->tail->prev->next=NULL;
    node* pOldtailNode=pl->tail;
    pl->tail=pl->tail->prev;
    pl->noElements--;
    pOldtailNode->prev=NULL;
    return pOldtailNode;
    }
}


node* deleteNodeAt(doublylinkedlist* pl,int index){
    if(index==len(pl)-1) deleteLast(pl);
    if(index==0) deleteFirst(pl);

    node* pNode=getAt(pl,index); 
    pNode->prev->next=pNode->next;
    pNode->next->prev=pNode->prev;
    pNode->next=NULL;
    pNode->prev=NULL;
    pl->noElements--;
    return pNode;
}


void insertAt(doublylinkedlist* pl,node* pn,int index){
    if (index==0) insertFirst(pl,pn);
    if (index==len(pl)-1) insertLast(pl,pn);
    
    node* pNode = getAt(pl,index);
    pn->prev=pNode->prev;
    pn->next=pNode;
    pNode->prev->next=pn;
    pNode->prev=pn;
    pl->noElements++;
}


void iterateElements(const doublylinkedlist* pl,void (*pfunc)(datatype)){
    node* pNode = pl->head;
        while (pNode!=NULL){
            (*pfunc)(pNode->value);
            pNode = pNode->next;
        }
}


node* getAt(doublylinkedlist* pl, int index){
    node* pNode=pl->head;
    for (int i = 0; i < index; i++)
    {
        pNode=pNode->next;
    }
    return pNode;
}

void setAt(doublylinkedlist* pl,datatype inputValue, int index){
    getAt(pl,index)->value=inputValue;
}


int listEmpty(doublylinkedlist* pl){
    return !(pl->noElements);
}
