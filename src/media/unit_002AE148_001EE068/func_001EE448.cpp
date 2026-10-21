#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001EDC38(struct Buf00109C40 *arg0);
extern "C" void func_001EEDB0(s32 arg0);
extern "C" void func_001EDBE0(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001EE448(void) {
    struct Buf00109C40 buf;

    func_001EDC38(&buf);
    func_001EEDB0(buf.unk0);
    func_001EDBE0(&buf, 2);
}
