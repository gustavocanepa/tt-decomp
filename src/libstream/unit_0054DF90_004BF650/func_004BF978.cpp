typedef int s32;

extern "C" {
extern char D_00776EC0[];
extern char D_00777200[];
void func_004A4D68(s32 a0);                         /* extern */
void func_004A4DD8(s32 a0);                         /* extern */
}

/* 40-byte block copied as 4-byte-aligned data (ldl/ldr pairs). */
struct Blk40 {
    char b[36];
    s32 w;
};

extern "C" void func_004BF978(s32 arg0, char *arg1) {
    char *s0 = D_00777200 + arg0 * 0x6C;
    func_004A4D68((s32)D_00776EC0);
    *(s32 *)(s0 + 0x40) = 2;
    *(Blk40 *)(s0 + 0x44) = *(Blk40 *)arg1;
    func_004A4DD8((s32)D_00776EC0);
}
