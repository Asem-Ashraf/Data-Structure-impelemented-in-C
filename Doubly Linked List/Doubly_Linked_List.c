#include "Doubly_Linked_List.h"
#define NULL ((void*)0)


doublylinkedlist createDoublyLinkedList(){
    doublylinkedlist dll;
    dll.head = NULL;
    dll.tail = NULL;
    dll.size = 0;

}

void intializeDoublyLinkedList(doublylinkedlist* pl){
    pl->head=pl->tail=NULL;
    pl->size=0;
}


int  len(doublylinkedlist* pl){
    return pl->size;
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
    pl->size++;
}


void insertFirst(doublylinkedlist* pl,node* pn){
    if (listEmpty(pl))
    {
        pn->prev=pn->next=NULL;
        pl->head=pl->tail=pn;
    }
    else{
        pl->head->prev=pn;
        pn->next=pl->head;
        pl->head=pn;
    }
    pl->size++;
}


node* deleteFirst(doublylinkedlist* pl){
    pl->head->next->prev=NULL;
    node* pOldHeadNode=pl->head;
    pl->head=pl->head->next;
    pl->head->next=NULL;
    pl->size--;
    return pOldHeadNode;
}


node* deleteLast(doublylinkedlist* pl){
    pl->tail->prev->next=NULL;
    node* pOldtailNode=pl->tail;
    pl->tail=pl->tail->prev;
    pl->tail->prev=NULL;
    pl->size--;
    return pOldtailNode;
}


node* deleteNodeAt(doublylinkedlist* pl,int index){
    node* pNode=getAt(pl,index); 
    pNode->prev->next=pNode->next;
    pNode->next->prev=pNode->prev;
    pNode->next=NULL;
    pNode->prev=NULL;
    pl->size--;
    return pNode;
}


void insertAt(doublylinkedlist* pl,node* pn,int index){
    node* pNode = getAt(pl,index);
    pn->prev=pNode->prev;
    pn->next=pNode;
    pNode->prev->next=pn;
    pNode->prev=pn;
    pl->size++;
}


void iter_seq(doublylinkedlist* pl){

}


node* getAt(doublylinkedlist* pl, int index){
    node* pNode=pl->head;
    for (int i = 0; i < index; i++)
    {
        pNode=pNode->next;
    }
    return pNode;
}


int listEmpty(doublylinkedlist* pl){
    return !pl->size;
}
