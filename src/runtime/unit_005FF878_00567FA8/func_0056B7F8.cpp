/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_function.h>
#include <stl_tempbuf.h>
#include <stl_heap.h>
#include <stl_algo.h>
struct Item { char pad[0x50]; int key; };
struct Node { Node *next; Node *prev; Item *data; };
struct Iter {
    typedef bidirectional_iterator_tag iterator_category;
    typedef Node *value_type;
    typedef int difference_type;
    typedef Node **pointer;
    typedef Node *&reference;
    Node *node;
    Iter() {}
    Iter(const Iter &o) : node(o.node) {}
    Node *&operator*() const { return *(Node **)&node; }
    Iter &operator++() { node = node->next; return *this; }
    Iter &operator--() { node = node->prev; return *this; }
    bool operator==(const Iter &o) const { return node == o.node; }
    bool operator!=(const Iter &o) const { return node != o.node; }
};
struct KeyLess {
    char state;
    bool operator()(Node *const &n, const unsigned short &k) const { return n->data->key < k; }
};
/* func_0056B7F8: the out-of-line __lower_bound<Iter, unsigned short, KeyLess, int> of SGI stl_algo.h */
template Iter __lower_bound(Iter, Iter, const unsigned short &, KeyLess, int *);
