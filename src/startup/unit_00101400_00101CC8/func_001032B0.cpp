#include "types.h"
struct Result { s32 err; s32 p4; u32 size; s32 pc; s32 pad[4]; };
extern "C" {
void *func_00103248(void *, void *);
void func_001034A8(s32);
s32 func_0028FCE8(void *, s32, const char *);
s32 func_003FC600(void);
void func_003FC620(void *, s32, s32);
void func_0047DFB0(Result *, void *);
s32 func_004AE750(s32, u32);
}
extern char D_00623D88[];
extern s32 D_005794AC, D_005794B0, D_00579310, D_00579314, D_00586A68;
extern "C" void func_001032B0(void) {
    char path[0x10];
    char obj[0x80];
    Result r;
    if (func_0028FCE8(D_00623D88, 0x40, "RaceEndLoadingAdvertiseFile") == 0) {
        D_005794B0 = D_005794AC;
        return;
    }
    s32 i = 0;
    s32 n = func_003FC600();
    u32 best = 0;
    if (n > 0) do {
        Result *rp = &r;
        s32 k = i;
        i++;
        func_003FC620(path, 0x10, k);
        func_0047DFB0(rp, func_00103248(obj, path));
        if (rp->err == 0) {
            if (best < r.size) best = r.size;
        }
    } while (i < n);
    D_00579310 = best;
    if (best != 0) {
        D_00579314 = func_004AE750(0x80, best);
        func_001034A8(D_00586A68);
    }
}
