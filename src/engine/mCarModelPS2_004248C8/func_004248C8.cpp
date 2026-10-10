extern "C" void func_004248C0(int);

extern "C" void func_004248C8(int a0, int a1) {
    *(int *)(a0 + 124) = a1;
    func_004248C0(a0);
}
