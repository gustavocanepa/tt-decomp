extern "C" void func_004BFB90(int id, char *buf, int size);
extern "C" void func_004C2F58(int id, char *buf, int size);
extern "C" unsigned int func_004A8368(const char *s);
extern "C" int func_004A6500(char *buf, const char *fmt, ...);
extern "C" void func_004F8588(void *a, const char *s, void *b);
extern const char D_006138F8[];

extern "C" void func_004CDE70(int code, void *a, void *b)
{
    char major[0x20];
    char minor[0x20];
    char text[0x40];
    func_004BFB90((code >> 4) & 0xF, major, 0x20);
    func_004C2F58(code & 0xF, minor, 0x20);
    func_004A6500(text, D_006138F8, func_004A8368(major), major, minor);
    func_004F8588(a, text, b);
}
