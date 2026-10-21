typedef int s32;

struct Code {
    char pad0[0x30];
    s32 base;
};

struct HContext {
    char pad0[0x24];
    Code *code;
    s32 pc;
};

extern "C" s32 func_0054E118(HContext *ctx) {
    Code *code = ctx->code;
    if (code != 0) {
        s32 base = code->base;
        s32 pc = ctx->pc;
        return (pc - base) >> 2;
    }
    return 0;
}
