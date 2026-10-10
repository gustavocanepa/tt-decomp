#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct Range;
extern "C" Range D_00582E98;
extern "C" float func_002F4FF0(Range *r);

struct Obj {
    char pad[8];
    float value;
    char pad2[8];
    unsigned char locked;
};

extern "C" void func_002E4800(Obj *o, float v)
{
    if (!o->locked) {
        if (func_002F4FF0(&D_00582E98) < v)
            o->value = func_002F4FF0(&D_00582E98);
        else
            o->value = v;
    }
}
