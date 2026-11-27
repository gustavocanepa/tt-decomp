#include "types.h"

struct Obj {
    char pad0[0x50];
    s32 unk50;
    char pad54[0xCC - 0x54];
    f32 unkBC;
};

struct Src {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

struct Sub {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

extern "C" s32 RaceDisplay__is_play_mode(Obj *arg0);
extern "C" void func_00359148(s32 arg0, f32 fparg0);
extern "C" s32 func_00359DB0(void *arg0);
extern "C" void func_00363718(char *arg0, f32 fparg0, f32 fparg1);

extern "C" void func_00357808(Obj *arg0, Src *arg1) {
    s32 temp_s1;
    Sub *temp_v1;
    s32 r2;

    if (RaceDisplay__is_play_mode(arg0) == 0) {
        temp_s1 = arg1->unk8;
        if (temp_s1 != arg0->unk50) {
            func_00359148((s32)((char *)arg0 + 0x1130), 0x1.6p3f);
            if (!(arg0->unkBC < 0x1.0p0f) && (func_00359DB0((char *)arg0 + 0x239C) == 0)) {
                r2 = func_00359DB0((char *)arg0 + 0x2A2C);
                temp_v1 = (Sub *)((char *)arg0 + 0x4F84);
                if (r2 == 0) {
                    arg0->unk50 = temp_s1;
                    temp_v1->unk18 = temp_s1;
                    temp_v1->unk1C = arg1->unkC;
                    func_00363718((char *)temp_v1, 0x1.4p3f, 0x1.0p-1f);
                }
            }
        }
    }
}
