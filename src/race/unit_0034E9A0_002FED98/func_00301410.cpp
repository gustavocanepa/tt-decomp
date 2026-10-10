typedef int s32;
typedef unsigned char u8;
typedef short s16;

struct Sub {
    char pad[0x4D1];
    u8 unk4B1;
    char pad2[0x668 - 0x4D2];
    s16 unk64C;
};

extern "C" s32 func_00301410(void *arg0) {
    struct Sub *temp_a0 = (struct Sub *)((char *)arg0 + 0x104);
    s32 var_v0 = 1;

    if (!(temp_a0->unk4B1 & 0x10)) {
        return var_v0;
    }
    var_v0 = temp_a0->unk64C == 1;
    return var_v0;
}
