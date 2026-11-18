/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { short delta,index; void (*fn)(void *,int); };
struct Obj { int f0; E *vt; char pad8[16]; int state; };
extern "C" int func_001FC448(Obj *,Obj *);
extern "C" void func_001FC570(Obj *);
extern "C" int func_0021A4E8(Obj *) throw();
extern "C" void func_0021A590(Obj *,Obj *) throw();
static inline void call0(Obj *o,int off) {
    struct E0 { short delta,index; void (*fn)(void *); };
    E0 *e=(E0 *)((char *)o->vt+off);
    e->fn((char *)o+e->delta);
}
extern "C" void func_0021A700(Obj *self,Obj *other) {
    if (func_001FC448(self,other)) {
        switch(self->state) {
        case 0:
            func_001FC570(self);
            break;
        case 1:
            break;
        case 2:
            if (func_0021A4E8(self)) {
                call0(other,0x260);
                func_001FC570(self);
            }
            break;
        case 3:
            return;
        default:
            break;
        }
        E *e=(E *)((char *)other->vt+0x1E0);
        e->fn((char *)other+e->delta,0);
        call0(other,0x268);
        func_0021A590(self,other);
    }
}
