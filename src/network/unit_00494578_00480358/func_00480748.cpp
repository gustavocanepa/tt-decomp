/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block {
    int a;
    int b;
    int value;
    int c;
    int d;
};

struct Res {
    Block info;
    int extra[3];
};

struct Item {
    char pad[0x48];
    int lock;
    char pad4c[0x28];
    int state;
    char pad78[0xC];
    Block block;
};

struct Conn {
    int handle;
    int a;
    int b;
    void *p;
};

struct Param {
    int state;
    Item *item;
    int f8;
    Conn *conn;
};

struct Base {
    char pad[0xA4];
};

class Owner : public Base {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual Res lookup(Item *item);
    virtual int func_005AE360(int ctx, int x, int y);
};

extern char D_0076FCC0[], D_0076FCE0[];
extern "C" int func_004816D0(int lock);
extern "C" void func_004816F0(int lock);
extern "C" void func_0047D640(Owner *, Param *);
extern "C" int func_004BEB20(int, int, int, int);
extern "C" void *func_004AD988(void *, int);

static inline void attach(Owner *self, Param *prm, int r) {
    if (r == 0) {
        prm->state = 9;
    } else {
        func_0047D640(self, prm);
        Conn *c = (Conn *)func_004AD988(D_0076FCC0, 0);
        c->handle = r;
        c->a = 0;
        c->b = 0;
        c->p = func_004AD988(D_0076FCE0, 0);
        prm->conn = c;
    }
}

extern "C" int func_00480748(Owner *self, Param *prm) {
    int r = -1;
    Item *item = prm->item;
    int lock = item->lock;
    int state = item->state;
    int ctx = func_004816D0(lock);

    if (state == 3) {
        r = 0;
    } else if (state == 0) {
        Res res = self->lookup(item);
        Block *dst = &item->block;
        *dst = res.info;
        if (dst->a == 0) {
            r = self->func_005AE360(ctx, res.extra[0], dst->c);
            attach(self, prm, r);
        }
    } else {
        r = func_004BEB20(0, -1, 0x8000, ctx);
        attach(self, prm, r);
    }
    func_004816F0(lock);
    return r;
}
