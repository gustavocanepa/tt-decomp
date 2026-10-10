#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005D8EB8[];
s32 func_00400D68(s8 *);
void func_004CAFB8(s8 *);
void func_004CAFD0(s8 *);
void func_003FFF30(s8 *arg0) {
    s8 *temp_s1;
    temp_s1 = arg0 + 4;
    func_00400D68(arg0);
    *(s32 *)arg0 = (s32)D_005D8EB8;
    func_004CAFB8(temp_s1);
    func_004CAFD0(temp_s1);
}
