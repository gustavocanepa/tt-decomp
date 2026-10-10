#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern s32 D_0059840C;
extern s32 D_00598414;

s32 func_004BAE78();                            /* extern */
s32 func_004BDC78(void *);                      /* extern */
s32 func_004CC438();                            /* extern */
s32 func_004CC830();                            /* extern */
s32 func_004CDB30(s32);                         /* extern */
s32 func_004FA740();                            /* extern */
s32 func_004FA750(s32);                         /* extern */
s32 func_004FA840(s32);                         /* extern */
s32 func_004FA860(s32);                         /* extern */

struct func_004BD848_arg0 {
    char pad0[0x8];
    void *unk8;
    s32 unkC;
};
struct func_004BD848_temp_s1 {
    char pad0[0x38];
    s32 unk38;
    char pad3C[0x4];
    s32 unk40;
};

void func_004BD848(struct func_004BD848_arg0 *arg0) {
    s32 temp_a0;
    struct func_004BD848_temp_s1 *temp_s1;

    temp_s1 = arg0->unk8;
    func_004CC438();
    func_004BAE78();
    func_004CDB30(arg0->unkC);
    func_004BDC78(temp_s1);
    func_004FA840(D_0059840C);
    func_004CC830();
    func_004CDB30(arg0->unkC);
    func_004CC438();
    func_004BAE78();
    func_004FA860(temp_s1->unk38);
    temp_s1->unk40 = 0;
    func_004FA840(temp_s1->unk38);
    temp_a0 = D_00598414;
    if (temp_a0 != -1) {
        func_004FA750(temp_a0);
    }
loop_2:
    func_004FA740();
    goto loop_2;
}
