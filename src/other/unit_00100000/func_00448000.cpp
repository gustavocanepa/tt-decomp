/* map lookup: SGI STL _Rb_tree::find (func_0056BE60) with the iterator modelled as in stl_tree.h
   (user copy constructor, so it is returned through a hidden pointer and end() is a memory temp) */
typedef int s32;

struct Node {
    char pad[0x14];
    s32 value;
};

struct BaseIter {
    Node *node;
};

inline bool operator==(const BaseIter &a, const BaseIter &b) { return a.node == b.node; }

struct Iter : BaseIter {
    Iter() {}
    Iter(Node *n) { node = n; }
    Iter(const Iter &o) { node = o.node; }
};

struct Map {
    s32 alloc;
    Node *header;
    Iter end() { return header; }
};

extern "C" Iter func_0056BE60(Map *, s32);

extern "C" s32 *func_00448000(Map *self, s32 key) {
    Iter it = func_0056BE60(self, key);
    return it == self->end() ? 0 : &it.node->value;
}
