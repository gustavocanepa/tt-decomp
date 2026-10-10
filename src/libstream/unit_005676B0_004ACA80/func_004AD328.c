/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AD6C8(void *);                      /* extern */
s32 func_004AD7C0(void *);                      /* extern */
s32 func_004AD7C8(void *);                      /* extern */
s32 func_004A4D68();                            /* extern */
s32 func_004A4DD8(void *);                      /* extern */

struct func_004AD328_arg0 {
    char pad0[0x50];
    s32 unk50;
};

void func_004AD328(struct func_004AD328_arg0 *arg0) {
    func_004A4D68();
    if (arg0->unk50 != 0) {
        func_004AD6C8(arg0);
        func_004AD7C0(arg0);
        func_004AD7C8(arg0);
    }
    func_004A4DD8(arg0);
}
