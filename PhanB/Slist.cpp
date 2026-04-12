#ifndef SINGLELIST_CPP
#define SINGLELIST_CPP
#include "Node.cpp"
#include <iostream>
using namespace std;

template <class Keys, class T>
class SingleList {
private:
    Node<Keys, T> *header;
    long sz;
public:
    SingleList() { header = NULL; sz = 0; }
    long size() { return sz; }
    Node<Keys, T>* pushback(Keys k, T e) {
        Node<Keys, T> *q = new Node<Keys, T>;
        q->setKey(k); q->setElem(e);
        q->setNext(header); 
        header = q;
        sz++;
        return q;
    }
    Node<Keys, T>* getNode(Keys k) {
        Node<Keys, T> *p = header;
        while (p != NULL && p->getKey() != k) p = p->getNext();
        return p;
    }
};
#endif