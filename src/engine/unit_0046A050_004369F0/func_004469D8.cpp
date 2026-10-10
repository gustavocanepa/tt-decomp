extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00446C20(...) throw();
void func_00446E60(...) throw();
s32 func_00448478(...) throw();

struct func_004469D8_arg0 {
    char pad0[0x6C];
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
};

void func_004469D8(char *arg0, s32 arg1) {
    func_00448478(arg0 + 0x8C, arg0);
    ((struct func_004469D8_arg0 *)arg0)->unk6C = 0;
    ((struct func_004469D8_arg0 *)arg0)->unk74 = 1;
    ((struct func_004469D8_arg0 *)arg0)->unk70 = 0;
    ((struct func_004469D8_arg0 *)arg0)->unk78 = 0;
    func_00446E60(arg0, arg1);
    func_00446C20(arg0, arg1);
}

}
