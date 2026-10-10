#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002CF8D0();                                /* extern */
s32 func_002D6A80(void *);                      /* extern */
s32 func_002E9158(s32);                         /* extern */
s32 func_0036E618(void *);                      /* extern */
s32 RacePause__structor_0(void *);                      /* extern */
s32 func_00377730(void *, void *);              /* extern */
s32 func_00379AB0(void *);                      /* extern */
s32 func_0037AA40();                            /* extern */
s32 func_0037D418(void *);                      /* extern */
s32 func_0037DF48(void *, void *);              /* extern */
s32 func_003890D8(s32);                         /* extern */

extern char D_005D2098[];
struct func_0036EAC8_temp_s3 {
    char pad0[0x2C];
    s32 unk2C;
};

struct func_0036EAC8_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x8];
    void *unk70;
    char pad74[0xDB8];
    s32 unkE2C;
    char padE30[0xD698];
    void *unkE4C8;
    char padE4CC[0x4];
    void *unkE4D0;
};

s32 func_0036EAC8(void *arg0) {
    s32 temp_a0;
    s32 var_s0;
    s32 var_s1;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s1;
    struct func_0036EAC8_temp_s3 *temp_s3;
    void *temp_s4;

    var_s1 = 5;
    var_s0 = arg0 + 0x37DD0;
    func_0037AA40();
    ((struct func_0036EAC8_arg0 *)arg0)->unk64 = (s32)D_005D2098;
    func_002E9158(arg0 + 0x13C00);
    do {
        temp_a0 = var_s0;
        var_s0 += 8;
        var_s1 -= 1;
        func_003890D8(temp_a0);
    } while (var_s1 != -1);
    temp_s3 = arg0 + 0x37E00;
    temp_s0 = arg0 + 0x39178;
    temp_s1 = arg0 + 0x39280;
    RacePause__structor_0(temp_s3);
    func_002D6A80(arg0 + 0x37E38);
    func_00379AB0(temp_s0);
    temp_s4 = arg0 + 0x39294;
    func_0036E618(temp_s1);
    func_0037D418(temp_s4);
    ((struct func_0036EAC8_arg0 *)arg0)->unkE4C8 = temp_s0;
    ((struct func_0036EAC8_arg0 *)arg0)->unkE4D0 = temp_s1;
    ((struct func_0036EAC8_arg0 *)arg0)->unk70 = (void *) (arg0 + 0x13C00);
    if (func_002CF8D0() == 0) {
        temp_s0_2 = arg0 + 0xE418;
        temp_s3->unk2C = 1;
        func_00377730(temp_s3, temp_s0_2);
        func_0037DF48(temp_s4, temp_s0_2);
    }
    ((struct func_0036EAC8_arg0 *)arg0)->unkE2C = 0xD;
}
