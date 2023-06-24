#include <cassert>
#include <algorithm>
#include "sequence.h"

namespace CSC21200::Project3 {

Sequence::Sequence(Sequence::size_type initial_capacity) {
    data = new value_type[initial_capacity];
    used = 0;
    current_index = 0;
    capacity = initial_capacity;
}

Sequence::Sequence(const Sequence &source) {
    data = new value_type[source.capacity];
    std::copy_n(source.data, source.used, data);

    used = source.used;
    current_index = source.current_index;
    capacity = source.capacity;
}

Sequence::~Sequence() {
    delete[] data;
}

void Sequence::resize(Sequence::size_type new_capacity) {
    if (new_capacity == capacity || new_capacity < used) return;

    auto *new_data = new value_type[new_capacity];

    std::copy_n(data, used, new_data);
    delete[] data;

    data = new_data;
    capacity = new_capacity;
}

void Sequence::start() {
    current_index = 0;
}

void Sequence::advance() {
    assert(this->is_item());

    ++current_index;
}

void Sequence::insert(const Sequence::value_type &entry) {
    if (this->size() == capacity) {
        this->resize(capacity * 1.1);
    }

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
    if (this->size() == capacity) {
        this->resize(capacity * 1.1);
    }

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

void Sequence::operator=(const Sequence &source) {
    if (this == &source) {
        return;
    }

    if (capacity != source.capacity) {
        delete[] data;
        data = new value_type[source.capacity];
    }

    std::copy_n(source.data, source.used, data);

    used = source.used;
    current_index = source.current_index;
    capacity = source.capacity;
}

void Sequence::operator+=(const Sequence &source) {
    this->resize(capacity + source.capacity);
    std::copy_n(source.data, source.used, data + used);

    used += source.used;
}

Sequence operator+(const Sequence &lhs, const Sequence &rhs) {
    Sequence new_sequence;

    new_sequence.resize(lhs.capacity + rhs.capacity);
    std::copy_n(lhs.data, lhs.used, new_sequence.data);
    std::copy_n(rhs.data, rhs.used, new_sequence.data + lhs.used);

    new_sequence.used = lhs.used + rhs.used;

    return new_sequence;
}

Sequence::size_type Sequence::size() const { return used; }

bool Sequence::is_item() const { return current_index < used; }

Sequence::value_type Sequence::current() const { return data[current_index]; }

Sequence::value_type Sequence::operator[](Sequence::size_type index) const { return data[index]; }

}