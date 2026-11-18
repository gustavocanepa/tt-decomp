#include "types.h"

extern "C" void *func_0047CA58(void *);
extern "C" void func_004AC838(void *, void *);
extern "C" void *func_0056DF88(void *);

extern char D_005DAA30[];
extern s32 D_0058E098;
extern char D_0058E0A0[];

extern "C" void func_004813B8(char *arg0) {
    s32 i;
    char *p;
    char *s3;

    i = 0;
    s3 = arg0 + 0xA8;
    func_0047CA58(arg0);
    *(s32 *)(arg0 + 0xA4) = (s32)D_005DAA30;
    func_0056DF88(s3);
    if (D_0058E098 > 0) {
        p = D_0058E0A0;
        do {
            *(s32 *)(p + 0x38) = (s32)arg0;
            func_004AC838(s3, p + 0x3C);
            i++;
            p += 0xF0;
        } while (i < D_0058E098);
    }
}
