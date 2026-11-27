/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Decodes a motion vector pair: per component a motion code (func_004CF970), f-code residual bits
   when both are nonzero, reconstruction by func_004CFA10 (the vertical one halved around it for
   field vectors), then a dual-prime delta (func_004CF9C0) when ctx->dmv.on is set. */
extern "C" short func_004CF970(void);
extern "C" short func_004CF9C0(void);
extern "C" int func_004CC568(int n);
extern "C" void func_004CFA10(int *mv, int fcode, int code, int resid);
struct Dmv { int on; int x; int y; };
struct Ctx { int full; char pad4[0x10]; Dmv dmv; };
extern "C" void func_004CFA88(Ctx *ctx, int *mv, int fh, int fv) {
    int full = ctx->full;
    Dmv *d = &ctx->dmv;
    int code = func_004CF970();
    int resid;
    if (fh && code) resid = func_004CC568(fh);
    else resid = 0;
    func_004CFA10(mv, fh, code, resid);
    if (d->on) d->x = func_004CF9C0();
    code = func_004CF970();
    if (fv && code) resid = func_004CC568(fv);
    else resid = 0;
    if (full) mv[1] >>= 1;
    func_004CFA10(&mv[1], fv, code, resid);
    if (full) mv[1] <<= 1;
    if (d->on) d->y = func_004CF9C0();
}
