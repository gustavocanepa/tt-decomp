/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Probes the entries around self->current in the order current, +1, -1, +2, -2, ... and stops at the first index one of the three handlers accepts; counts a miss when none does. */
typedef int s32;

struct Self {
    char pad0[0x674];
    s32 count;
    char pad678[0x688 - 0x678];
    s32 current;
    char pad68C[0x69C - 0x68C];
    s32 misses;
};

extern "C" s32 func_001996E0(Self *, s32) throw();
extern "C" s32 func_001997B0(Self *, s32) throw();
extern "C" s32 func_001999C0(Self *, s32);

extern "C" void func_001998E8(Self *self) {
    for (s32 i = 0; i < self->count * 2; i++) {
        s32 n = i + 1;
        s32 base = self->current;
        s32 index;
        if (i & 1) index = base + n / 2;
        else index = base - n / 2;
        if (index >= 0 && index < self->count) {
            if (func_001996E0(self, index) != 0) return;
            if (func_001997B0(self, index) != 0) return;
            if (func_001999C0(self, index) != 0) return;
        }
    }
    self->misses++;
}
