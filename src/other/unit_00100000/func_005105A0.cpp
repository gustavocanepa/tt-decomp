typedef int s32;
typedef signed char s8;

struct Obj005C44B8 {
    char pad[0x3B4];
    s8 unk3B4;
};

extern "C" Obj005C44B8 *D_00579774;

extern "C" void func_005105A0(s32 arg0, s32 arg1) {
    Obj005C44B8 *temp_v0 = D_00579774;

    if (temp_v0 != 0) {
        temp_v0->unk3B4 = arg1;
    }
}
