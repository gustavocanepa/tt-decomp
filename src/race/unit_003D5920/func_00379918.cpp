#include "types.h"
#define NULL 0

extern "C" {
void func_00385B68(void *);
s32 func_00385B30(void *);
s32 func_0055A848(void *, void *);
void func_0041FAC8(void *, s32, void *, s32);
extern char D_005F70E0[];
extern char func_00379800[];
}

extern "C" void func_00379918(char *arg0) {
    s32 s1;
    s32 s3;
    s32 v0;
    s32 *base;
    s32 *e;

    func_00385B68(arg0);
    if (func_00385B30(arg0) != 0) {
        s3 = 0;
        if (*(s32 *)(*(char **)(arg0 + 4) + 0xC) != 0) {
            do {
                s1 = 0;
                do {
                    v0 = func_0055A848(*(void **)(*(char **)(arg0 + 4) + 0xC), func_00379800);
                    base = (s32 *)(arg0 + 0xC);
                    e = base + (s3 * 4 + s1);
                    *e = v0;
                    if (v0 != 0) {
                        func_0041FAC8(*(void **)(*(char **)(arg0 + 4) + 0xC), v0, D_005F70E0, 1);
                    }
                    s1++;
                } while (s1 < 4);
                s3++;
            } while (s3 < 6);
        }
    }
}
