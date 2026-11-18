/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline int span(float step, float end, float start) {
    int n = (int)(end / step);
    n -= (int)(start / step);
    n -= 1;
    int result = 1;
    if (n > 0) result = n;
    return result;
}
extern "C" int func_0037C438(char *self) {
    char *sub = *(char **)(self + 0x24);
    return span(*(float *)(self + 0x14), *(float *)(self + 0x18), *(float *)(sub + 4));
}
