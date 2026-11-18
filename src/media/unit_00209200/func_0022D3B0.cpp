/* compiler: ee-gcc2.96-stl */
/* The keys of a map<String, int> (SGI STL, include/stl) as a script array of strings. */
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

typedef map<Str, s32, less<Str>, GameAlloc<pair<const Str, s32> > > Map;

struct HObject;
struct HString;
struct HArrayObj;
struct HArray;

extern "C" void func_00295180(HArray *self);
extern "C" void func_002931B0(HArray *self, const HArray *other);
extern "C" void func_002931C8(HArray *self, int in_charge);
extern "C" void func_002A75A8(HObject *self, int in_charge);
extern "C" void func_002ADBF0(HString *self, int in_charge);
extern "C" void func_002B01F8(HString *self, const Str *s);

/* a counted reference to a script object */
struct HObject {
    void *p;
    HObject(const HObject &o);
    ~HObject() { func_002A75A8(this, 2); }
};

struct HString {
    void *p;
    HString(const Str &s) { func_002B01F8(this, &s); }
    HString(const HString &o);
    ~HString() { func_002ADBF0(this, 2); }
};

struct HArrayObj {
    HObject push_back(const HString &x) __asm__("func_002944D0");
};

struct HArray {
    HArrayObj *p;
    HArray() { func_00295180(this); }
    HArray(const HArray &o) { func_002931B0(this, &o); }
    ~HArray() { func_002931C8(this, 2); }
    HArrayObj *operator->() const { return p; }
};

struct Owner {
    char pad[0x20];
    Map names;
};

extern "C" HArray func_0022D3B0(const Owner *self) {
    HArray arr;
    for (Map::const_iterator it = self->names.begin(); it != self->names.end(); it++)
        arr->push_back(HString((*it).first));
    return arr;
}
