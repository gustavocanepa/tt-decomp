extern "C" int func_00393A08(void *self);

extern "C" int func_00399458(void *self, int mode) {
    int n = func_00393A08(self);
    if (n == 0)
        return 0;
    if (mode == 0) {
        if (n < 3)
            return 0;
        return 1;
    }
    if (mode == 1)
        return n < 4;
    return 0;
}
