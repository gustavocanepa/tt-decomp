/* compiler: ee-gcc2.96-nosib */
typedef long long s64;

extern "C" void func_0040C0E0(void *self, s64 v);
extern "C" void func_0040BED0(void *self, s64 v);

extern "C" void func_0040BE90(void *self, s64 v) {
    if ((v >> 32) == 0x26) {
        func_0040C0E0(self, v);
    } else {
        func_0040BED0(self, v);
    }
}
