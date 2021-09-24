#ifndef LISTDLS_H
#define LISTDLS_H

#include <iostream>
#include "node_dl.h"

using namespace std;

template<class T> 
class ListDLS{
    NodeDL<T> *head, *tail, *nil;
    int length;
    bool ascend;

    public:
    ListDLS(bool ascend): head(NULL), tail(NULL), length(0),ascend(ascend){
        nil= new NodeDL<T>;
    }
    ListDLS():ListDLS(true){}

    //verifico se la lista è vuota 
    bool isEmpty(){
        return (head == NULL) && (tail==NULL);
    }
// non implementiamo i metodi setter per evitare di avere situazione di memoria non consistente ( Memory Break)
 
    NodeDL<T> * getHead() const {return head;}
    NodeDL<T> * getTail() const {return tail;}
    NodeDL<T> * getNil() const {return nil;}
    int getLength() const {return length;}
    bool isAscend() const { return ascend;}

    void insertHead(T value){
        NodeDL<T> * n = new NodeDL<T>(value);

        if(this->isEmpty()){
            n->setNext(nil); // se la lista è vuota vedi (n) che il tuo successore è nil
            n->setPrev(nil); // se la lista è vuota vedi (n) che il tuo successore è nil
            head = n;
            tail = n;
            nil->setNext(head);
            nil->setPrev(tail);
        }

        else {
            n->setNext(head);
            head->setPrev(n);
            n->setPrev(nil);
            nil->setNext(n);
            head=n;
            
        }
        length++;
    }

    void insertTail(T value){
        if (this->isEmpty()){
            this->insertHead(value);
            return;
        }
        NodeDL<T> *n= new NodeDL<T>(value);
        n->setPrev(tail);
        tail->setNext(n);
        n->setNext(nil);
        nil-> setPrev(n);
        tail=n;
       
        length++;
    }

    void insert(T value){
        if ( ascend && (value<head->getValue())||(!ascend && ( value>= head->getValue()))){
            this-> insertHead(value);
            return;
        }
        if ( ascend && (value>= tail->getValue()) || (!ascend && (value<tail->getValue()))){
            this-> insertTail(value);
            return; 
        }

        NodeDL<T> * cur = head;
        NodeDL<T> * n = new NodeDL<T> ( value);
        if (ascend){
            while ((*cur < *n )&& cur->getNext() != nil){
                cur = cur-> getNext();
            }
            n->setPrev(cur->getPrev());
            n->setNext(cur);
            cur->getPrev()->setNext(n);
            cur->setPrev(n);
            length++;
        }
        else {
            while (( *cur  >= *n ) && cur != nil){
                cur = cur-> getNext();
            }
            n->setPrev(cur->getPrev());
            n->setNext(cur);
            cur->getPrev()->setNext(n);
            cur->setPrev(n);
            length++;

        }
    }

    void deleteHead(){
        if (this-> isEmpty())
            return;
        
        head-> getNext()->setPrev(nil);
        nil-> setNext(head->getNext());
        Node<T> * tmp = head; // nodo temporaneo che poi andremo ad eliminare
        head= head -> getNext();

        length--;

        delete tmp; // non usiamo [] perchè non è un array 
        return;
    }

    void deleteTail(){
        if(this->isEmpty())
            return;
        
        tail-> getPrev()->setNext(nil);
        nil-> setPrev(tail->getPrev());
        Node<T> * tmp = tail;
        tail=tail->getPrev();

        length--;

        delete tmp;
        return; 
    }
    NodeDL<T> * search(T value){
        Node<T> * tmp = new NodeDL<T>(value);

        if((ascend&&(*tmp < *head)) || (!ascend && (*tmp < *tail)) || (ascend && ( *tmp>= *tail)) || (!ascend && (*tmp>= *head)))
            return NULL;
        
        Node <T> * cur = head;
        while ( *cur != *tmp && cur != nil)  
            cur= cur-> getNext();
        if ( cur == nil)
            return NULL;
        else 
            return cur; 
        
    }

    friend ostream& operator<<(ostream& out, ListDLS<T> l){
        out<< "Lista di lunghezza : "<<l.length <<" head "<< l.head << endl;
        NodeDL<T> * current = l.head;
        while(current != l.nil){
            out<<"\t"<< current->toString()<<endl;
            current = current-> getNext();
        }
        return out; 
    }


};
#endif