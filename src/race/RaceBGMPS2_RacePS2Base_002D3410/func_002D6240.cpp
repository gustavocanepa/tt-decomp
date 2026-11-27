/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct E { char pad4[4]; s32 f4; char pad[0x3C - 8]; };
struct T { E e[2]; s32 pad; };
struct G { char pad[0x134]; s32 f134; };
extern char D_00579534[];

extern "C" void func_00104D10(void *);
extern "C" s32 func_00475A08(void);
extern "C" void func_00477060(s32, s32, s32, s32, s32);

typedef s32 (*TestFn)(char *);

extern "C" void func_002D6240(char *arg0) {
    if (*(unsigned char *)(arg0 + 0xD008) != 0) {
        VEntry *e = (VEntry *)(*(char **)(arg0 + 0x64) + 0x460);
        if (((TestFn)e->fn)(arg0 + e->delta) != 0 && *(float *)(arg0 + 0xCFF0) != 0.0f) {
            char *base = D_00579534;
            char *q = base + (1 - *(s32 *)(base + 0x78)) * 0x3C;
            if (*(s32 *)(q + 4) == 1) {
                s32 s0 = *(s32 *)(base + 0x134);
                s32 b1 = s0 + 0x23000;
                s32 b2 = s0 + 0x46000;
                func_00104D10(q);
                func_00477060(s0, b1, b2, 0x280, 0xE0);
                *(unsigned char *)(arg0 + 0xD009) = func_00475A08();
                *(float *)(arg0 + 0xCFEC) = maxf(1.0f - 0x1.111110p-6f / *(float *)(arg0 + 0xCFF0), 0.0f);
            }
        }
    }
}
