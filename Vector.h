//
// Created by rudri on 3/29/2019.
//

#ifndef MYVECTOR_MYVECTOR_H
#define MYVECTOR_MYVECTOR_H

// Item

struct Item {
    int value;
    Item* next;

    Item(int value): value{value}, next{nullptr} {}
};

// Vector

class Vector {
    Item* head;
    Item* tail;

public:

    Vector(): head{nullptr}, tail{nullptr} {}
    ~Vector();

    void push_first(int newFirst);
    void push_back(int newLast);

    void pop_first();
    void pop_back();

    bool empty();

    int get_first();
    int get_last();
    int get_item(unsigned int i); // returns 0 of size is 0
    void insert(int pos, const int& value);

    void print();
    unsigned int size();
};


#endif //MYVECTOR_MYVECTOR_H
