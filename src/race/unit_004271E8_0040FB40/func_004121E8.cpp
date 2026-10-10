extern "C" int func_00412060(void *a, void *b);
/* throw(): reorg then fills the delay slot of `bne k, 1` from its target (bne, not bnel). */
extern "C" int func_00412108(void *a, void *b, int c) throw();

extern "C" int func_004121E8(void *a, void *b) {
    int k = func_00412060(a, b);
    if (k == 0)
        return 0;
    if (k == 1) {
        if (func_00412108(a, b, 0) != -1)
            return 0;
    }
    return 1;
}
