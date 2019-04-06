//
// Created by rudri on 3/29/2019.
//

#include <iostream>

#include "Vector.h"

// Vector Methods

// Adding

void Vector::push_first(int newFirst) {

    Item* temp = new Item(newFirst);

    if (empty()) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void Vector::push_back(int newLast) {

    Item* temp = new Item(newLast);

    if (empty()) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void Vector::insert(int pos, const int &value) {
    if (size() == 0) {
        this->push_back(value);
        return;
    } else if (size() == 1) {
        if (pos == 0) {
            this->push_first(value);
            return;
        } else if (pos == 1) {
            this->push_back(value);
            return;
        }
    } else {
        if (pos == 0) {
            Item* newItem = nullptr;
            newItem = head;
            head = head->next;
            newItem->next = head;
            newItem->value = value;
            return;
        }
    }

    Item* temp = head;
    Item* newItem = new Item(value);
    Item* aux = head;

    for (int i = 0; i < pos; i++) {
        aux = aux->next;
    }

    for (int i = 0; i < pos-1; i++) {
        temp = temp->next;
    }

    temp->next = newItem;
    newItem->next = aux;

}

// Removing

void Vector::pop_first() {
    if (empty()) {
        std::cout << "Cannot remove elements of empty vector." << std::endl;
    } else {
        Item* temp = head;
        head = head->next;
        delete temp;
    }
}

void Vector::pop_back() {
    if (empty()) {
        std::cout << "Cannot remove elements of empty vector." << std::endl;
    } else {
        delete tail; // deletes content of tail, not the pointer tail
        Item* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        tail = temp;
        tail->next = nullptr;
    }
}

// Accessing

int Vector::get_item(unsigned int i) {
    Item* temp = head;
    if (temp == nullptr) {
        return 0;
    } else if (temp->next == nullptr) {
        return temp->value;
    }

    for (int j = 0; j < i; j++) {
        temp = temp->next;
    }

    return temp->value;
}

// Empty

bool Vector::empty() {
    return (head == nullptr && tail == nullptr);
}

// Getters

int Vector::get_first() {
    return head->value;
}

int Vector::get_last() {
    return tail->value;
}

// Print

void Vector::print() {

    unsigned int posicion = 0;

    if (head == nullptr) {
        std::cout << "Empty vector." << std::endl;
        return;
    } else if (head->next == nullptr) {
        std::cout << posicion << ". " << head->value << std::endl;
        return;
    }

    Item* temp = head;

    for (int i = 0; i < size(); i++) {
        std::cout << "At index " << posicion << ": " << temp->value << std::endl;
        temp = temp->next;
        ++posicion;
    }
}

// Size

unsigned int Vector::size() {
    unsigned int size = 0;

    if (head == nullptr) {
        return 0;
    } else if (head->next == nullptr) {
        return 1;
    }

    Item* temp = head;

    while (temp->next != nullptr) {
        size++;
        temp = temp->next;
    }
    size++;

    return size;
}

// Destructor

Vector::~Vector() {
    if (!empty()) {
        for (int i = 0; i < size(); i++) {
            pop_back();
        }
    }
}