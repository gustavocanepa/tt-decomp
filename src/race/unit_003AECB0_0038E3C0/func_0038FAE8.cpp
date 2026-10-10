extern const char D_005F7900[];
extern const char D_005F7908[];
extern const char D_005F7918[];
extern "C" int func_004A6500(char *buf, const char *fmt, ...);
extern "C" const char *DisplayRText__getRTextStr(const char *key);

extern "C" const char *func_0038FAE8(int id)
{
    const char *s;
    if (id < 0 || id == 0xFF)
        return D_005F7900;
    s = D_005F7900;
    if ((unsigned int)id < 13) {
        char key[32];
        func_004A6500(key, D_005F7908, id);
        s = DisplayRText__getRTextStr(key);
        if (s == 0)
            s = D_005F7918;
    }
    return s;
}
