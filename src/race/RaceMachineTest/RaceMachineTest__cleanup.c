/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0033DF60(s32, s32);                /* extern */
s32 func_0033E078(s32, s32);                /* extern */
s32 func_00386CC8();                            /* extern */

void RaceMachineTest__cleanup(s32 arg0) {
    func_00386CC8();
    func_0033DF60(arg0, 0);
    func_0033E078(arg0, 0);
}
