#include <cassert>
#include "bag.h"

Bag::size_type Bag::erase(const value_type &target) {
    Bag::size_type i = 0;
    Bag::size_type count = 0;

    while (i < used) {
        if (data[i] == target) {
            --used;
            data[i] = data[used];
            ++count;
        } else {
            ++i;
        }
    }

    return count;
}

bool Bag::erase_one(const Bag::value_type &target) {
    for (Bag::size_type i = 0; i < used; i++) {
        if (data[i] == target) {
            --used;
            data[i] = data[used];
            return true;
        }
    }

    return false;
}

void Bag::insert(const Bag::value_type &entry) {
    assert(this->size() < Bag::CAPACITY);

    data[used] = entry;
    ++used;
}

void Bag::operator+=(const Bag &addend) {
    assert(used + addend.used <= Bag::CAPACITY);

    Bag::size_type size = addend.used;

    for (Bag::size_type i = 0; i < size; i++) {
        this->insert(addend.data[i]);
    }
}

Bag::size_type Bag::count(const Bag::value_type &target) const {
    Bag::size_type count = 0;

    for (Bag::size_type i = 0; i < used; i++) {
        ++count;
    }

    return count;
}

Bag operator+(const Bag &lhs, const Bag &rhs) {
    assert(lhs.size() + rhs.size() <= Bag::CAPACITY);

    Bag bag;

    bag += lhs;
    bag += rhs;

    return bag;
}

Bag operator-(const Bag &lhs, const Bag &rhs) {
    Bag bag = lhs;

    for (Bag::size_type i = 0; i < rhs.used; i++) {
        bag.erase_one(rhs.data[i]);
    }

    return bag;
}
