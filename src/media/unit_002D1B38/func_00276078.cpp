/* compiler: ee-gcc2.96-nosib */
struct Obj { int m0; int m4; int m8; float mC; int m10; float m14; float m18; float m1C; char pad[0x10]; void *m30; };
extern "C" float func_00276008(Obj *);
extern "C" void func_00206008(void *, float, float, float, float);

extern "C" void func_00276078(Obj *o)
{
    if (o->m30) {
        float t = func_00276008(o);
        float a = o->m1C + o->m14 * t;
        float b = o->mC * t;
        if (o->m4) func_00206008(o->m30, a, 0.0f, b, o->m18);
        else func_00206008(o->m30, 0.0f, a, o->m18, b);
    }
}
