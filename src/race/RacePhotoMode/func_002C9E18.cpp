#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00104E00(...) throw();
s32 func_002C9EA8(...) throw();

struct func_002C9E18_arg1 {
    char pad0[0x8];
    s32 unk8;
};
struct func_002C9E18_arg0 {
    char pad0[0x327A8];
    f32 unk327A8;
    f32 unk327AC;
};

void func_002C9E18(struct func_002C9E18_arg0 *arg0, struct func_002C9E18_arg1 *arg1) {
    s32 temp_s2;

    temp_s2 = (s32) (arg0->unk327A8 * (f32) arg1->unk8);
    func_002C9EA8(arg0, arg1, temp_s2, (s32) ((arg0->unk327AC * (f32) func_00104E00(arg1))));

}
