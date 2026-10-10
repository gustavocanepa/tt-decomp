typedef int s32;

struct Rep {
    s32 len;
    s32 res;
    s32 ref;
    s32 sel;
};

extern char D_005E4AA0[];

struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    s32 length() const { return rep()->len; }
    const char *c_str() const { if (length() == 0) {
            return D_005E4AA0;
        }
        dat[length()] = 0;
        return dat; }
};

extern "C" void func_00179D48(void *self, const char *s);

extern "C" void func_00179D00(void *self, const String *s) {
    func_00179D48(self, s->c_str());
}
