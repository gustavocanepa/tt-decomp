/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Obj { char pad[0x3E8]; void *f3E8; };
extern "C" int func_004BDC48(void);
extern "C" int func_004BDC58(void *);
extern int D_00598410;
extern "C" float func_004BCB68(Obj *o) {
    float r = 0.0f;
    if (D_00598410 != 0) {
        u32 a = func_004BDC58(o->f3E8);
        u32 b = func_004BDC48();
        r = (float)a;
        r /= (float)b;
    }
    return r;
}
