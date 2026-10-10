typedef int s32;

struct Obj003EF2D8 {
    char pad[0x318];
    s32 unk2F8;
};

extern "C" s32 func_003499E0(struct Obj003EF2D8 *arg0)
{
    s32 *p = (s32 *)((char *)arg0 + 0x4B8);
    s32 matches = 0;
    s32 i;

    for (i = 0; i < 5; i++) {
        s32 v = *p;
        p = (s32 *)((char *)p + 0x1A0);
        if (v >= arg0->unk2F8) {
            matches = matches + 1;
        }
    }
    return matches;
}
