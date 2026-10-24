/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rect {
    char unk0;
    char pad1[3];
    short unk4;
    short unk6;
};

struct Ent {
    char d[8];
};

struct Slot {
    s32 state;
    char pad4[0x218 - 4];
    Ent ent[64];
    s32 count;
};

struct Game {
    char pad0[0x20];
    char slots[0x41C * 2];
    char pad[0x85C - 0x20 - 0x41C * 2];
    s32 unk858;
    char pad85C[4];
    s32 unk860;
};

extern "C" {
Rect *func_004834E8(void *) throw();
Rect *func_00483528(void *) throw();
void func_00483860(void *, void *, void *) throw();
void func_00484050(void *, s32) throw();
void func_00484360(void *) throw();
}

extern "C" s32 func_00484DB8(Game *g)
{
    if (g->unk860 != 0) return 1;
    Slot *s = (Slot *)((char *)g + (1 - g->unk858) * 0x41C + 0x24);
    Rect *a = func_004834E8(g);
    Rect *b = func_00483528(g);
    switch (s->state) {
    case 0:
        func_00483860(g, a, b);
        break;
    case 1:
        if (a->unk6 == a->unk4 && b->unk6 == b->unk4) {
            s32 n = s->count;
            s32 i = n - 1;
            s32 j = n + 2;
            func_00483860(g, &s->ent[i], a);
            func_00483860(g, a, b);
            func_00483860(g, b, &s->ent[j]);
        } else {
            func_00483860(g, a, b);
            func_00484050(g, -1);
        }
        break;
    case 2:
        if (s->count > 0) {
            char *entry = (char *)s + s->count * 8;
            char k = entry[0x210];
            if (k == s->state) {
                a->unk0 = k;
                s->count = s->count - 1;
                func_00484360(g);
            }
        }
        return 1;
    }
    return 1;
}
