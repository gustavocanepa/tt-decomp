/* compiler: ee-gcc2.96-no-strict-aliasing */
/* With func_005038D8 / func_00503928 around it (they bracket critical sections in this library),
   polls func_004C2B68(o) until it returns non-zero or func_004C2868(o, &o->queue) reports false;
   returns the last func_004C2B68 result. The loop is entered at its test (`b` to the
   func_004C2B68 call): only a do-while entered by goto reproduces that; while/for/do forms
   rotate it differently. The andi is an explicit `& 1` on its bool result. */
#include "types.h"

struct func_004C2BB8_a0 {
    char pad0[0xC];
    s32 queue;
};

extern "C" s32 func_005038D8(void);
extern "C" s32 func_00503928(void);
extern "C" bool func_004C2868(struct func_004C2BB8_a0 *o, s32 *queue);
extern "C" s32 func_004C2B68(struct func_004C2BB8_a0 *o);

extern "C" s32 func_004C2BB8(struct func_004C2BB8_a0 *o) {
    s32 r;
    func_005038D8();
    goto test;
    do {
        if (!(func_004C2868(o, &o->queue) & 1))
            break;
    test:
        r = func_004C2B68(o);
    } while (r == 0);
    func_00503928();
    return r;
}
