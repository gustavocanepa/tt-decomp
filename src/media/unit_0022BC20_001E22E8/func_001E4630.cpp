/* bastring.h basic_string::c_str() inline: "" when empty, else terminate() and data(). */
typedef unsigned int u32;

extern char D_005E9BB0[]; /* "" */

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };

struct String {
    char *dat;
    StringRep *rep() const { return (StringRep *)dat - 1; }
    u32 length() const { return rep()->len; }
    char *data() const { return dat; }
    void terminate() const { data()[length()] = 0; }
    const char *c_str() const {
        if (length() == 0)
            return D_005E9BB0;
        terminate();
        return data();
    }
};

extern void *D_00586EF4;
extern "C" int func_001E49C8(void *self);
extern "C" void func_0045F430(void *mgr, const char *name, int value);

extern "C" void func_001E4630(void *self, const String &name) {
    func_0045F430(D_00586EF4, name.c_str(), func_001E49C8(self));
}
