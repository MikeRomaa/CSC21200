#include <cassert>
#include "sequence.h"

namespace CSC21200::Project4 {

Sequence::Sequence() {
    head_ptr = nullptr;
    tail_ptr = nullptr;
    cursor = nullptr;
    precursor = nullptr;
    many_nodes = 0;
}

Sequence::Sequence(const Sequence &source) {
    head_ptr = nullptr;
    tail_ptr = nullptr;
    cursor = nullptr;
    precursor = nullptr;
    many_nodes = 0;

    *this = source;
}

Sequence::~Sequence() {
    cursor = head_ptr;
    while (cursor != nullptr) {
        auto next = cursor->link();
        delete cursor;
        cursor = next;
    }
}

void Sequence::start() {
    precursor = nullptr;
    cursor = head_ptr;
}

void Sequence::advance() {
    precursor = cursor;
    cursor = cursor->link();
}

void Sequence::insert(const Sequence::value_type &entry) {
    if (!this->is_item() || cursor == head_ptr) {
        if (this->size() == 0) {
            auto new_node = new Node(entry);
            head_ptr = new_node;
            tail_ptr = new_node;
        } else {
            list_head_insert(head_ptr, entry);
        }

        this->start();
    } else {
        list_insert(precursor, entry);
        cursor = precursor->link();
    }

    ++many_nodes;
}

void Sequence::attach(const Sequence::value_type &entry) {
    if (!this->is_item()) {
        cursor = tail_ptr;
    }

    if (this->size() == 0) {
        auto new_node = new Node(entry);
        head_ptr = new_node;
        tail_ptr = new_node;
        cursor = tail_ptr;
    } else {
        list_insert(cursor, entry);
        this->advance();

        if (cursor->link() == nullptr) {
            tail_ptr = cursor;
        }
    }

    ++many_nodes;
}

void Sequence::operator=(const Sequence &source) {
    if (this == &source) {
        return;
    }

    if (size() != 0) {
        list_clear(head_ptr);
    }

    if (!source.is_item()) {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        precursor = nullptr;
        cursor = nullptr;
    } else if (source.cursor == source.head_ptr) {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        this->start();
    } else {
        list_piece(source.head_ptr, source.cursor, head_ptr, precursor);
        list_piece(source.cursor, nullptr, cursor, tail_ptr);
        precursor->set_link(cursor);
    }

    many_nodes = source.many_nodes;
}

void Sequence::remove_current() {
    assert(this->is_item());

    auto next = cursor->link();
    delete cursor;
    cursor = next;

    if (precursor == nullptr) {
        // First node of the list was deleted
        head_ptr = cursor;
    } else {
        // Intermediate node of the list was deleted
        precursor->set_link(cursor);
    }

    --many_nodes;
}

Sequence::value_type Sequence::current() const {
    assert(this->is_item());

    return cursor->data();
}

}