#include "types.h"

struct Res_001D1D38 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 pad[5];
};

extern "C" void func_004F7B74(char *buf, void *src);
extern "C" void func_004F7A30(char *buf, char *s);
extern "C" void func_0047DFB0(Res_001D1D38 *out, char *buf);

extern "C" s32 func_00198180(char *arg0, char *arg1) {
    char buf[0x80];
    Res_001D1D38 res;

    func_004F7B74(buf, arg0 + 4);
    if (*arg1 != 0) {
        func_004F7A30(buf, arg1 + 1);
    }
    func_0047DFB0(&res, buf);
    return res.unk8;
}
