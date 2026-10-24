/* compiler: ee-gcc2.96-stl */
/* Constructor of a network object that owns a map<int, int> (SGI STL, memalign allocator): the
   map's default constructor is inlined, with its _Compare() and allocator_type() temporaries. */
extern "C" void func_004A45D0(void*) throw();
#include <stl_tree.h>
#include <stl_map.h>

typedef unsigned char u8;

extern "C" void *func_00575E60(int heap, int size);


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
        return n != 0 ? (T *)func_00575E60(0x10, n * sizeof(T)) : 0;
    }
    void deallocate(T *p, size_type n) {
        func_004A45D0(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};


struct Data { int active; unsigned short *buf; unsigned char *payload; };
typedef pair<const unsigned, Data*> Value;
typedef GameAlloc<Value> Alloc;
typedef _Rb_tree<unsigned, Value, _Select1st<Value>, less<unsigned>, Alloc> Tree;
typedef map<unsigned, Data*, less<unsigned>, Alloc> Map;
extern "C" Tree::iterator func_0056FA40(Tree*,const unsigned&);
template<> inline Tree::iterator Tree::find(const unsigned &k) { return func_0056FA40(this,k); }
extern "C" void func_00487968(void*,void*) throw();
extern "C" void func_00488070(void*) throw();
extern "C" void func_004884C0(void*) throw();
extern "C" void func_004A4D68(void*);
extern "C" void func_004A4DD8(void*);
struct Guard {
 void *p;
 Guard(void *v):p(v) {func_004A4D68(p);}
 ~Guard() {func_004A4DD8(p);}
};
struct Owner { void *vtable; void *list; Map map; int unused; char mutex[48]; };
static inline Map::iterator lookup(Map *m,unsigned key) { return m->find(key); }
extern "C" int func_004898A0(Owner *s,int key) {
 Guard guard(s->mutex);
 Map::iterator it=s->map.find(key);
 if(it==s->map.end()) return -9;
 Data *data=it->second;
 if(data->active) {
  func_004884C0(data->payload);
  data->payload[11]|=32;
  *data->buf |= 1;
  func_00488070(s->list);
 }
 func_00487968(s->list,data->buf);
 func_004A45D0(data);
 s->map.erase(it);
 return 0;
}
