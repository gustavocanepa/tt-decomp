/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0039C748(int base, int team, int member) {
    if (member < 0) {
        int *p = (int *)(team * 0x10 + base + 0x9218);
        char *q = (char *)(team * 0x8d0 + base + 0x3e4);
        for (int i = 0; i < 4; i++, p++, q += 0x178) {
            int flag = 0;
            if (*(int *)(q+0x170) || *(int *)(q+0x174)) flag = 1;
            if (!flag && !*p) return 0;
        }
        return 1;
    }
    return *(int *)(((team * 4 + member) * 4) + base + 0x9218);
}
