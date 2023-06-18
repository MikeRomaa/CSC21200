//FILE: bag1.h
// From Chapter 3 of Data Structures and Other Objects (Second Edition)
// ________________________________________________________________________
//
// This file has been modified to work with Microsoft Visual C++ 6.0,
// as described in www.cs.colorado.edu/~main/vc6.html
// ________________________________________________________________________
//
// CLASS PROVIDED: bag (part of the namespace main_savitch_3)
//
// TYPEDEF and MEMBER CONSTANTS for the bag class:
//   typedef ____ value_type
//     bag::value_type is the data type of the items in the bag. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   typedef ____ size_type
//     bag::size_type is the data type of any variable that keeps track of how many items
//     are in a bag.
//
//   static const size_type CAPACITY = _____
//     bag::CAPACITY is the maximum number of items that a bag can hold.
//
// CONSTRUCTOR for the bag class:
//   Bag( )
//     Postcondition: The bag has been initialized as an empty bag.
//
// MODIFICATION MEMBER FUNCTIONS for the bag class:
//   size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the bag.
//     The return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const value_type& target)
//     Postcondition: If target was in the bag, then one copy has been removed;
//     otherwise the bag is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry)
//     Precondition:  size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been added to the bag.
//
//   void operator +=(const bag& addend)
//     Precondition:  size( ) + addend.size( ) <= CAPACITY.
//     Postcondition: Each item in addend has been added to this bag.
//
//   friend operator-(const Bag &lhs, const Bag &rhs)
//     Postcondition: For two bags b1 and b2, the bag x - y contains all the
//     items of x, with any items from y removed.
//
// CONSTANT MEMBER FUNCTIONS for the bag class:
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the bag.
//
//   size_type count(const value_type& target) const
//     Postcondition: The return value is number of times target is in the bag.
//
// NONMEMBER FUNCTIONS for the bag class:
//   bag operator +(const bag& b1, const bag& b2)
//     Precondition:  b1.size( ) + b2.size( ) <= bag::CAPACITY.
//     Postcondition: The bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bag class:
//    Assignments and the copy constructor may be used with bag objects.

#ifndef MAIN_SAVITCH_BAG1_H
#define MAIN_SAVITCH_BAG1_H

#include <cstdlib>  // Provides size_t

class Bag {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        // * For VC++ 6.0 we are using size_t instead of std::size_t. And we
        // * have defined CAPACITY using an enum instead of a static member
        // * constant. See www.cs.colorado.edu/~main/vc6.html for details.
        typedef int value_type;
        typedef size_t size_type;
        static const size_type CAPACITY = 30;

        // CONSTRUCTOR
        Bag() { used = 0; }

        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type &target);

        bool erase_one(const value_type &target);

        void insert(const value_type &entry);

        void operator+=(const Bag &addend);

        // CONSTANT MEMBER FUNCTIONS
        size_type size() const { return used; }

        size_type count(const value_type &target) const;

        friend Bag operator-(const Bag &lhs, const Bag &rhs);

    private:
        value_type data[CAPACITY];  // The array to store items
        size_type used;             // How much of array is used
};

// NONMEMBER FUNCTIONS for the bag class
Bag operator+(const Bag &b1, const Bag &b2);

#endif
