/* compiler: ee-gcc2.96-stl */
/* mUpdateContextPS2: does any entry of the map<String, Buffers> (SGI STL, include/stl) answer to this name? */
#include <stl_tree.h>
#include <stl_map.h>

typedef int s32;
typedef unsigned int u32;

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
extern char D_005E8D90[];

/* the game's string: libstdc++ v2 basic_string */
struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    static char *data(Rep *r) { return (char *)(r + 1); }
    s32 length() const { return rep()->len; }
    void terminate() const { data(rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0) return D_005E8D90;
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
extern "C" u32 func_0045DC30(void *self, const char *name);

/* two owned blocks */
struct Buffers {
    void *a;
    void *b;
    ~Buffers() { func_0048F2B0(this, 2); }
    u32 has(const char *name) { return func_0045DC30(this, name); }
};

typedef pair<const Str, Buffers> Value;
typedef _Rb_tree_node<Value> Node;
typedef _Rb_tree<Str, Value, _Select1st<Value>, less<Str>, GameAlloc<Value> > Tree;
typedef map<Str, Buffers, less<Str>, GameAlloc<Value> > Map;

struct mUpdateContextPS2 {
    char pad[0x45C];
    Map buffers;
};

extern "C" bool func_001C6978(mUpdateContextPS2 *self, const Str &name) {
    for (Map::iterator it = self->buffers.begin(); it != self->buffers.end(); it++) {
        if ((*it).second.has(name.c_str()))
            return true;
    }
    return false;
}
