extern void func_00456D68(void);
int func_00457C38(char *p) {
    if (*(int *)(p + 0x874) != 0) {
        func_00456D68();
        return 0;
    }
    return 1;
}
