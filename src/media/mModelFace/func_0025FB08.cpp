#include "types.h"

struct Obj002BBFA8 {
    char pad0[0x368];
    s32 unk308;
};

struct Buf002BBFA8 {
    struct Obj002BBFA8 *unk0;
    char pad[0xC];
};

extern "C" void func_0025E718(struct Buf002BBFA8 *arg0);
extern "C" void func_0025E6C0(struct Buf002BBFA8 *arg0, int arg1);

extern "C" void func_0025FB08(void) {
    struct Buf002BBFA8 buf;
    struct Obj002BBFA8 *p;

    func_0025E718(&buf);
    p = buf.unk0;
    p->unk308 |= 1;
    func_0025E6C0(&buf, 2);
}
