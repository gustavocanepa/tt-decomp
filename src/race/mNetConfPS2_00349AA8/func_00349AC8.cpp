/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct S { char pad[0x138]; char name[0x20]; char buf[0x20]; s32 n; };
extern "C" void func_00370368(void *, char *);
extern "C" s32 func_004A8368(const char *) throw();
extern "C" char *func_004F7B74(char *, const char *);

extern "C" void func_00349AC8(S *s) {
    char *buf = s->buf;
    func_004F7B74(buf, s->name);
    s32 len = func_004A8368(buf);
    s->buf[len-1] = (s->n + 1) % 10 + 0x30;
    s->buf[len-2] = (s->n + 1) / 10 + 0x30;
    func_00370368(s, buf);
}
