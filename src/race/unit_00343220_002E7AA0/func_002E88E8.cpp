/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void AutomobileControlRecord__Recorder__finish(void *) throw();
extern "C" void func_002E88B0(void *, int) throw();
struct Block { char data[0x10000]; };
struct Obj { int kind, state; char pad[0x58]; char *data; int index, count; };
extern "C" int func_002E88E8(Obj *o) {
    if ((o->state ^ 1) == 0) {
        AutomobileControlRecord__Recorder__finish((char *)o + 8);
        if (o->kind == 0) {
            int n = o->count;
            ++n;
            if (n == 3) {
                for (int i = 0; i < 2; i++) {
                    ((Block *)o->data)[i] = ((Block *)o->data)[i + 1];
                }
                n = 3;
            }
            o->count = n;
        }
        int n = o->index + 1;
        if (n == 3) n = 2;
        o->index = n;
        func_002E88B0(o, n);
    }
}
