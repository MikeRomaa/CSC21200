// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include "node.h"

using namespace std;

namespace CSC21200::Project4 {

size_t list_length(const Node *head_ptr)
// Library facilities used: cstdlib
{
    const Node *cursor;
    size_t answer;

    answer = 0;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        ++answer;

    return answer;
}

void list_head_insert(Node *&head_ptr, const Node::value_type &entry) {
    head_ptr = new Node(entry, head_ptr);
}

void list_insert(Node *previous_ptr, const Node::value_type &entry) {
    Node *insert_ptr;

    insert_ptr = new Node(entry, previous_ptr->link());
    previous_ptr->set_link(insert_ptr);
}

Node *list_search(Node *head_ptr, const Node::value_type &target)
// Library facilities used: cstdlib
{
    Node *cursor;

    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        if (target == cursor->data())
            return cursor;
    return NULL;
}

const Node *list_search(const Node *head_ptr, const Node::value_type &target)
// Library facilities used: cstdlib
{
    const Node *cursor;

    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        if (target == cursor->data())
            return cursor;
    return NULL;
}

Node *list_locate(Node *head_ptr, size_t position)
// Library facilities used: cassert, cstdlib
{
    Node *cursor;
    size_t i;

    assert (0 < position);
    cursor = head_ptr;
    for (i = 1; (i < position) && (cursor != NULL); i++)
        cursor = cursor->link();
    return cursor;
}

const Node *list_locate(const Node *head_ptr, size_t position)
// Library facilities used: cassert, cstdlib
{
    const Node *cursor;
    size_t i;

    assert (0 < position);
    cursor = head_ptr;
    for (i = 1; (i < position) && (cursor != NULL); i++)
        cursor = cursor->link();
    return cursor;
}

void list_head_remove(Node *&head_ptr) {
    Node *remove_ptr;

    remove_ptr = head_ptr;
    head_ptr = head_ptr->link();
    delete remove_ptr;
}

void list_remove(Node *previous_ptr) {
    Node *remove_ptr;

    remove_ptr = previous_ptr->link();
    previous_ptr->set_link(remove_ptr->link());
    delete remove_ptr;
}

void list_clear(Node *&head_ptr)
// Library facilities used: cstdlib
{
    while (head_ptr != NULL)
        list_head_remove(head_ptr);
}

void list_copy(const Node *source_ptr, Node *&head_ptr, Node *&tail_ptr)
// Library facilities used: cstdlib
{
    head_ptr = NULL;
    tail_ptr = NULL;

    // Handle the case of the empty list.
    if (source_ptr == NULL)
        return;

    // Make the head node for the newly created list, and put data in it.
    list_head_insert(head_ptr, source_ptr->data());
    tail_ptr = head_ptr;

    // Copy the rest of the nodes one at a time, adding at the tail of new list.
    source_ptr = source_ptr->link();
    while (source_ptr != NULL) {
        list_insert(tail_ptr, source_ptr->data());
        tail_ptr = tail_ptr->link();
        source_ptr = source_ptr->link();
    }
}

void list_piece(
    const Node *start_ptr, const Node *end_ptr,
    Node *&head_ptr, Node *&tail_ptr
)
// Precondition: start_ptr and end_ptr are pointers to nodes on the same
// linked list, with the start_ptr node at or before the end_ptr node.
// Postcondition: head_ptr and tail_ptr are the head and tail pointers
// for a new list that contains the items from start_ptr up to but
// not including end_ptr.  The end_ptr may also be NULL, in which case
// the new list contains elements from start_ptr to the end of the list.
// Library facilities used: cstdlib
{
    head_ptr = NULL;
    tail_ptr = NULL;

    // Handle the case of the empty list.
    if (start_ptr == end_ptr)
        return;

    // Make the head node for the newly created list, and put data in it.
    list_head_insert(head_ptr, start_ptr->data());
    tail_ptr = head_ptr;

    // Copy the rest of the nodes one at a time, adding at the tail of new list.
    start_ptr = start_ptr->link();
    while (start_ptr != end_ptr) {
        list_insert(tail_ptr, start_ptr->data());
        tail_ptr = tail_ptr->link();
        start_ptr = start_ptr->link();
    }
}

}