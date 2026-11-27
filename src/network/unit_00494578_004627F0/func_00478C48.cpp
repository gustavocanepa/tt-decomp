/* compiler: ee-gcc2.96-no-strict-aliasing */
void func_00478C48(char *p) {
    int i = *(signed char *)(p + 0xebd);
    if (i >= 0) {
        char *dst = p + 0x14;
        do {
            int off = i * 20 + 0xc30;
            *(int *)(dst + off) = 0;
            i = *(signed char *)(p + off + 0xa);
        } while (i >= 0);
    }
}
