struct Obj;
extern "C" long long func_00412018(Obj *);
extern "C" long long func_00412028(Obj *, int) throw();
extern "C" int func_00412040(Obj *, int);

extern "C" long long func_00412108(Obj *o, long long key, int arg2) {
    long long r;
    if (key == 0x1F) return 0xF800LL << 21;
    int n = (int)func_00412018(o);
    r = -1;
    int i;
    for (i = 0; i < n; i++) {
        r = func_00412028(o, i);
        long long h = (r & (-1LL << 32)) >> 32;
        int e = func_00412040(o, i);
        if (key == h && arg2 == e) break;
        r = -1;
        if ((unsigned long long)key < (unsigned long long)h) break;
    }
    return r;
}
