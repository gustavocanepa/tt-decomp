/* compiler: ee-gcc2.9-991111 */
extern int D_00617C58[12];

int func_005058A8(int (*fn)(int)) {
    unsigned int i;
    int r;
    for (i = 0; i < 12; i++) {
        r = fn(D_00617C58[i]);
        if (r < 0)
            return r;
    }
    return 0;
}
