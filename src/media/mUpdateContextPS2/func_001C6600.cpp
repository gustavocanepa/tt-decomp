/* compiler: ee-gcc2.96-stl */
/* mUpdateContextPS2: release every entry of a map<String, Buffers> (SGI STL, include/stl), then clear it. */
#include <stl_tree.h>
#include <stl_map.h>

typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};
struct HeapName {
    const char *name;
};

extern "C" void *func_00326750(unsigned int size, int align, const char *name) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name) throw();
extern "C" HeapName *func_005C11A8(void);
extern "C" int func_005C2A50(const void *self, const void *other, unsigned int pos, unsigned int n);
extern char D_0069E910[];

/* the game's string: libstdc++ v2 basic_string */
struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    static char *data(Rep *r) { return (char *)(r + 1); }
    s32 length() const { return rep()->len; }
    void terminate() const { data(rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0) return D_0069E910;
        terminate();
        return data(rep());
    }
    ~Str() {
        Rep *q = rep();
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
    bool operator<(const Str &o) const { return func_005C2A50(this, &o, 0, (unsigned int)-1) < 0; }
};

struct TypeInfo {
    const char *name;
};
template <class T> struct TypeTag;

/* the game's allocator: every block is tagged with the name of its type */
template <class T>
class GameAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef GameAlloc<U> other; };
    GameAlloc() throw() {}
    GameAlloc(const GameAlloc &) throw() {}
    template <class U> GameAlloc(const GameAlloc<U> &) throw() {}
    ~GameAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return (T *)func_00326750(n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

extern "C" void func_0048F2B0(void *self, int in_charge);
extern "C" void func_0045DA70(void *self);

/* two owned blocks */
struct Buffers {
    void *a;
    void *b;
    ~Buffers() { func_0048F2B0(this, 2); }
    void release() { func_0045DA70(this); }
};

typedef pair<const Str, Buffers> Value;
typedef _Rb_tree_node<Value> Node;
typedef _Rb_tree<Str, Value, _Select1st<Value>, less<Str>, GameAlloc<Value> > Tree;
typedef map<Str, Buffers, less<Str>, GameAlloc<Value> > Map;

/* the tree's out-of-line _M_erase */
extern "C" void func_005275C0(Tree *self, Node *x);
template <> inline void Tree::_M_erase(Node *x) { func_005275C0(this, x); }

struct mUpdateContextPS2 {
    char pad[0x45C];
    Map buffers;
};

extern "C" void func_001C6600(mUpdateContextPS2 *self) {
    for (Map::iterator it = self->buffers.begin(); it != self->buffers.end(); it++)
        (*it).second.release();
    self->buffers.clear();
}
