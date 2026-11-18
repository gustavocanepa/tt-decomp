#include "types.h"
struct Db { char p[0x1EC]; int f1E4; };
extern Db D_00585A30;
extern char D_005FBFD8[];
extern "C" int func_0040B940(void *, int, int, void *);
extern "C" const char *func_00411D78(int, int);

extern "C" const char *func_0040FF60(unsigned long arg0) {
    s32 buf[4];
    int key = (int)(arg0 & 0xFFFFFFFFUL);
    if (func_0040B940(&D_00585A30, key, 0x28, buf) == 0)
        return D_005FBFD8;
    return func_00411D78(D_00585A30.f1E4, buf[0]);
}
