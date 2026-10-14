/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Val { int type,v; };
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; };
struct VEntry { short delta,index; int (*fn)(void *); };
struct Node { char pad[0x5C]; VEntry *vt; char pad60[0x10]; int state; };
struct Entry { int id; Val value; };
struct Vec { Entry *begin,*end,*cap; };
struct Obj { Node *node; char pad[0x164]; Str str; int x,id; Val val; Str other; Vec vec; Val val2; };
struct Args { int unused; void *ptr; int n,cap,pos; char pad[0x1C]; };
struct Frame { Args args; Val tmp; char pad38[8]; volatile void *dead; char pad44[0x1C]; Val tmp2; char pad68[8]; };
extern "C" void func_0043CB88(Obj *) throw();
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043E4E0(Val *, Val *, int, int, Args *, Obj *);
extern "C" void func_00443CD0(void *, Val *);
extern "C" void func_00447398(Node *, int);
extern "C" void func_00447D48(Str *);
extern "C" void func_004A45D0(void *) throw();
extern "C" char *strobe__toUpper(Rep *);
static inline int vcall(Node *n) { VEntry *e = n->vt+3; return e->fn((char *)n+e->delta); }
static inline void init(Args *a) { a->ptr=0; a->n=0; a->cap=0; a->pos=0; }
extern "C" void func_0043CCF0(Obj *self) {
    Frame f;
    if (self->node) {
        Val *value = &self->val2;
        if ((value->type ^ 13) == 0) {
            init(&f.args);
            Val *tmp = &f.tmp;
            func_0043E4E0(tmp,value,vcall(self->node),0,&f.args,self);
            func_0043D510(tmp);
            void *p = f.args.ptr;
            f.dead=p;
            if (p) func_004A45D0(p);
        }
        Str *str = &self->str;
        Str *other = &self->other;
        if (other != str) {
            Rep *r = (Rep *)(str->p-16);
            if (--r->ref == 0) func_004A45D0(r);
            char *d = other->p;
            r = (Rep *)(d-16);
            if (r->sel != 0) d = strobe__toUpper(r);
            else r->ref++;
            str->p = d;
        }
        func_00447D48(str);
        if (self->id >= 0) {
            self->node->state = 0;
            func_00447398(self->node,self->id);
        } else {
          value = &self->val;
          if ((value->type ^ 13) == 0) {
            init(&f.args);
            Val *tmp = &f.tmp2;
            func_0043E4E0(tmp,value,vcall(self->node),0,&f.args,self);
            func_0043D510(tmp);
            void *p = f.args.ptr;
            f.dead=p;
            if (p) func_004A45D0(p);
        } else {
            Vec *v = &self->vec;
            Entry *end = v->end;
            if (v->end - v->begin != 0) {
                self->node->state = 0;
                func_00447398(self->node,end[-1].id);
                func_00443CD0((char *)self+0x40,&end[-1].value);
                v->end--;
            }
        }
        }
        func_0043CB88(self);
    }
}
