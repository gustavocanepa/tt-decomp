typedef int s32;
typedef long long s64;

extern "C" char *func_0041D9C0(s64 arg0);
extern "C" void func_004F7A30(char *arg0, char *arg1);
extern "C" void func_004F7B74(char *arg0, const char *arg1);
extern char D_005FFFE0[];
extern char D_005FFFF0[];
extern char D_00600000[];

extern "C" char *GT4Model__CarModel__getModelFileName(s64 arg0, char *arg1, s32 arg2, s32 arg3)
{
    const char *s;
    char *t;

    if (arg2 != 0) {
        s = D_005FFFE0;
    } else if (arg3 != 0) {
        s = D_005FFFF0;
    } else {
        s = D_00600000;
    }
    func_004F7B74(arg1, s);
    t = func_0041D9C0(arg0);
    if (t == 0) {
        *arg1 = 0;
        return t;
    }
    func_004F7A30(arg1, t);
    return arg1;
}
