/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;
struct VEntry { s16 delta; s16 pad; void (*fn)(void *, void *, s32, void *); };
struct Vt { char pad[4]; VEntry *vtbl; };
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_0029CF48(void *, void *);
extern "C" s32 func_0029E9F0(void *);
extern "C" void func_002A7578(void *, void *);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002A7A30(void *);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
struct Handle {
    void *p;
    Handle() __asm__("func_002A7A30");
    ~Handle() __asm__("func_002A75A8");
    Handle &operator=(const Handle &src) {
        if (this != &src) {
            void *n=src.p;
            if(n) func_002C0FE8(n);
            if(p) func_002C1050(p);
            p=n;
        }
        return *this;
    }
};
struct Temp { void *p; char pad[12]; void *get() const { return p; } };
extern "C" s32 func_0027EDF8(Vt **self, void *a1, void *a2) {
    if (*self) {
        Handle hs[2];
        Temp d;
        Temp e;
        void *t1=a1;
        func_002A7578(&d,&t1);
        hs[0]=*(Handle *)&d;
        func_002A75A8(&d,2);
        Handle *h2=hs+1;
        void *t2=a2;
        func_002A7578(&d,&t2);
        *h2=*(Handle *)&d;
        func_002A75A8(&d,2);
        func_002A7A30(&d);
        Vt *o=*self;
        VEntry *v=o->vtbl+0xC0/8;
        v->fn((char *)o+v->delta,&d,2,hs);
        func_0029CF48(&e,&d);
        s32 r=func_0029E9F0(e.get());
        func_0029CEF0(&e,2);
        func_002A75A8(&d,2);
        return r;
    }
    return 0;
}
