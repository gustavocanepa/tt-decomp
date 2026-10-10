struct Obj {
    char pad[0x14];
    unsigned char locked;
};

extern "C" void func_002E46E0(Obj *o, float v);
extern "C" void func_002E4800(Obj *o, float v);
extern "C" void func_002E4AE0(Obj *o, float v);

extern "C" void func_002E4588(Obj *o, int locked)
{
    if (!o->locked && locked) {
        func_002E46E0(o, 0.0f);
        func_002E4800(o, 0.0f);
        func_002E4AE0(o, 0.0f);
    }
    o->locked = locked;
}
