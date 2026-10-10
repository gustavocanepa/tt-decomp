typedef int s32;

extern s32 D_00583D88[];

extern "C" s32 func_00323910(s32 x) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if (D_00583D88[i] == x) return i;
    }
    return -1;
}
