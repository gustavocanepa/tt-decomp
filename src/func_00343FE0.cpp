/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Result { s32 words[5]; };
struct Blk { s32 a, b; };
struct Pair { Blk block; s32 padding[6]; };
static inline void set(Blk *b, s32 a, s32 c) { b->a = a; b->b = c; }
extern "C" char *func_0041A550(void *car, s32 first);
extern "C" s32 func_0041A538(void *car, s32 first, s32 size);
extern "C" s32 func_0041AB80(void *car, s32 first);
extern "C" int func_004E5700(const char *, const char *, unsigned int);
extern "C" void *func_0041DB10(void *, void *, int);
extern "C" void func_0047DFB0(Result *, void *);
extern "C" void func_00343210(void *);
extern "C" void func_0042F140(void *, Blk *, Blk *, s32);

extern "C" void RaceCarModel__virtual_17(char *o, char *name0, char *name1, s32 mode) {
    char *car;
    char buf[2][0x40];
    union { Result info; Pair pair; } tmp;
    Blk cb;
    s32 i = 0;
    s32 j;
    for (; i < 2; i++) {
        char *p = buf[i];
        s32 first = (i == 0);
        char *name = first ? name0 : name1;
        if (name == 0) {
            return;
        }
        car = o + 0x18;
        if (func_004E5700(name, func_0041A550(car, first), 8) == 0) {
            *p = 0;
        } else {
            func_0041DB10(name, p, mode);
            func_0047DFB0(&tmp.info, p);
            func_0041A538(car, first, (tmp.info.words[2] + 0x3f) & ~0x3f);
        }
    }
    for (j = 0; j < 2; j++) {
        if (buf[j][0] != 0) {
            set(&tmp.pair.block, func_0041AB80(car, j == 0), 0);
            set(&cb, (s32)func_00343210, (s32)o);
            func_0042F140(buf[j], &tmp.pair.block, &cb, 1);
        }
    }
}
