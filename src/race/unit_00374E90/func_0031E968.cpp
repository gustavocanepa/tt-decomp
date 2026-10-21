typedef int s32;
typedef float f32;

struct S {
    s32 a;
    f32 f;
};

extern "C" s32 func_0031E930(struct S *s, f32 x) throw();
extern "C" void func_0031E958(struct S *arg0, s32 arg1, f32 fparg0) throw();

extern "C" s32 func_0031E968(struct S *arg0, char *arg1, s32 arg2)
{
    s32 i;
    f32 x;
    s32 r;

    arg1 = arg1 + arg2 * 0x28;
    x = *(f32 *)(arg1 + 0x24);
    i = 0;
    do {
        r = func_0031E930((struct S *)((s32)arg0 + i * 8), x);
        if (r != 0) {
        s32 k = 0xF;
        if (i < k) {
            do {
                arg0[k] = arg0[k-1];
                k--;
            } while (i < k);
        }
        func_0031E958((struct S *)((s32)arg0 + i * 8), arg2, x);
        return 1;
    }
        i++;
    } while (i < 0x10);
    return r;
}
