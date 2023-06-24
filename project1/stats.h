// Provided by:   Michael Romashov
// Email Address: mromash000@citymail.cuny.edu
// FILE: stats.h
// CLASS PROVIDED: Statistician
//   (a class to keep track of statistics on a sequence of real numbers)
//
// CONSTRUCTOR for the Statistician class:
//   Statistician();
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of numbers. Various statistics will be calculated about the
//     sequence.
//
// PUBLIC MODIFICATION member functions for the Statistician class:
//   void next(double r)
//     The number r has been given to the Statistician as the next number in
//     its sequence of numbers.
//   void reset();
//     Postcondition: The Statistician has been cleared, as if no numbers had
//     yet been given to it.
//
// PUBLIC CONSTANT member functions for the Statistician class:
//   int length() const
//     Postcondition: The return value is the length of the sequence that has
//     been given to the Statistician (i.e., the number of times that the
//     next(r) function has been activated).
//   double sum() const
//     Postcondition: The return value is the sum of all the numbers in the
//     Statistician's sequence.
//   double mean() const
//     Precondition: length() > 0
//     Postcondition: The return value is the arithmetic mean (i.e., the
//     average of all the numbers in the Statistician's sequence).
//   double minimum() const
//     Precondition: length() > 0
//     Postcondition: The return value is the tinyest number in the
//     Statistician's sequence.
//   double maximum() const
//     Precondition: length() > 0
//     Postcondition: The return value is the largest number in the
//     Statistician's sequence.
//
// NON-MEMBER functions for the Statistician class:
//   Statistician operator+(const Statistician& lhs, const Statistician& rhs)
//     Postcondition: The Statistician that is returned contains all the
//     numbers of the sequences of lhs and rhs.
//   Statistician operator*(double scalar, const Statistician& stat)
//     Postcondition: The Statistician that is returned contains the same
//     numbers that stat does, but each number has been multiplied by the
//     scalar.
//   bool operator==(const Statistician& lhs, const Statistician& rhs)
//     Postcondition: The return value is true if lhs and rhs have the zero
//     length. Also, if the length is greater than zero, then lhs and rhs must
//     have the same length, the same mean, the same minimum,
//     the same maximum, and the same sum.
//
// VALUE SEMANTICS for the Statistician class:
// Assignments and the copy constructor may be used with Statistician objects.

#ifndef STATS_H
#define STATS_H

#include <iostream>

namespace CSC21200::Project1 {

class Statistician {
    public:
        // CONSTRUCTOR
        Statistician();

        // MODIFICATION MEMBER FUNCTIONS
        void next(double r);

        void reset();

        // CONSTANT MEMBER FUNCTIONS
        int length() const;

        double sum() const;

        double mean() const;

        double minimum() const;

        double maximum() const;

        // FRIEND FUNCTIONS
        friend Statistician operator+(
            const Statistician &lhs,
            const Statistician &rhs
        );

        friend Statistician operator*(double scalar, const Statistician &stat);

    private:
        int count{};       // How many numbers in the sequence
        double total{};    // The sum of all the numbers in the sequence
        double tinyest{};  // The smallest number in the sequence
        double largest{};  // The largest number in the sequence
};

// NON-MEMBER functions for the Statistician class
bool operator==(const Statistician &lhs, const Statistician &rhs);

#endif

}