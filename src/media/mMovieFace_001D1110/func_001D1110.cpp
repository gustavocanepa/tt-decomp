extern "C" void func_004F7B74(int, int);

extern "C" void func_001D1110(int a0, int a1, int a2) {
    *(int *)(a0 + 484) = a1;
    func_004F7B74((a0 + 420), a2);
}
