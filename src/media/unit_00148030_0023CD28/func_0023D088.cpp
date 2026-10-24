#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0023D980(struct Buf00109C40 *arg0);
extern "C" void func_0023D5C8(s32 arg0);
extern "C" void func_0023D928(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0023D088(void) {
    struct Buf00109C40 buf;

    func_0023D980(&buf);
    func_0023D5C8(buf.unk0);
    func_0023D928(&buf, 2);
}
