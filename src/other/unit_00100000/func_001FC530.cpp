typedef int s32;

struct Self { char pad[0x18]; s32 m18; };
extern "C" void func_001C7410(s32);

extern "C" void func_001FC530(Self *self) {
    while (self->m18 == 1 || self->m18 == 2) {
        func_001C7410(1);
    }
}
