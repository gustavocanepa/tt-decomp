#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001BE1C0(struct Buf00109C40 *arg0);
extern "C" void func_001BED60(s32 arg0);
extern "C" void func_001BE168(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001BE598(void) {
    struct Buf00109C40 buf;

    func_001BE1C0(&buf);
    func_001BED60(buf.unk0);
    func_001BE168(&buf, 2);
}
