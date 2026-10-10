#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_003FC340(s8 *);
void func_003FC9F0(s8 *);
void func_003FF488(void *);
void func_003FF870(void *);
void func_003FFF30(void *);
void func_004000B8(void *);
s32 func_00400D68(s8 *);
void func_00403468(void *);
extern char D_005D8CC8[];
void func_003FC8C8(s8 *arg0) {
    func_00400D68(arg0);
    *(s32 *)arg0 = (s32)D_005D8CC8;
    func_003FC340(arg0 + 0x1230);
    func_00403468(arg0 + 0x1238);
    func_003FF488(arg0 + 0x13AC);
    func_003FFF30(arg0 + 0x145C);
    func_004000B8(arg0 + 0x16B8);
    func_003FF870(arg0 + 0x170C);
    func_003FC9F0(arg0);
}
