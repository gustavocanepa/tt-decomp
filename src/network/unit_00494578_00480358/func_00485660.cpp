/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int mode, next; char pad[0x414]; };
struct Obj { char pad[0x24]; State state[2]; int index; int pad85c; int busy; };
struct Packet { char status; char pad[3]; short first, last; };
extern "C" void func_004825C8(void *, void *, void *, int) throw();
extern "C" void func_00482820(void *) throw();
extern "C" void *func_004834E8(void *) throw();
extern "C" void func_00483628(void *, void *, void *, int) throw();
extern "C" void func_00486CF0(void *);
extern "C" int func_00485660(Obj *self) {
    char buf[512];
    if (self->busy) return 1;
    State *s = &self->state[1-self->index];
    switch (s->mode) {
    case 0: return 0;
    case 1:
        s->next = 2;
        func_00482820(self);
        s->mode = 2;
        break;
    case 2: {
        Packet *p = (Packet *)func_004834E8(self);
        func_004825C8(self, p, buf, 256);
        func_00486CF0(buf);
        func_00483628(self, p, buf, p->last - p->first);
        p->status = 5;
        break;
    }
    }
    return 1;
}
