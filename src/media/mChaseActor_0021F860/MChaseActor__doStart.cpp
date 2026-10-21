#include "types.h"

struct Buf00283990 {
    void *unk0;
    char pad[0xC];
};

extern "C" void func_0021F5D8(struct Buf00283990 *arg0);
extern "C" void func_0021FDF8(void *arg0, s32 arg1);
extern "C" void func_0021F580(struct Buf00283990 *arg0, int arg1);

extern "C" void MChaseActor__doStart(void) {
    struct Buf00283990 buf;

    func_0021F5D8(&buf);
    func_0021FDF8(buf.unk0, 0);
    func_0021F580(&buf, 2);
}
