typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Holder {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" void func_002A7590(void *, s32);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002A7A30(void *);

extern "C" void *func_00294560(void *arg0, void *arg1) {
    s32 buf0[4];
    Holder *h = (Holder *)((char *)arg1 + 0x10);
    if (h->unk4 != h->unk8) {
        func_002A7590(buf0, h->unk8 - 4);
        s32 p = h->unk8 - 4;
        h->unk8 = p;
        func_002A75A8((void *)p, 2);
        func_002A7590(arg0, (s32)buf0);
        func_002A75A8(buf0, 2);
    } else {
        func_002A7A30(arg0);
    }
    return arg0;
}
