/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Result { s32 words[5]; };
struct Blk { s32 a,b; };
struct Pair { Blk block; s32 padding[6]; };
static inline void set(Blk *b, s32 a, s32 c) { b->a = a; b->b = c; }
extern "C" char *func_0041A5D8(void *);
extern "C" int func_004E5700(const char *, const char *, unsigned int);
extern "C" void *func_0041DA70(void *, void *, int);
extern "C" Result func_0047DFB0(void *);
extern "C" s32 func_0041E0A8(void *, s32);
extern "C" s32 func_0041A5C0(void *, s32);
extern "C" void func_00343230(void *, s32);
extern "C" void func_0042F140(void *, Blk *, Blk *, s32);
extern "C" void func_00344178(char *o, char *name, s32 mode) {
    char *car = o + 0x18;
    char buf[64];
    if (func_004E5700(name, func_0041A5D8(car), 8)) {
        func_0041DA70(name, buf, *(void **)(o + 0x14) ? 1 : mode);
        Result info = func_0047DFB0(buf);
        Pair pair;
        Blk cb;
        s32 size = (info.words[2] + 0x3f) & ~0x3f;
        void *p = *(void **)(o + 0x14);
        s32 data;
        if (p) data = func_0041E0A8(p, size);
        else data = func_0041A5C0(car, size);
        *(s32 *)(car + 0xA0) = 0;
        set(&pair.block, data, 0);
        set(&cb, (s32)func_00343230, (s32)o);
        func_0042F140(buf, &pair.block, &cb, 1);
    }
}
