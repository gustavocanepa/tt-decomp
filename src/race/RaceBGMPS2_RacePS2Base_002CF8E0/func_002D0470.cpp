#include "types.h"
extern int D_00582A7C;
extern int D_00767138[16];
extern "C" void func_0046EE88(void *);
extern "C" int func_004F73A0(void);

extern "C" void func_002D0470(void) {
    int i, j, k, t;
    if (D_00582A7C == 0) {
        for (int n = 0; n < 16; n++) D_00767138[n] = (n + 1) / 2 - 4;
        for (j = 0; j < 20; j++) {
            for (i = 0; i < 16; i++) {
                int k2 = (int)((float)func_004F73A0() * 4.6566129e-10f * 16.0f);
                int t2 = D_00767138[i];
                D_00767138[i] = D_00767138[k2];
                D_00767138[k2] = t2;
            }
        }
        D_00582A7C = 1;
    }
    for (i = 0; i < 16; i++) {
        k = (int)((float)func_004F73A0() * 4.6566129e-10f * 16.0f);
        t = D_00767138[i];
        D_00767138[i] = D_00767138[k];
        D_00767138[k] = t;
    }
    func_0046EE88(D_00767138);
}
