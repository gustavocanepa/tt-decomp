typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" u32 func_004C9B10(void *self, int index);

extern "C" u64 func_004C9B68(void *self, int index) {
    u64 lo = func_004C9B10(self, index * 2);
    u64 hi = func_004C9B10(self, index * 2 + 1);
    return lo | (hi << 32);
}
