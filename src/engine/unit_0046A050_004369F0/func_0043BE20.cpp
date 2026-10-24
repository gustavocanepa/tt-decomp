/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
typedef int s32;
typedef unsigned int u32;

struct Val { s32 type; s32 v; };
extern "C" void func_0043D510(Val *);

struct String3;
extern "C" void func_005685F0(String3 *str, u32 len, s32 force);
extern "C" String3 *func_005683E0(String3 *str, u32 pos, u32 n1, u32 n2, char c);

struct String3 {
    struct Rep {
        u32 len, res, ref, selfish;
        char *data() { return (char *)(this + 1); }
        char &operator[](u32 s) { return data()[s]; }
    };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    void alloc(u32 size, s32 save) { func_005685F0(this, size, save); }
    void unique() { if (rep()->ref > 1) alloc(length(), 1); }
    void selfish() { unique(); rep()->selfish = 1; }
    char &operator[](u32 pos) { selfish(); return (*rep())[pos]; }
    char *ibegin() const { return &(*rep())[0]; }
    char *begin() { selfish(); return &(*this)[0]; }
    char *end() { selfish(); return &(*this)[length()]; }
    String3 &replace(u32 pos, u32 n1, u32 n2, char c) { return *func_005683E0(this, pos, n1, n2, c); }
    char *erase(char *f, char *l) {
        u32 o = f - ibegin();
        replace(o, l - f, (u32)0, (char)0);
        selfish();
        return ibegin() + o;
    }
    void clear() { erase(begin(), end()); }
};

struct Elem12 { char p[12]; };
typedef vector<Elem12> Vec12;

struct Owner {
    char pad[0x5C];
    virtual ~Owner();
};
struct Parent { char pad[0x30]; s32 f30; };
struct Self;
extern "C" void func_00443CF0(void *p, s32 n);
extern "C" void func_0043C310(Self *);
extern "C" void *exception__structor_0(s32);
struct Owner2 : Owner {
    char more[0xAC - 0x60];
    static void *operator new(unsigned int n) { return exception__structor_0(n); }
    Owner2(Parent *p, s32 a, Self *s, s32 b, s32 c) __asm__("func_004468E0");
};

struct Self {
    Owner *own;
    Self *prev;
    Self *next;
    Parent *parent;
    char pad10[0x1C - 0x10];
    s32 f1C;
    s32 f20;
    char pad24[0x2C - 0x24];
    s32 f2C;
    char pad30[0x40 - 0x30];
    char sub[0x168 - 0x40];
    String3 str;
    s32 f16C;
    char pad170[4];
    Val v174;
    char pad17C[4];
    Vec12 vec;
    Val v18C;

    void reset(Owner *p) {
        if (prev == next) {
            delete own;
        } else {
            next->prev = prev;
            prev->next = next;
        }
        own = p;
        next = this;
        prev = this;
    }
};

extern "C" void func_0043BE20(Self *self, s32 flag)
{
    self->f1C = 0;
    self->f20 = 0;
    self->f2C = 0;
    self->f16C = 0;
    self->vec.erase(self->vec.begin(), self->vec.end());
    self->str.clear();
    func_0043D510(&self->v174);
    func_0043D510(&self->v18C);
    func_00443CF0(self->sub, 0);
    self->reset(0);
    Owner2 *p = new Owner2(self->parent, self->parent->f30, self, flag, 0);
    self->reset(p);
    func_0043C310(self);
}
