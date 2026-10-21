extern "C" char D_005F0FD0[];
struct Rep { unsigned int len, res, ref; int selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](unsigned int i) { return data()[i]; }
};
struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    unsigned int length() const { return rep()->len; }
    void terminate() const { (*rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0) return D_005F0FD0;
        terminate();
        return rep()->data();
    }
};
struct VEntry { short delta; short index; int (*fn)(void *, const char *, unsigned int); };
struct Obj { int field0; VEntry *vtbl; };
extern "C" void func_0029F640(Obj *self, Str *s) {
    const char *text = s->c_str();
    VEntry *e = (VEntry *)((char *)self->vtbl + 0x1B8);
    e->fn((char *)self + e->delta, text, s->length());
}
