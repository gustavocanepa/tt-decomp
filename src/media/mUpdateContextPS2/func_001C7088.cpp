typedef int s32;
typedef unsigned char u8;

struct Obj {
    u8 pad[0x458];
    s32 unk420;
};

struct D_Obj {
    u8 pad[0x78];
    s32 unk78;
};

extern D_Obj D_00579534;

extern "C" void *func_001C7088(Obj *arg0) {
    void *result = (char *)arg0 + 0x41C;
    if (arg0->unk420 == 0) {
        result = (char *)&D_00579534 + D_00579534.unk78 * 0x3C;
    }
    return result;
}
