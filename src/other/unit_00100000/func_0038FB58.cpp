typedef int s32;

extern "C" void func_004F7B74(char *dst, const char *src);
extern "C" char *func_004F8588(char *dst, const char *src, s32 n);
extern "C" char D_005F7918[];

extern "C" void func_0038FB58(char *dst, const char *src, s32 size) {
    if (src == 0) {
        src = D_005F7918;
    }
    if (size < 0) {
        return func_004F7B74(dst, src);
    }
    func_004F8588(dst, src, size - 1);
    dst[size - 1] = 0;
}
