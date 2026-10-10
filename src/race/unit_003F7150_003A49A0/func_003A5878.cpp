typedef int s32;
typedef unsigned char u8;

struct Elem {
    char pad[0x1ED];
    u8 code;
};

extern u8 D_00582DF8[];

extern "C" s32 func_003A5878(char *arg0, s32 arg1) {
    struct Elem *e = (struct Elem *)(arg0 + arg1 * 0xF4);
    return D_00582DF8[e->code] != 0;
}
