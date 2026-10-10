struct S;

extern "C" void *func_004C9C50(S *arg0);

extern "C" void *func_00211EC0(char *arg0) {
    return func_004C9C50((S *)(arg0 + 0x14));
}
