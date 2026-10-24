/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int words[0x3B8 / 4]; };
struct Ctx { int handle; char pad[0x3C]; Block block; int state; };
extern "C" char D_00779E80[];
extern "C" void func_004F4348(int);
extern "C" int func_005038D8();
extern "C" int func_004F45D8(Ctx *, int, int, void *, int);
extern "C" void func_005749C8(Ctx *ctx, Block *src) {
    func_004F4348(ctx->handle);
    int enabled = func_005038D8();
    ctx->block = *src;
    if (enabled) __asm__ volatile("ei");
    ctx->state = 1;
    func_004F45D8(ctx, 4, 1, D_00779E80, 0x80);
}
