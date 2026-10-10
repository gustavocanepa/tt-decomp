struct Ctx { int handle; char pad[0x3C]; char path[0x40]; };
extern "C" Ctx D_00776D80;
extern "C" void func_004F4348(int handle);
extern "C" char *func_004F7B74(char *dst, const char *src); /* strcpy */
extern "C" void func_004F45D8(Ctx *ctx, int cmd, int a, void *buf, int size);

extern "C" void func_004BEDF0(const char *path)
{
    Ctx *ctx = &D_00776D80;
    func_004F4348(ctx->handle);
    func_004F7B74(ctx->path, path);
    func_004F45D8(ctx, 8, 0, 0, 0);
}
