struct Found {
    int a;
    int index;
    int c;
    int d;
};

extern "C" Found func_00424008(void *table, void *key, void *type);
extern "C" void func_002E2400(void *a, void *b, void *c);
extern char D_005F2B00[];

extern "C" void func_002DC5F8(void *key, void *table, void *a, void *c)
{
    Found f = func_00424008(table, key, D_005F2B00);
    if (f.index >= 0)
        func_002E2400(a, key, c);
}
