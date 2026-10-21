typedef int s32;
typedef unsigned char u8;

struct Obj00373DD8 {
    u8 pad[0xA4C];
    s32 unk9BC;
};

extern "C" s32 func_003A7928(void *arg0, s32 arg1);

extern "C" s32 func_0031C7D0(struct Obj00373DD8 *arg0, s32 arg1) {
    s32 temp_a2 = arg0->unk9BC * 0x1B4;
    return func_003A7928((void *)(temp_a2 + (s32)arg0 + 0x10), arg1);
}
