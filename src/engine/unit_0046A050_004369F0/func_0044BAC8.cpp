/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct Obj {
    char pad[0x5C];
    virtual ~Obj();
};

struct LinkedPtr {
    Obj *p;
    LinkedPtr *prev;
    LinkedPtr *next;
    void release() {
        Obj *obj = p;
        if (prev == next) {
            if (obj) delete obj;
        } else {
            next->prev = prev;
            prev->next = next;
        }
    }
    void reset(Obj *q) {
        release();
        p = q;
        next = this;
        prev = this;
    }
};

struct Base {
    char pad0[0x5C];
    virtual ~Base();
    virtual void f1(s32 a, s32 b);
};

struct Self : Base {
    s32 st;
    s32 p64;
    s32 p68;
    char pad6C[4];
    s32 p70;
    LinkedPtr second;
    char pad80[0x18];
    s32 g98;
};

struct Ids {
    s16 v[4];
    u8 flag;
};

extern "C" Ids *func_0044BAA0(Self *) throw();
extern "C" void func_0044B890(Self *self, s32 arg1) throw();

extern "C" s32 func_0044BAC8(Self *self, s32 a, s32 b, s32 c) {
    if (self->g98 != 0) return 0;
    {
        s32 t = func_0044BAA0(self)->flag != 0;
        s32 r = 0;
        s32 s;
        s32 old;
        if (t || (self->p68 == 0 && b != 0)) self->p70 = a;
        s = self->st;
        old = s;
        if (b == 0 && a != 0 && (self->p64 == 0 || (self->p68 != 0 && self->p70 == 0))) {
            s = 1; r = 1;
        } else if (b == 0 && a == 0 && self->p64 != 0) {
            s = 0; r = 2;
        } else if (b != 0 && self->p68 == 0 && a != 0) {
            s = 2; r = 4;
        } else if (b == 0 && self->p68 != 0) {
            if (a != 0) {
                if (self->p70 != 0) { s = 1; r = 8; }
            } else if (self->p70 != 0) { s = 0; r = 0x40; }
        } else if (b != 0 && self->p68 != 0) {
            if (self->p70 != 0 && a != 0 && self->p64 == 0) {
                r = t ? 0x80 : 0x20; s = 1;
            } else if ((t || self->p70 != 0) && a == 0 && self->p64 != 0) {
                r = t ? 0x100 : 0x10; s = 0;
            }
        }
        self->p64 = a;
        self->p68 = b;
        if (old == s) return r;
        {
            self->st = s;
            Ids *ids = func_0044BAA0(self);
            if (ids->v[old] != ids->v[s]) {
                self->second.reset(0);
                func_0044B890(self, c);
                self->f1(c, 0);
            }
            }
        return r;
    }
}
