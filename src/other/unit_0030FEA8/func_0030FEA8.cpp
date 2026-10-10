typedef int s32;

struct S { char pad[0x69]; unsigned char flag; };

extern "C" s32 func_0030FEA8(S *arg0) {
    return arg0->flag != 0;
}
