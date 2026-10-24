/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef int s32;
typedef unsigned int u32;
struct P { u32 v; } __attribute__((packed));
struct Rec { char p[8]; char *f8; };
struct Obj { char p[4]; void *f4; char p8[0x48]; u32 f50; u32 f54; };
extern "C" Rec *func_00487850(void *, u32);
extern "C" void func_00487968(void *, void *);
extern "C" s32 func_0048BAC8(Obj *o, u32 idx) {
    u32 off = idx * 4;
    u32 q = off / o->f50;
    u32 r = off % o->f50;
    Rec *rec = func_00487850(o->f4, o->f54 + q);
    if (rec == 0) return -5;
    u32 v = ((P *)(rec->f8 + r))->v & 0x0FFFFFFF;
    func_00487968(o->f4, rec);
    return v;
}
