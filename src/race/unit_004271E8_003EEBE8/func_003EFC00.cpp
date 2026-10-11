extern "C" void ModelSet2__render(void *a, void *b);
extern "C" void func_004209C8(void *a, int id, void *b);

extern "C" void func_003EFC00(void *a, void *b, const unsigned short *list) {
    if (list) {
        int n = *list++;
        for (int i = 0; i < n; i++)
            func_004209C8(a, *list++, b);
    } else {
        ModelSet2__render(a, b);
    }
}
