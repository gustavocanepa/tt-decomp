struct Mutex;
extern "C" void func_004A4D68(Mutex *m);
extern "C" void func_004A4DD8(Mutex *m);

struct Guard {
    Mutex *m;
    Guard(Mutex *mutex) : m(mutex) { func_004A4D68(m); }
    ~Guard() { func_004A4DD8(m); }
};

struct Table;
extern "C" int func_005437A8(Table *t, int a, int b);

struct Obj {
    char pad[0x10];
    char table[0x110];
    char mutex[4];
};

extern "C" int func_0026D540(Obj *o, int a, int b)
{
    Table *t = (Table *)o->table;
    Guard g((Mutex *)o->mutex);
    return func_005437A8(t, a, b);
}
