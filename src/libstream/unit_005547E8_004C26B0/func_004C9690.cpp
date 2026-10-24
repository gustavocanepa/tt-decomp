#include "types.h"

struct Server {
    s32 sema;
    char pad4[0x3C];
    s32 arg;
};

extern Server D_00779680;
extern "C" void func_004F4348(s32 sema);
extern "C" void func_004F45D8(Server *s, s32 cmd, s32 a, s32 b, s32 c);

extern "C" void func_004C9690(s32 arg) {
    Server *s = &D_00779680;
    func_004F4348(s->sema);
    s->arg = arg;
    func_004F45D8(s, 6, 1, 0, 0);
}
