typedef int s32;

extern "C" const char *func_0019BD98(s32 id);
extern "C" char *func_004F7B74(char *dst, const char *src);
extern "C" void func_0019B220(char *dst, s32 id, s32 n);

extern "C" void func_0019CCB8(s32 id, s32 kind, char *out) {
    func_004F7B74(out, func_0019BD98(id));
    out += 0xC;
    *out++ = kind;
    func_0019B220(out, id, 7);
}
