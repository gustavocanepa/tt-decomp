/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int x; char *vt; };
struct Handle { Obj *p; char pad[12]; };
struct Self { char pad[0x2C]; int x28,x2c; };
struct VE { short d,i; Handle *(*fn)(void *,unsigned); };
struct VI { short d,i; int (*fn)(void *); };
extern char D_007643F0[],D_007647B8[],D_00764B80[],D_00764F48[];
extern "C" void func_00295180(Handle *);
extern "C" int func_002901D0(Handle *,const char *);
extern "C" unsigned func_00294F40(Obj *);
extern "C" void func_002BD510(void *,unsigned,int);
extern "C" int func_002BD940(void *);
extern "C" void func_002931C8(Handle *,int);
extern "C" int func_002BF018();
static inline int get(Obj *o) {
    VI *e=(VI *)(o->vt+0x68);
    return e->fn((char *)o+e->d);
}
static inline Handle *at(Obj *o,unsigned i) {
    VE *e=(VE *)(o->vt+0x88);
    return e->fn((char *)o+e->d,i);
}
#define BODY(str,glob) { \
    func_00295180(&h); \
    if(func_002901D0(&h,str)) { \
        for(unsigned i=0;i<20 && i<func_00294F40(h.p);i++) \
            func_002BD510(glob,i,get(at(h.p,i)->p)); \
    } \
    self->x28=func_002BD940(glob); \
    func_002931C8(&h,2); \
}
extern "C" void func_001CC100(Self *self,int arg1) {
    Handle h;
    if(arg1==0) BODY("HugeAllocatorRelease",D_007643F0)
    else if(arg1==1) BODY("LargeAllocatorRelease",D_007647B8)
    else if(arg1==2) BODY("SmallAllocatorRelease",D_00764B80)
    else if(arg1==3) BODY("TinyAllocatorRelease",D_00764F48)
    self->x2c=func_002BF018();
}
