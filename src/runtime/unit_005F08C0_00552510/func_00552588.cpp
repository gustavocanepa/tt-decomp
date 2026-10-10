extern "C" void func_002E8088(void *self, int delta);

extern "C" void func_00552588(void *self, signed char *cur, signed char *next) {
    func_002E8088(self, *next - *cur);
    *cur = *next;
}
