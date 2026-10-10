extern const char D_005F7B48[], D_005F7B58[], D_005F7B68[], D_005F7B78[];

extern "C" const char *func_00393A98(int k) {
    switch (k) {
    case 3: return D_005F7B48;
    case 4: return D_005F7B58;
    case 5: case 10: case 11: return D_005F7B68;
    case 6: case 12: case 13: return D_005F7B78;
    default: return 0;
    }
}
