/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0033DF60(void *, s32);             /* extern */
s32 func_0033E078(void *, s32);             /* extern */
s32 func_0033E130(void *, s32);             /* extern */
s32 func_0033E230(void *, s32);             /* extern */
s32 func_0033E250(void *, s32);             /* extern */
s32 func_0036E3C0(void *, s32);             /* extern */
s32 func_00386CC8();                            /* extern */
s32 func_0042B9A0();                            /* extern */

struct RaceFreeRun__virtual_87_arg0 {
    char pad0[0x39DF8];
    s32 unk39DF8;
    char pad39DFC[0x4];
    s32 unk39E00;
    s32 unk39E04;
};

void RaceFreeRun__cleanup(struct RaceFreeRun__virtual_87_arg0 *arg0) {
    func_00386CC8();
    arg0->unk39DF8 = 0;
    arg0->unk39E04 = 0;
    arg0->unk39E00 = 0;
    func_0036E3C0(arg0, 0);
    func_0042B9A0();
    func_0033DF60(arg0, 0);
    func_0033E078(arg0, 0);
    func_0033E250(arg0, 0);
    func_0033E130(arg0, 0);
    func_0033E230(arg0, 0);
}
