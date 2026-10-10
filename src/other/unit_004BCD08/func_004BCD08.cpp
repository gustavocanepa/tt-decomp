typedef int s32;

struct Struct_0054EF30 {
    char pad0[0x3E8];
    s32 unk3E8;
};

extern s32 func_004BDAF8(s32);
extern s32 D_00598418;
extern s32 D_00598410;

s32 func_004BCD08(struct Struct_0054EF30 *arg0)
{
    if (D_00598418 == 0 && D_00598410 != 0) {
        return func_004BDAF8(arg0->unk3E8);
    }
    return 0;
}
