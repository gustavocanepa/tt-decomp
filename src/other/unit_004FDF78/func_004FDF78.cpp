/* compiler: ee-gcc2.9-991111 */
typedef int s32;

struct Ctx { char pad[0x24]; s32 m24, m28, m2C; };
extern "C" s32 func_004FD970(s32, Ctx *, s32, s32, s32, s32);

extern "C" s32 func_004FDF78(s32 a, s32 b, s32 c, Ctx *ctx) {
    return func_004FD970(0x80000008, ctx, 0x40, ctx->m24, ctx->m28, ctx->m2C) ? 0 : 0x800;
}
