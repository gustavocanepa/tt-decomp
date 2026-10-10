extern void *D_00586EF4;
extern "C" void func_0045EC58(void *, void *);
extern "C" int func_0045DDB8(void *, char *, int, const char *, float);
extern "C" char *func_004F7B74(char *, const char *);

extern "C" void func_002D92A0(char *dst, const char *src, void *ctx, float scale)
{
    if (ctx) func_0045EC58(D_00586EF4, ctx);
    if (!func_0045DDB8(D_00586EF4, dst, 0x80, src, scale)) func_004F7B74(dst, src);
}
