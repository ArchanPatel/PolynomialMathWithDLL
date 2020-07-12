#include "polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial(int A[], unsigned int size) {
    size_ = size; //
    if (size_ != 0) {
        for (int i = 0; i < size_; i++)
            list_.insert_back(A[i]);
    }
    else{ //in case size is 0
        list_.insert_front(0);
    }
}

Polynomial::~Polynomial() {
    for (int i=0; i < size_; i++)
        list_ . remove_back();
    size_ = 0;
}

Polynomial* Polynomial::add(Polynomial *rhs) const {
    int sum[size_+rhs->size_];
    int smaller; // the size integer of the smaller sized list
    int i; //index for for loop
    int j; //index for for loop
    if (size_ > rhs->size_)
        smaller = rhs->size_;
    else
        smaller = size_;
    for (i=0; i<smaller; i++)
        sum[i] = list_ .select(i) + rhs->list_.select(i);
    if (smaller == rhs->size_){ //Add the remaining elements of this* with 0
        for (j=i; j<size_; j++)
            sum[j] = list_.select(j);
    }
    else { //Add the remaining elements of rhs* with 0
        for (j=i; j<rhs->size_; j++)
            sum[j] = rhs->list_.select(j);
    }
        Polynomial* sumFinal = new Polynomial(sum, j); //the sum to be returned
    return sumFinal;
}

Polynomial* Polynomial::sub(Polynomial *rhs) const {
    for (int i=0; i<rhs->size_; i++)
        rhs->list_.replace(i, -1*rhs->list_.select(i)); //multiply rhs by -1
    return add(rhs); // perform addition with the modified rhs
}

Polynomial* Polynomial::mul(Polynomial *rhs) const {
    int product[size_+rhs->size_-1]; //the maximum possible size the product can be

    for (int i=0; i<size_+rhs->size_-1; i++) //initialize the product array
        product[i] = 0;
    for (int i=0; i< size_; i++){ //multiply the ith term of *this
        for (int j=0; j<rhs->size_; j++) //multiply the jth term of *rhs
            //store the product of each term by term multiplication in the index representing the degree
            product[i+j] += list_.select(i) * rhs->list_.select(j);
    }
        Polynomial* productFinal = new Polynomial(product, size_+rhs->size_-1);
    return productFinal;
}

void Polynomial::print() const {
    for (int i=size_-1; i>=0; i--){ //iterate through each term of the polynomial
        if (list_.select(i) < 0) { //if the term is negative
            if (i != size_-1) //only execute if not the first term
                cout<< " + ";
            cout << "(" << list_.select(i) << ")" << "x^" << i;
        }
        else if (list_.select(i) > 0) { //if the term is positive
            if (i != size_-1) //only execute if not the first term
                cout<< " + ";
            cout << list_.select(i) << "x^" << i;
        }
    }
    cout<<endl;
}

