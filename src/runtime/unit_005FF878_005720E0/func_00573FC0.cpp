typedef int s32;
typedef short s16;

struct VE {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj {
    char pad0[0x30];
    s32 match;
    char pad34[0x30];
    char *vt;
    char pad68[0x260 - 0x68];
};

extern char D_005A0B88[];

extern "C" void func_004A4930(Obj *arg0);
extern "C" void func_004A4970(Obj *arg0);

extern "C" void func_00573FC0(void *a0, Obj *self, s32 count, s32 arg, s32 match) {
    s32 i;
    Obj *p = self;

    func_004A4930((Obj *)D_005A0B88);
    if (match != 0) {
        if (count > 0) {
            i = 0;
            do {
                if (p->match == match) {
                    VE *e = (VE *)(p->vt + 0x18);
                    e->fn((char *)p + e->delta, arg);
                }
                i++;
                p++;
            } while (i < count);
        }
    } else if (count > 0) {
        do {
            count--;
            VE *e = (VE *)(p->vt + 0x18);
            e->fn((char *)p + e->delta, arg);
            p++;
        } while (count != 0);
    }
    func_004A4970((Obj *)D_005A0B88);
}
