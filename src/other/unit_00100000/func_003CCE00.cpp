typedef int s32;

struct Item { char pad[0x154]; };
extern "C" void func_003CC050(Item *);

extern "C" void func_003CCE00(Item *items) {
    s32 i;
    for (i = 6; i >= 0; i--) {
        func_003CC050(items++);
    }
}
