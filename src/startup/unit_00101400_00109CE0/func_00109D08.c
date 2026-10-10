/* A stack object: constructor (func_00108CA8), one call, destructor with in-charge flag 2. */
struct Obj { char data[0xB0]; };

void func_00108CA8(struct Obj *self);
void func_00108CE8(struct Obj *self, int flags);
int func_00108ED0(struct Obj *self, int a, int b);

int func_00109D08(int a, int b)
{
    struct Obj obj;
    int result;

    func_00108CA8(&obj);
    result = func_00108ED0(&obj, a, b);
    func_00108CE8(&obj, 2);
    return result;
}
