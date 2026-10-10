typedef int s32;

struct Obj {
    char pad[0x14];
    s32 unk14;
};

extern "C" void func_003696A0(struct Obj *arg0, void *arg1);

extern "C" void RaceNetRallyBattleInformation__virtual_12(void *arg0, struct Obj *arg1) {
    if (arg1->unk14 == 0) {
        func_003696A0(arg1, (char *)arg0 + 0x138);
    }
}
