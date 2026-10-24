#include "types.h"

struct Obj {
    char pad[0x10];
    s32 unk10;
    s32 unk14;
    s32 state;
};

extern "C" void func_001FC570(Obj *o) {
    switch (o->state) {
    case 0:
        o->state = 1;
        break;
    case 1:
        break;
    case 2:
        o->unk10 = 0;
        o->state = 3;
        break;
    }
}
