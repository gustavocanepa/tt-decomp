/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct Node { Node *next; Obj *const owner; Node(Obj *p); };
struct Obj { char pad[0xb0]; Node node; };
extern Node *D_005DA3F8;
extern "C" Obj *func_00480280(Obj *) throw();
inline void *operator new(unsigned int, void *p) { return p; }
inline Node::Node(Obj *p) : next(D_005DA3F8), owner(p) { D_005DA3F8 = this; }
extern "C" int func_00480DB0(Obj *o) {
    func_00480280(o);
    new (&o->node) Node(o);
}
