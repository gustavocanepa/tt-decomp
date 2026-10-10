typedef int s32;

struct Item { char pad[0x74]; };
extern "C" void func_003CF138(Item *);

extern "C" void func_003D0688(Item *items) {
    s32 i;
    for (i = 3; i >= 0; i--) {
        func_003CF138(items++);
    }
}
