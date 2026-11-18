/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(char *);
};

extern "C" void func_00421C58(float);
extern "C" void func_00470450(s32);
extern "C" void func_00470478(s32);
extern "C" void func_004780F8(void);

extern "C" void func_002D13F8(char *arg0) {
    char *s0 = *(char **)(*(char **)(*(char **)(*(char **)(arg0 + 0x6C) + 0x80) + 4) + 0x80);
    *(s32 *)(arg0 + 0xE3DC) = *(s32 *)(arg0 + 0xE3DC) + 1;
    VEntry *e = (VEntry *)(*(char **)(arg0 + 0x64) + 0x3F0);
    e->fn(arg0 + e->delta);
    func_00421C58(*(float *)(s0 + 0x50));
    func_00470450(-1);
    func_00470478(1);
    func_004780F8();
}
