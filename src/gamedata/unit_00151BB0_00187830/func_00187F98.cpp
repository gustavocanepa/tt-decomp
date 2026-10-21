extern "C" void func_001C7410(int);

extern "C" int func_00187F98(char *arg0, int arg1) {
    int i = 0;

    if (arg1 > 0) {
        int *p = (int *)(arg0 + 0xC0);
        do {
            if ((*p ^ 2) != 0) {
                return 0;
            }
            func_001C7410(1);
            i++;
        } while (i < arg1);
    }
    return 1;
}
