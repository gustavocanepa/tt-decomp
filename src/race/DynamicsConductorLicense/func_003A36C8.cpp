typedef unsigned char u8;
typedef int s32;

struct Obj {
    u8 unk0;
    u8 unk1;
    u8 unk2;
};

extern "C" s32 func_003A36C8(s32 arg0) {
    struct Obj *p = (struct Obj *)(arg0 + 0x238E0);
    if (p->unk2 != 3) {
        return 0;
    }
    return p->unk1 != 1;
}
