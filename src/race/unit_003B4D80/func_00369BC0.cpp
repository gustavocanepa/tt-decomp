typedef int s32;
typedef long s64;

struct Ent { short delta; short pad; void (*fn)(char *, char *); };

extern "C" s64 func_0040CFF0(char *arg0);
extern "C" char *GT4Model__CarModel__getModelFileName(s64 arg0, char *arg1, s32 arg2, s32 arg3);

extern "C" void func_00369BC0(char *arg0, s32 arg1, s32 arg2) {
    char buf[0x50];
    *(s32 *)(arg0 + 0x484C) = arg2;
    GT4Model__CarModel__getModelFileName(func_0040CFF0(arg0 + 0xFD8), buf, arg1 == 2, arg2);
    char *a = *(char **)(arg0 + 0x4840);
    Ent *e = (Ent *)(*(char **)(a + 8) + 0x68);
    e->fn(a + e->delta, buf);
}
