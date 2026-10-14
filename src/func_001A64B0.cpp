/* compiler: ee-gcc2.96-nosib */
typedef int s32;

struct Obj {
    char pad0[0x1C];
    s32 f1c;
    char pad1[0x3C - 0x20];
    s32 f3c;
    char pad2[0x48 - 0x40];
    s32 f48;
    void *f4c;
    s32 f50;
    char pad3[0x5C - 0x54];
    s32 f5c;
    s32 f60;
};

extern "C" void func_001A66B0(Obj *r);
extern "C" char *func_001A65C0(Obj *o);
extern "C" char *func_001A6660(Obj *self);
extern "C" s32 func_001A6138(Obj *self);
extern "C" void func_0050E888(s32 arg0);
extern char D_005E71C8[];

extern "C" void func_001A64B0(void *arg0) {
    Obj *s0 = (Obj *)arg0;
    char *s1;
    if (s0->f48 != 0) {
        func_001A66B0(s0);
    } else {
        s1 = 0;
        s0->f60 = s0->f1c - 1;
        if (s0->f60 != -1) {
            do {
                s1 = func_001A65C0(s0);
                if (s1 != 0) {
                    break;
                }
                s1 = func_001A6660(s0);
                if (s1 == 0) {
                    s1 = (char *)func_001A6138(s0);
                }
                func_0050E888(s0->f5c);
                if (s1 != 0) {
                    break;
                }
                s0->f60 = s0->f60 - 1;
            } while (s0->f60 != -1);
        }
        if (s0->f4c != 0) {
            char *a2 = s1;
            if (s1 == 0) {
                a2 = D_005E71C8;
            }
            ((void (*)(s32, s32, char *))s0->f4c)(s0->f50, 0, a2);
        }
        s0->f3c = 0;
        s0->f4c = 0;
    }
}
