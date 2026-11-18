#include "types.h"
extern "C" void *func_004F6678(void *, int, unsigned);
static inline u8 rol(u8 x, int n) { return (x << n) | (x >> (8 - n)); }
extern "C" void func_00413F08(u8 *key, u8 *tbl, u8 *uk1, u8 *uk2, unsigned rounds) {
    u8 ka[9];
    u8 kb[9];
    unsigned i;
#define E(x) (((u8 *)((x) + (int)tbl))[0x100])
    int ki;
    func_004F6678(key, 0, 0xD9);
    func_004F6678(ka, 0, 9);
    func_004F6678(kb, 0, 9);
    if (rounds >= 14) rounds = 13;
    key[0] = rounds;
    ki = 1;
    for (unsigned j = 0; j < 8; j++) {
        u8 a = rol(uk1[j], 5);
        u8 b = uk2[j];
        ka[j] = a;
        key[ki++] = b;
        ka[8] = a ^ ka[8];
        kb[j] = b;
        kb[8] = b ^ kb[8];
    }
    unsigned j;
    for (i = 1; i <= rounds; i++) {
        for (j = 0; j < 9; j++) {
            ka[j] = rol(ka[j], 6);
            kb[j] = rol(kb[j], 6);
        }
        for (j = 0; j < 8; j++)
            key[ki++] = E(E((u8)(18 * i + j + 1))) + ka[(j + 2 * i - 1) % 9];
        for (j = 0; j < 8; j++)
            key[ki++] = E(E((u8)(18 * i + j + 10))) + kb[(j + 2 * i) % 9];
    }
    func_004F6678(ka, 0, 9);
    func_004F6678(kb, 0, 9);
}
