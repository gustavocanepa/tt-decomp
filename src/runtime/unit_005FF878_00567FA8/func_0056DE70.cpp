typedef unsigned char u8;
typedef int s32;

struct Obj {
    char pad[4];
    u8 *unk4;
};

extern "C" s32 func_0056DE70(struct Obj *arg0, s32 arg1) {
    u8 *p = arg0->unk4 + arg1;
    return (p[0] | (p[1] << 8) | (p[2] << 16)) | (p[3] << 24);
}
