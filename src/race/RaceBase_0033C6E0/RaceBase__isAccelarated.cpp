typedef int s32;

struct Obj {
    char pad[0xDFC];
    s32 unkD38;
    char pad2[0xE14 - 0xDFC - 4];
    s32 unkD50;
};

extern "C" s32 RaceBase__isAccelarated(Obj *arg0) {
    if (arg0->unkD50 > 0) {
        return 1;
    }
    return arg0->unkD38;
}
