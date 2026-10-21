/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Command {
    int id;
    int x;
    int y;
    int value;
};

struct Obj {
    char pad0[0x18];
    int value;
    char pad1[0x24C - 0x1C];
    Command command;
};

extern "C" {
extern char D_005A0B88[];
void func_004A4930(void *);
void func_004A4970(void *);

void func_004C6A78(Obj *o, int id, float x, float y)
{
    func_004A4930(D_005A0B88);
    Command *c = &o->command;
    c->id = id;
    c->x = (int)(x * 16383.0f);
    c->y = (int)(y * 16383.0f);
    c->value = o->value;
    func_004A4970(D_005A0B88);
}
}
