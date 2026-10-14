/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Owner { char pad[0x80]; void *p; };
struct Input { char pad[0x30]; float x; char pad2[8]; int c; };
extern "C" int func_0034BD58(void *, int, int, float, int, float);
extern "C" int func_003A90D8(Owner *o, Input *p, int a, int b) {
    return func_0034BD58(o->p, a, b, p->x, p->c, 500.0f);
}
