#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP
#include "SList.cpp"
#include <string>

template<class Keys, class T>
class Hashtable {
private:
    int m;
    SingleList<Keys, T> *table;
public:
    Hashtable(int n) { m = n; table = new SingleList<Keys, T>[m]; }
    ~Hashtable() { delete[] table; }
    
    Node<Keys, T>* Add(Keys key, T e, int (*hash)(Keys, int)) {
        int h = hash(key, m);
        if (table[h].getNode(key) == NULL) return table[h].pushback(key, e);
        return NULL;
    }

    bool Contains(Keys key, int (*hash)(Keys, int)) {
        int h = hash(key, m);
        return table[h].getNode(key) != NULL;
    }
};
#endif