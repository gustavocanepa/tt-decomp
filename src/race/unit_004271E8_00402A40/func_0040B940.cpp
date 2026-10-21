typedef int s32;

struct func_0040B940_a0 {
    char pad[0x138];
    s32 items[1];
};

extern "C" s32 SPEC_DATABASE__DatabaseTable__getRow(s32, s32, s32);

extern "C" s32 func_0040B940(struct func_0040B940_a0 *self, s32 arg1, s32 idx, s32 arg3) {
    s32 p = self->items[idx];
    s32 result = 0;
    if (p == 0) {
        return result;
    }
    return SPEC_DATABASE__DatabaseTable__getRow(p, arg1, arg3);
}
