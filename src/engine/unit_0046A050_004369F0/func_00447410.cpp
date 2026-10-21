/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec {float x,y,z,w;};
struct Matrix {Vec v[4];};
struct Transform {float angle,a,b,c,x,y;};
struct ItemData {char p[0x2c];Transform transform;char q[0x18];};
struct Item:ItemData {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int test(Vec *,float);
};
struct Node {Node *next,*prev;Item *item;};
struct List {int allocator;Node *head;};
struct Owner {char pad[0xA4];List items;};
struct Iter {Node *n;};
static inline void init(Iter *i,Node *n) {i->n=n;}
static inline Node *end(List *l) {return l->head;}
static inline bool neq(Iter i,Node *n) {return i.n != n;}
static inline Item *get(Iter i) {return i.n->item;}
static inline void advance(Iter *i) {i->n = i->n->next;}
extern "C" void func_00445118(Transform *,Matrix *) throw();
extern "C" void func_00444E28(Matrix *,Vec *,Vec *) throw();
extern "C" int func_00447410(Owner *o,Vec *p,float f) {
    Iter it;
    List *l=&o->items;
    init(&it,l->head->next);
    Node *cur=it.n;
    for (;cur!=end(l);advance(&it),cur=it.n) {
        Vec point;
        Matrix m;
        func_00445118(&cur->item->transform,&m);
        func_00444E28(&m,p,&point);
        if (get(it)->test(&point,f)) return 1;
    }
    return 0;
}
