typedef int s32;
typedef unsigned char u8;

struct Obj {
    s32 unk0;
};

extern "C" u8 *func_002FD378(s32 arg0);

extern "C" s32 func_0030C348(Obj *arg0) {
    s32 temp_v1 = arg0->unk0;
    if (temp_v1 == 0) {
        return 0;
    }
    return *func_002FD378(temp_v1 + 0x600);
}
