struct L { int n; int items[1]; };
struct F { char pad[8]; float w; };
extern "C" void func_0041F0E0(int a, void *b, int c, int d, int e, int f);

extern "C" void func_0041F598(L *arg0, void *arg1, int arg2, int arg3, int arg4, int arg5) {
    int i = 0;
    if (arg0->n > 0) {
        int *p = arg0->items;
        do {
            int v = *p;
            p++;
            func_0041F0E0(v, arg1, arg2, arg3, arg4, arg5);
            i++;
        } while (i < arg0->n);
    }
    if (arg0->n != 0) {
        F *f = (F *)arg1;
        f->w = (f->w - 1.0f) / (float)arg0->n + 1.0f;
    }
}
