/* compiler: ee-gcc2.9-991111 */
struct Obj { char pad[0x20]; void *value; };
struct Obj *func_004D9E48(void);
extern char D_006235F0[];
void *func_004D4DD8(void) {
    struct Obj *o = func_004D9E48();
    if (o == 0) return D_006235F0;
    return o->value;
}
