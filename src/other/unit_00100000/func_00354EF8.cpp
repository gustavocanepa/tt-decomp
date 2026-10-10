typedef int s32;
typedef unsigned char u8;

struct Inner0039FC50 {
    char pad0[0xDC];
    s32 unkDC;
};

struct Obj0039FC50 {
    char pad0[0x4];
    struct Inner0039FC50 *unk4;
    char pad1[0x3D - 0x8];
    u8 unk3C;
};

extern "C" void func_00359098(void *arg0);

extern "C" void func_00354EF8(struct Obj0039FC50 *arg0) {
    if (arg0->unk3C != 0 && arg0->unk4->unkDC == 0) {
        func_00359098((char *)arg0 + 0x1130);
    }
}
