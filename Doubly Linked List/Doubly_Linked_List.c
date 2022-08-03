#include "Doubly_Linked_List.h"
#define NULL ((void*)0)
doublylinkedlist createDoublyLinkedList(){
    doublylinkedlist dll;
    dll.head = NULL;
    dll.tail = NULL;
    dll.size = 0;

}
int  len(doublylinkedlist* pl){
    return pl->size;
}
void insertLast(doublylinkedlist* pl,node* pn){
    pl->tail->next=pn;
    pn->prev=pl->tail;
    pl->tail=pn;
}
void insertFirst(doublylinkedlist* pl,node* pn){
    pl->head->prev=pn;
    pn->next=pl->head;
    pl->head=pn;
}
node* deleteFirst(doublylinkedlist* pl){
    pl->head->next->prev=NULL;
    node* pOldHeadNode=pl->head;
    pl->head=pl->head->next;
    pl->head->next=NULL;
    return pOldHeadNode;
}
node* deleteLast(doublylinkedlist* pl){
    pl->tail->prev->next=NULL;
    node* pOldtailNode=pl->tail;
    pl->tail=pl->tail->prev;
    pl->tail->prev=NULL;
    return pOldtailNode;
}
node* deleteNodeAt(doublylinkedlist* pl,int index){
    node* pNode=getAt(pl,index); 
    pNode->prev->next=pNode->next;
    pNode->next->prev=pNode->prev;
    pNode->next=NULL;
    pNode->prev=NULL;
    return pNode;
}
void insertAt(doublylinkedlist* pl,node* pn,int index){
    node* pNode = getAt(pl,index);
    pn->prev=pNode->prev;
    pn->next=pNode;
    pNode->prev->next=pn;
    pNode->prev=pn;
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
