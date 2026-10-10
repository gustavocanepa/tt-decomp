/* Function-local static object, written out: guard, constructor, atexit destructor. */
extern int D_0057C4C0;
extern char D_00766D08[];

extern "C" void *func_002BCA00(void *obj, int a, int b);
extern "C" int func_004F4D20(void (*fn)(void));
extern "C" void func_002BFB20(void);

extern "C" void *func_002BD730(void)
{
    int *guard = &D_0057C4C0;
    if (*guard == 0) {
        func_002BCA00(D_00766D08, 0, 0);
        *guard = 1;
        func_004F4D20(func_002BFB20);
    }
    return D_00766D08;
}
