struct Lock;
extern "C" void func_004A4D68(Lock *l);
extern "C" void func_004A4DD8(Lock *l);

struct Guard {
    Lock *l;
    Guard(Lock *lock) : l(lock) { func_004A4D68(l); }
    ~Guard() { func_004A4DD8(l); }
};

struct Obj {
    char pad[0x1C];
    char lock[4];
};

extern "C" void func_004F48A0(Obj *o, int a, int b, int c);

extern "C" void func_005776E8(Obj *o, int a, int b, int c)
{
    Guard g((Lock *)o->lock);
    func_004F48A0(o, a, b, c);
}
