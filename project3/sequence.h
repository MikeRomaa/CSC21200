// FILE: Sequence2.h
// CLASS PROVIDED: Sequence (part of the namespace com267_Sequence2)
//
// TYPEDEFS and MEMBER CONSTANTS for the Sequence class:
//   typedef ____ value_type
//     Sequence::value_type is the data type of the items in the Sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   typedef ____ size_type
//     Sequence::size_type is the data type of any variable that keeps track of
//     how many items are in a Sequence.
//
//   static const size_type DEFAULT_CAPACITY = _____
//     Sequence::DEFAULT_CAPACITY is the initial capacity of a Sequence that is
//     created by the default constructor.
//
// CONSTRUCTOR for the Sequence class:
//   Sequence(size_t initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The Sequence has been initialized as an empty Sequence.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.
//
// MODIFICATION MEMBER FUNCTIONS for the Sequence class:
//   void resize(size_type new_capacity)
//     Postcondition: The Sequence's current capacity is changed to the
//     new_capacity (but not less that the number of items already on the
//     list). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.
//
//   void start( )
//     Postcondition: The first item on the Sequence becomes the current item
//     (but if the Sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     Sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the Sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the Sequence. In either case, the newly
//     inserted item is now the current item of the Sequence.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the Sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the Sequence. In either case, the newly
//     inserted item is now the current item of the Sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the Sequence, and the
//     item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the Sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the Sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the Sequence.
//
// VALUE SEMANTICS for the Sequence class:
//    Assignments and the copy constructor may be used with Sequence objects.
//
// DYNAMIC MEMORY USAGE by the List
//   If there is insufficient dynamic memory, then the following functions
//   throw a BAD_ALLOC exception: The constructors, insert, attach.

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <cstdlib>  // Provides size_t

namespace CSC21200::Project3 {

class Sequence {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 15;

        // CONSTRUCTORS and DESTRUCTOR
        Sequence(size_type initial_capacity = DEFAULT_CAPACITY);

        Sequence(const Sequence &source);

        ~Sequence();

        // MODIFICATION MEMBER FUNCTIONS
        void resize(size_type new_capacity);

        void start();

        void advance();

        void insert(const value_type &entry);

        void attach(const value_type &entry);

        void remove_current();

        void operator=(const Sequence &source);

        void operator+=(const Sequence &source);

        friend Sequence operator+(const Sequence &lhs, const Sequence &rhs);

        // CONSTANT MEMBER FUNCTIONS
        size_type size() const;

        bool is_item() const;

        value_type current() const;

        value_type operator[](size_type index) const;

    private:
        value_type *data;
        size_type used;
        size_type current_index;
        size_type capacity;
};

#endif

}