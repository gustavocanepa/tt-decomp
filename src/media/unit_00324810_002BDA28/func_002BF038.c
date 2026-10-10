/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002BFCC0(s32);                     /* extern */
s32 func_002BD9C0();                            /* extern */
s32 func_002BDAB0(s32, s32);                /* extern */

extern char D_0057C9B8[];
extern char D_0057CA00[];
void func_002BF038(s32 arg0) {
    func_002BFCC0((s32)D_0057CA00);
    func_002BDAB0((s32)D_0057C9B8, arg0);
    func_002BD9C0();
}
