typedef int s32;

struct Cb { void (*fn)(void); s32 arg; };
struct Self { char pad[0x18]; Cb cb; };
extern "C" void func_0047F6E8(Self *);
extern "C" void func_0042EDC8(void);

extern "C" void func_0042ED50(Self *self) {
    Cb t;
    func_0047F6E8(self);
    t.fn = func_0042EDC8;
    t.arg = 0;
    self->cb = t;
}
