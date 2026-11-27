/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Val { int type; int v; Val() : type(1) {} ~Val(); };
extern "C" void func_0043D510(Val *) throw();
inline Val::~Val() { func_0043D510(this); }
extern "C" void func_0043D6E8(Val *, const char *) throw();
struct Vec;
extern "C" void func_00447C80(Vec *, const Val &);
extern char D_00601CB8[]; /* "" */
struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
    const char *c_str() const { if (length() == 0) return D_00601CB8; terminate(); return data(); }
};
struct Obj { char pad[0x54]; String name; };
struct Node { Node *next; Node *prev; Obj *data; };
struct It {
 Node *n;
 It(Node *p): n(p) {}
 It(const It &p): n(p.n) {}
};
struct CIt {
 Node *n;
 CIt(Node *p): n(p) {}
 CIt(const It &p): n(p.n) {}
 Obj *get() const { return n->data; }
 CIt &operator++() { n=n->next; return *this; }
 bool operator!=(const CIt &o) const {return n!=o.n;}
};
struct List { int al; Node *node;
 CIt begin() const {return node->next;}
 CIt end() const {return node;}
};
struct Owner { char pad[0xA4]; List items; };
extern "C" void func_004477D0(const Owner *o, Vec *out) {
    for (CIt it = o->items.begin(); it != o->items.end(); ++it) {
        if (it.get()->name.length() != 0) {
            Val t;
            func_0043D6E8(&t, it.get()->name.c_str());
            func_00447C80(out, t);
        }
    }
}
