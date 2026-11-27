/* compiler: ee-gcc2.96-no-strict-aliasing */
extern unsigned int D_00586A68;
extern char D_0076A098[3];
extern "C" char *func_00455930(unsigned int);
extern "C" int func_004A8268(const char *, const char *) throw();
extern "C" char *func_0042D750() {
    char *s = func_00455930(D_00586A68);
    if (func_004A8268(s, "DB") == 0) s = (char *)"UK";
    int a = s[0];
    if (((unsigned char *)0x616779)[a] & 1) a += 32;
    D_0076A098[0] = a;
    int b = s[1];
    D_0076A098[2] = 0;
    if (((unsigned char *)0x616779)[b] & 1) b += 32;
    D_0076A098[1] = b;
    return D_0076A098;
}
