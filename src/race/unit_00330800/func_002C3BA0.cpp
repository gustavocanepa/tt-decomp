/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;

extern "C" void *func_004A4690(int heap, int size);
extern "C" void func_004A45D0(void *) throw();

template <class T>
class Alloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() throw() {}
    Alloc(const Alloc &) throw() {}
    template <class U> Alloc(const Alloc<U> &) throw() {}
    ~Alloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_004A4690(0x10, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) { func_004A45D0(p); }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef vector<char, Alloc<char> > Vec;

// Provisional image layout; tiling fields agree with func_002C39C8.
struct Image {
    char pad0[4];
    char *data;
    char pad8[8];
    s32 width;
    s32 height;
    s32 tileColumns;
    s32 tileRows;
    s32 elementSize;
};

extern "C" void func_002C39C8(Image *, s32, s32) throw();
extern "C" void func_002C5F28(char *, s32, s32, s32, s32, void *, s32);

// Preserve each row byte count when changing the element size.
// The const reference preserves the original inlined division guard.
static inline void rescale(Image *o, const s32 &newSize) {
    s32 width = o->width;
    s32 oldSize = o->elementSize;
    o->width = width * oldSize / newSize;
    o->elementSize = newSize;
}

extern "C" void func_002C3BA0(Image *image) {
    s32 t = image->tileColumns;
    if (t == 1 && image->tileRows == t) {
        s32 elementSize = image->elementSize;
        // SGI STL vector owns the temporary row buffer for this conversion.
        Vec v((Vec::size_type)(image->width * elementSize));
        for (s32 i = 0; i < image->height; i++) {
            func_002C5F28(image->data + image->width * image->elementSize * i, 1, elementSize, image->width, 1, &v, 0);
        }
        rescale(image, 1);
        func_002C39C8(image, elementSize, 1);
    }
}
