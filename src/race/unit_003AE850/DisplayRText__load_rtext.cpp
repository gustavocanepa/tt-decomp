/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int D_00584420;
extern "C" unsigned int D_00586A68;
extern "C" char D_00584428[];
extern "C" int D_00584430;
extern "C" char D_005F67D8[], D_005F67F0[];
extern "C" void *func_00455930(unsigned int);
extern "C" int func_004A6500(char *, const char *, ...) throw();
extern "C" int func_0044CBD0(void *, char *, int, int);
extern "C" int func_0044CCF0(void *, char *);
extern "C" int DisplayRText__load_rtext(void) {
    int *p = &D_00584420;
    if (*p == 0) {
        char buf[128];
        func_004A6500(buf, D_005F67D8, func_00455930(D_00586A68));
        *p = func_0044CBD0(D_00584428, buf, 0, -1);
        D_00584430 = func_0044CCF0(D_00584428, D_005F67F0);
    }
}
