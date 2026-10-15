typedef int s32;

struct func_004CDD88_a0;
extern "C" s32 func_004CDD88(struct func_004CDD88_a0 *a0);

extern "C" s32 D_00598424;

struct func_004BDAF8_a0 {
    char pad[0xC];
    struct func_004CDD88_a0 *child;
};

extern "C" s32 func_004BDAF8(struct func_004BDAF8_a0 *a0) {
    if (D_00598424 == 0) return 0;
    return func_004CDD88(a0->child);
}
