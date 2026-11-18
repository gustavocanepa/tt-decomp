/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_iterator.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <limits.h>
#include <stdlib.h>
#include <stl_tempbuf.h>
#include <stl_algo.h>
#include <stl_heap.h>
struct Elem { int words[3]; };
struct Cmp {
    char state;
    bool operator()(const Elem &, const Elem &) const;
};
struct Link { char pad0[0xE8]; Link *next; Link *other; };
/* Tree iterator: the node pointer follows a word this caller never sets. */
struct Q {
    int pad0;
    Link *node;
    Q(Link *n) : node(n) {}
    Q(const Q &);
};
struct Tree {
    char pad0[0x1E04];
    Link *head;
    int count;
    Q begin() { return Q(head->next); }
    Q end() { return Q(head); }
    Q erase(Q first, Q last) __asm__("func_00568098");
};
struct Pq {
    Elem data[0x3000 / sizeof(Elem)];
    int count;
    Cmp comp;
    char pad[3];
    Tree tree;
};
template <> void __adjust_heap(Elem *first, int hole, int len, Elem value, Cmp comp) __asm__("func_0056A4C0");
extern "C" void func_0056A4B0(Pq *);
extern "C" void func_0056A1E0(Pq *pq) {
    int n;
    while ((n = pq->count) != 0) {
        pop_heap(pq->data, pq->data + n, pq->comp);
        func_0056A4B0(pq);
    }
    pq->tree.erase(pq->tree.begin(), pq->tree.end());
}
