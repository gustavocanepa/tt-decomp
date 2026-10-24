#include "types.h"

extern char D_005B7A70[];

/* hObject; its constructor is func_002A7618 (named after it so __13func_0030A678 resolves). */
struct func_002A7618 {
    s32 m0;
    char *vtbl;
    s32 m8, mC;
    func_002A7618();
};

/* A standard-style allocator object: the default argument `Alloc()` of the vector constructor is
   a stack temporary passed by reference, which leaves an unused 16-byte slot in the frame. */
struct Alloc {
    Alloc() {}
    Alloc(const Alloc &) {}
};

struct NodeVector {
    Alloc a;
    s32 *start, *finish, *eos;
    NodeVector(const Alloc &al = Alloc()) : a(al), start(0), finish(0), eos(0) {}
};

struct mDomNodeList : func_002A7618 {
    NodeVector nodes;
    mDomNodeList();
};

mDomNodeList::mDomNodeList() {
    vtbl = D_005B7A70;
}
