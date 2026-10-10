struct Ctx { int handle; char pad[0x3F4]; int state; };

extern "C" char D_00779E80[];
extern "C" void func_004F4348(int handle);
extern "C" void func_004F45D8(Ctx *ctx, int a, int b, void *buf, int size);

extern "C" void func_00574978(struct Ctx *ctx)
{
    func_004F4348(ctx->handle);
    ctx->state = 1;
    func_004F45D8(ctx, 3, 0, D_00779E80, 0x80);
}
