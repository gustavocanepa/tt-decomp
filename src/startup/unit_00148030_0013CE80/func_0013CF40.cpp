/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VT { s16 off; s16 pad; s32 (*fn)(void *); };
struct Obj { char pad[4]; char *vt; };
struct Holder { char pad[4]; Obj *o; };

extern "C" void func_00128418(void *, int);
extern "C" void func_00128470(void *, void *);
extern "C" void func_0013CAB0(void *, int) throw();
extern "C" void func_0013CB08(void *, void *) throw();
extern "C" void func_0013D808(void *, void *, int);

extern "C" void func_0013CF40(void *arg0, void *arg1, int arg2, Holder *arg3) {
    void *sp[8];
    void *sp20[8];
    void *sp40[4];
    if (arg2 >= 2) {
        Obj *o = arg3->o;
        VT *v = (VT *)(o->vt + 0x68);
        s32 r = v->fn((char *)o + v->off);
        func_0013CB08(sp, arg1);
        void *h = sp[0];
        void **p = sp20;
        func_00128470(p, arg3);
        func_0013D808(h, *p, r);
        func_00128418(p, 2);
        func_0013CAB0(sp, 2);
    } else if (arg2 > 0) {
        func_0013CB08(sp, arg1);
        void *h = sp[0];
        void **p = sp40;
        func_00128470(p, arg3);
        func_0013D808(h, *p, -1);
        func_00128418(p, 2);
        func_0013CAB0(sp, 2);
    }
}
