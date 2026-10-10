typedef unsigned char u8;
typedef int s32;

extern char D_005F1450[];

struct Obj {
    u8 pad[0x8];
    char *unk10;
};

extern "C" char *func_002A9FF8(Obj *arg0) {
    char **fieldPtr = &arg0->unk10;
    char *p = *fieldPtr;
    s32 len = *(s32 *)(p - 0x10);
    if (len == 0) {
        return D_005F1450;
    }
    p[len] = 0;
    return *fieldPtr;
}
