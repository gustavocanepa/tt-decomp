/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec2 { float x, z; };
struct V3 { float x, y, z; };
struct Obj { char pad[4]; void **p; char pad8[8]; };
struct Entry {
    unsigned int flags;
    unsigned short idx;
    char pad[0x3A];
};
struct List {
    char pad[0x18];
    int n;
    Entry *ents;
    char pad20[4];
    Obj *objs;
};
struct Mid { char pad[0xCC]; List *list; };
struct Ctx { char pad[4]; Mid *mid; };
struct Pos { float x, w, z; };
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" void func_00378768(void *, Vec2 *);
extern "C" bool func_00379768(Obj *, Vec2 *) throw();
extern "C" float func_00552A38(float *);
extern "C" void func_00552A68(float *, float *);
extern "C" void func_00552C90(void *, void *);

extern "C" int func_003AA138(Pos *pos, Ctx *ctx, float r) {
    List *l = ctx->mid->list;
    pos->w = 0;
    if (!l) return -1;
    Vec2 p;
    p.x = pos->x;
    p.z = pos->z;
    int i;
    {
        for (i = 0; i < l->n; i++) {
            Entry *e = &l->ents[i];
            Obj *o = &l->objs[e->idx];
            if (e->flags & 1) {
                float a_[3];
                float *a = a_;
                float b[3];
                Vec2 c;
                func_004F6678(a, 0, 12);
                func_00378768(*o->p, &c);
                a[0] = c.x;
                a_[2] = c.z;
                func_00552A68(a, b);
                func_00552C90(b, pos);
                if (func_00552A38(b) < r * r) {
                    func_00552A68(a, &pos->x);
                    return i;
                }
            } else if (func_00379768(o, &p)) {
                return i;
            } else {
                continue;
            }
        }
    }
    return -1;
}
