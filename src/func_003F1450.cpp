/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
struct Rec { s32 f0; float f4; s32 f8; float fC; u16 f10; u16 f12; s32 f14; s32 f18; s32 f1C; };
struct Elem { char pad[0x20]; };
struct Grp { s32 p0; s16 p4; s16 p6; Elem *elems; s32 pC; };
struct Ent { s32 p0; s16 g; s16 p6; s16 e; s16 pa; s32 pc; };
struct Set { char pad[0x10]; Grp *groups; s32 p14; s32 p18; Ent *ents; };
struct Out { s32 a; float b; float c; s32 d; s32 e; s32 f; };
extern "C" Rec *GT4_Motion__PlayList__getElement(Elem *);
extern "C" s32 GT4_Motion__MotionSetPlayer__getPlayListElementInformation(Out *out, Set *set, s32 idx) {
    if (idx < 0) return 0;
    idx = idx * sizeof(Ent) + (s32)set->ents;
    s32 k = ((Ent *)idx)->e;
    if (k >= 0) {
        Grp *g = set->groups;
        g += ((Ent *)idx)->g;
        Rec *r = GT4_Motion__PlayList__getElement(g->elems + k);
        out->a = r->f18;
        float start = r->f4;
        float len = r->fC;
        out->b = start;
        out->c = start + len;
        out->d = r->f10;
        out->e = r->f1C;
        out->f = r->f0;
        return 1;
    }
    return 0;
}
