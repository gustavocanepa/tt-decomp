#include "types.h"

struct Buf002839C8 {
    void *unk0;
    char pad[0xC];
};

extern "C" void func_0021F5D8(struct Buf002839C8 *arg0);
extern "C" void func_0021FDF8(void *arg0, s32 arg1);
extern "C" void func_0021F580(struct Buf002839C8 *arg0, int arg1);

extern "C" void MChaseActor__doStop(void) {
    struct Buf002839C8 buf;

    func_0021F5D8(&buf);
    func_0021FDF8(buf.unk0, 1);
    func_0021F580(&buf, 2);
}
