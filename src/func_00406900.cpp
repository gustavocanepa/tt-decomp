typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x171];
    u8 unk171;
};

extern "C" s32 func_00406900(Obj *arg0) {
    u8 temp_v0 = arg0->unk171;
    return (temp_v0 == 0xFF) ? -1 : temp_v0;
}
