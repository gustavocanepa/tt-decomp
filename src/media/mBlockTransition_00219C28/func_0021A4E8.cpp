#include "types.h"

struct S;
struct E;
struct Obj;

extern "C" struct E *BlockUnit__initialize(struct S *s, int i, int j);
extern "C" s32 func_00219768(struct Obj *arg0, f32 fparg0);

struct Obj {
    char pad0[0x2C];
    f32 f2C;
    s32 n30;
    s32 n34;
};

extern "C" s32 func_0021A4E8(struct Obj *arg0) {
    s32 flag = 1;
    s32 i = 0;
    if (arg0->n34 > 0) {
        do {
            s32 j = 0;
            if (arg0->n30 > 0) {
                do {
                    s32 cur = j;
                    j += 1;
                    s32 r = func_00219768(
                        (struct Obj *)BlockUnit__initialize((struct S *)arg0, cur, i),
                        arg0->f2C);
                    flag = (r != 0) ? 0 : flag;
                } while (j < arg0->n30);
            }
            i += 1;
        } while (i < arg0->n34);
    }
    return flag;
}
