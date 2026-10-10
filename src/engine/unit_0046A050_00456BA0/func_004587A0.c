extern void func_00458778(void);
int func_004587A0(char *p) {
    if (*(int *)(p + 0xAA8) != 0) {
        func_00458778();
        return 0;
    }
    return 1;
}
