typedef int s32;

struct Server {
    s32 sema;
    char pad4[0x3C];
    s32 arg;
};

extern Server D_00773FC0;
extern "C" void func_004F4348(s32 sema);
extern "C" void func_004F45D8(Server *s, s32 cmd, s32 a, s32 b, s32 c);

extern "C" void func_004B5D28(s32 arg) {
    Server *s = &D_00773FC0;
    func_004F4348(s->sema);
    s->arg = arg;
    func_004F45D8(s, 9, 0, 0, 0);
}
