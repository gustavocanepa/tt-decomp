/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { unsigned char tag, count; char pad[0x1a]; unsigned char modes[16]; unsigned char map[16]; signed char signs[16]; };
struct State { char pad[0x14]; float a; char gap[8]; float b; };
struct Car { char pad[0x10]; float first[1]; };
struct Part { char pad[0x20]; float second[1]; };
struct Entry { char pad[0x14]; float value; char rest[0xF4-0x18]; };
struct Obj { char pad[0x10]; Car *car; };
extern "C" Info *func_002FD378(void *);
static inline float value(Part *p, int n) { return p->second[n]; }
static inline int positive(Info *p, int n) { if(n >= p->count) return 0; return p->signs[n] > 0; }
static inline unsigned int negative(Info *p, int n) { if(n >= p->count) return 0; return p->signs[n] < 0; }
extern "C" void func_002E7768(Obj *self) {
    State *state = (State *)((char *)self + 0x104);
    Car *car = self->car;
    Info *info = func_002FD378(car);
    int i = 0;
    if(info->count != 0) {
        Entry *e = (Entry *)((char *)self + 0x164);
        do {
            int j = info->map[i];
            float x = state->b * value((Part *)((char *)car + 8), j);
            int mode = info->modes[i];
            if(mode == 0) e->value = -x;
            else if((mode ^ 1) == 0) e->value = x;
            else e->value = 0;
            float y = state->a * car->first[j];
            if(positive(info,i)) e->value += y;
            else if(negative(info,i)) e->value -= y;
            i++;
            e++;
        } while(i < info->count);
    }
}
