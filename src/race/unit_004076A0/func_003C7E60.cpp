/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;

struct Self {
    char pad0[8];
    char a[0x4C];
    char b[0x4C];
};

extern "C" int func_0040DE88(void *);
extern "C" int func_0040DEC8(void *);
extern "C" int func_00406A50(void *, int, int);

static inline void clear_word(u32 *word, u32 mask) { *word &= ~mask; }

static inline void remove_bit(char *base, int i) {
    u32 *w = (u32 *)(base + (u32)((i >> 5) * 4 + 0x40));
    u32 m = 1 << (i & 31);
    u32 v = *w;
    if (__builtin_expect((int)(v & m), 0)) {
        clear_word(w, m);
        int *cnt = (int *)(base + 0x3C);
        *cnt = *cnt - 1;
    }
}

extern "C" void func_003C7E60(Self *self, void *p, void *q) {
    if (q != 0) {
        int i = 0;
        int ea = func_0040DE88(p);
        int eb = func_0040DEC8(p);
        for (; i < 13; i++) {
            if (i != ea) {
                int r = func_00406A50(q, 0x19, i);
                if (r == 0) remove_bit(self->a, i);
            }
        }
        for (i = 0; i < 13; i++) {
            if (i != eb) {
                int r = func_00406A50(q, 0x1A, i);
                if (r == 0) remove_bit(self->b, i);
            }
        }
    }
}
