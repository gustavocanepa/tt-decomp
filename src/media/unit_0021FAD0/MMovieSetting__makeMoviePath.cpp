struct Str8 { char c[8]; };
extern char *D_0057ACD0;
extern const Str8 D_005E9390;
extern const char D_005E9398[];
extern const char D_005E93A8[];
extern char D_00765380[];
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" void func_0028FCE8(char *, int, const char *);
extern "C" int func_004A6500(char *, const char *, ...);

extern "C" char *MMovieSetting__makeMoviePath(void)
{
    char *path = D_0057ACD0;
    if (!path) {
        char buf[0x40];
        *(Str8 *)buf = D_005E9390;
        func_004F6678(buf + 8, 0, 0x38);
        func_0028FCE8(buf, 0x40, D_005E9398);
        func_004A6500(D_00765380, D_005E93A8, buf);
        D_0057ACD0 = D_00765380;
        path = D_00765380;
    }
    return path;
}
