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

extern "C" void *func_002C0EB0(void *self);
extern "C" char D_005C5EF0[];

struct mStringConst {
    s32 count;
    void *vtbl;
    String str;
};

extern "C" void func_002BA7D0(mStringConst *self, const String *s)
{
    func_002C0EB0(self);
    self->vtbl = D_005C5EF0;
    String_copy(&self->str, *s);
}
