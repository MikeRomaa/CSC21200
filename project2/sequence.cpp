#include <cassert>
#include "sequence.h"

namespace CSC21200::Project2 {

Sequence::Sequence() {
    used = 0;
    current_index = 0;
}

void Sequence::start() {
    current_index = 0;
}

void Sequence::advance() {
    assert(this->is_item());

    ++current_index;
}

void Sequence::insert(const Sequence::value_type &entry) {
    assert(this->size() < Sequence::CAPACITY);

    if (!this->is_item()) {
        current_index = 0;
    }

    for (Sequence::size_type i = used; i > current_index; i--) {
        data[i] = data[i - 1];
    }

    data[current_index] = entry;
    ++used;
}

void Sequence::attach(const Sequence::value_type &entry) {
    assert(this->size() < Sequence::CAPACITY);

    if (!this->is_item()) {
        current_index = used;
    } else {
        ++current_index;
    }

    for (Sequence::size_type i = used; i > current_index; i--) {
        data[i] = data[i - 1];
    }

    data[current_index] = entry;
    ++used;
}

void Sequence::remove_current() {
    assert(this->is_item());

    for (Sequence::size_type i = current_index; i < used; i++) {
        data[i] = data[i + 1];
    }

    --used;
}

Sequence::size_type Sequence::size() const { return used; }

bool Sequence::is_item() const { return current_index < used; }

Sequence::value_type Sequence::current() const { return data[current_index]; }

}