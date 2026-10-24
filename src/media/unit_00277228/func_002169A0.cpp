/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { int off; char name[28]; };
struct Obj { char *base; int count; Entry *entries; };
extern "C" void func_002168A8(void *, void *) throw();
extern "C" int func_004A8268(const char *, const char *) throw();
extern "C" int func_002169A0(Obj *o, void *out, const char *name) {
    for (int i = 0; i < o->count; i++) {
        if (func_004A8268(o->entries[i].name, name) == 0) {
            func_002168A8(out, o->base + o->entries[i].off);
            return 1;
        }
    }
    return 0;
}
