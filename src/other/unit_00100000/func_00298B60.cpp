/* compiler: ee-gcc2.96-no-strict-aliasing */
/* mStringConst(const String &s): RefCounter base, vptr, then the string member copy-constructed
   (basic_string's inline grab(): clone when selfish, else ++ref). The base constructor returns
   `this` (gcc 2.x constructors do): declared void it changes the register homes here. */
typedef int s32;

extern "C" char *func_0050F0F0(void *rep);

struct Rep {
    s32 len;
    s32 res;
    s32 ref;
    s32 selfish;

    char *data() { return (char *)(this + 1); }
    char *clone() { return func_0050F0F0(this); }
    char *grab()
    {
        if (selfish)
            return clone();
        ++ref;
        return data();
    }
};

struct String {
    char *dat;
    Rep *rep() const { return ((Rep *)dat) - 1; }
};

static inline String *String_copy(String *self, const String &str)
{
    self->dat = str.rep()->grab();
    return self;
}

extern "C" void *func_002A7618(void *self);
extern "C" char D_005C3FD8[];

struct mStringConst {
    s32 count;
    void *vtbl;
    char pad8[8];
    String str;
};

extern "C" void func_00298B60(mStringConst *self, const String *s)
{
    func_002A7618(self);
    self->vtbl = D_005C3FD8;
    String_copy(&self->str, *s);
}
