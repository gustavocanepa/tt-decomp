/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" char *AutomobileControlRecord__Manager__load(void *, char *, int);
extern "C" void func_0036DBE8(char *self, char *replay) {
    *(int *)(self + 0xF1D8) = 1;
    char *ghost = self + 0xE90C;
    AutomobileControlRecord__Manager__load(self + 0xE9E0, replay + 0x1A24, 0);
    *(int *)(ghost + 0x1D0) = 0;
}
