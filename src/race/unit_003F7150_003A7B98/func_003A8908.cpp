extern "C" int func_002ECC60(void *self, int *used, int *total);

extern "C" int func_003A8908(void *self, int *used, int *total) {
    int r = 0;
    *total = 0;
    *used = 0;
    if (func_002ECC60(self, used, total)) {
        if (*total > 0)
            r = (float)*used / (float)*total > 0.7f;
    }
    return r;
}
