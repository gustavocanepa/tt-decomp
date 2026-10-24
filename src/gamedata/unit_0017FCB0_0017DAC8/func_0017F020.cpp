#include "types.h"

struct Buf {
    s32 val;
    char pad[0xC];
};

extern "C" void func_0017C448(void *arg0, int arg1);
extern "C" void func_0017C4A0(void *arg0, void *arg1);
extern "C" void func_0017C8F8(s32 arg0, const char *arg1);

extern "C" void func_0017F020(void *arg0, void *arg1) {
    struct Buf buf;
    func_0017C4A0(&buf, arg1);
    func_0017C8F8(buf.val, "car");
    func_0017C448(&buf, 2);
}
