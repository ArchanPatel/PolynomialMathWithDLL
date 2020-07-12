#include <climits>

#ifndef SYDE223_A1_POLYNOMIAL_H
#define SYDE223_A1_POLYNOMIAL_H
#include "doubly-linked-list.h"


class Polynomial {
private:
    // The number of used elements in data_.
    unsigned int size_;
    // The list storing the co-efficients
    DoublyLinkedList list_;
public:
    //Constructor
    Polynomial(int A[], unsigned int size);
    //Destructor
    ~Polynomial();
    //Adds the two polynomials
    Polynomial* add (Polynomial* rhs) const;
    //Subtract the two polynomials
    Polynomial* sub (Polynomial* rhs) const;
    //Multiply the two polynomials
    Polynomial* mul (Polynomial* rhs) const;
    //Prints the polynomial
    void print() const;
};


#endif

