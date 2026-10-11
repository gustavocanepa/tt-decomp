/* SGI STL (stl_alloc.h) __malloc_alloc_template<0>::_S_oom_malloc with gcc 2.96's
   __THROW_BAD_ALLOC: D_005A2988 << "out of memory" << endl; exit(1). */
typedef unsigned int size_t;

struct ostream;
extern "C" ostream &func_004E3E70(ostream &os, const char *s);
extern "C" ostream &func_004E44A8(ostream &os);
extern "C" void func_004F4F90(int status) __attribute__((noreturn));
extern "C" void *func_004A45F8(size_t n);

struct ostream {
    char pad[1];
    ostream &operator<<(const char *s) { return func_004E3E70(*this, s); }
    ostream &operator<<(ostream &(*f)(ostream &)) { return f(*this); }
};

extern ostream D_005A2988;
extern const char D_00601380[];
extern void (*D_00578D0C)();

extern "C" void *func_00568A98(size_t n) {
    void (*handler)();
    void *result;
    for (;;) {
        handler = D_00578D0C;
        if (0 == handler) {
            D_005A2988 << D_00601380 << func_004E44A8;
            func_004F4F90(1);
        }
        (*handler)();
        result = func_004A45F8(n);
        if (result)
            return result;
    }
}
