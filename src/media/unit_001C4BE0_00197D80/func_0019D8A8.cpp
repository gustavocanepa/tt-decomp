struct Obj { char pad[0x24]; char name[1]; };
extern "C" char *func_004F7B74(char *, const char *); /* strcpy */
extern "C" char *func_004F7A30(char *, const char *); /* strcat */
extern "C" int func_004A8368(const char *);          /* strlen */
extern const char D_005E6AB8[];
extern const char D_005E6BC0[];

extern "C" char *func_0019D8A8(Obj *o, char *buf)
{
    buf[0] = '/';
    func_004F7B74(buf + 1, o->name);
    func_004F7A30(buf + 1, D_005E6AB8);
    char *p = buf + func_004A8368(buf);
    for (int i = 5; i >= 0; i--) *p++ = D_005E6BC0[i];
    *p = 0;
    return buf;
}
