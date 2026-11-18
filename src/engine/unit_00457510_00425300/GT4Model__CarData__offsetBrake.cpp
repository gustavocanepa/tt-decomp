struct Stream {
    int f0, f4, f8, fC, f10, f14;
    char pad18[0x20];
    int f38, f3C, f40;
    char pad44[12];
};
struct Ent { const char *name; int id; };
struct Info { char pad[0x30]; unsigned short cnt; char pad32[0x32]; Ent *arr; };
struct Obj { char pad[0x18]; Info *info; };
extern char D_00600848[], D_00600858[], D_00600868[], D_00600870[];
extern "C" int func_004A8268(const char *, const char *);
extern "C" int func_00420718(Info *, int);
extern "C" int func_00463200(Stream *, int, int);
extern "C" int func_00463248(Stream *);
extern "C" float *func_004637E0(Stream *);
static inline char *more(Stream *s) { return s->f40 == 0 ? &s->pad18[16] : 0; }
extern "C" void GT4Model__CarData__offsetBrake(Obj *o, float amount)
{
    if (o->info) {
        if (amount != 0.0f) {
            for (Ent *e = o->info->arr; e != o->info->arr + o->info->cnt; e++) {
                const char *name = e->name;
                int id = e->id;
                int hit = 0;
                if (func_004A8268(name, D_00600848) == 0 || func_004A8268(name, D_00600858) == 0 ||
                    func_004A8268(name, D_00600868) == 0 || func_004A8268(name, D_00600870) == 0)
                    hit = 1;
                float v = amount;
                if (!hit) v = -v;
                Stream it;
                func_00463200(&it, func_00420718(o->info, id), 1);
                while (more(&it)) {
                    float *p = func_004637E0(&it);
                    *p += v;
                    func_00463248(&it);
                }
            }
        }
    }
}
