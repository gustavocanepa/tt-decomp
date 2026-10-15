typedef unsigned char u8;
typedef int s32;

struct S { char pad[0xC]; u8 bC; u8 bD; u8 bE; u8 bF; };
extern "C" struct S D_00613940;

extern "C" s32 func_004D2788(void) {
    return (D_00613940.bC << 24) | (D_00613940.bD << 16) | (D_00613940.bE << 8) | D_00613940.bF;
}
