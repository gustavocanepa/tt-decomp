/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef s32 (*Fn)(char *);
struct Entry { s16 delta; s16 index; Fn fn; };
struct Obj { char pad[0x4c]; Entry *vt; };
struct Holder { char pad[0x10]; Obj *obj; };
extern "C" void func_00151AE8(void *) throw();
extern "C" void func_00151A90(void *, int) throw();
extern "C" void func_0029EA18(void *, int);
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" s32 func_00520A30(char *);
extern "C" s32 func_005206C0(char *);
extern "C" Obj *GT4MC__FileGT4GameData__loadInstance(Fn, Fn, int, char *, Fn, Obj *);
static inline s32 invoke(Obj *self) {
    Entry *e = (Entry *)((char *)self->vt + 0xb8);
    return e->fn((char *)self + e->delta);
}
extern "C" void MMemoryCardFile__get_portrait(s32 *arg0) {
    s32 buf[4];
    Obj *object;
    s32 newVal, oldVal;
    func_00151AE8(buf);
    Obj *base = ((Holder *)buf[0])->obj;
    object = 0;
    if (base) {
        Entry *e = base->vt;
        object = GT4MC__FileGT4GameData__loadInstance(e->fn, func_00520A30, 0, (char *)base + e->delta, func_005206C0, base);
    }
    func_00151A90(buf, 2);
    s32 flag;
    if (object == 0 || invoke(object) == 0) flag = 0;
    else flag = 1;
    func_0029EA18(buf, flag);
    if (arg0 != buf) {
        newVal = buf[0];
        if (newVal) func_002C0FE8(newVal);
        oldVal = *arg0;
        if (oldVal) func_002C1050(oldVal);
        *arg0 = newVal;
    }
    func_0029CEF0(buf, 2);
}
