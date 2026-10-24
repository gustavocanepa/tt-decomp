/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { char pad[0xA]; short w; };
struct Table { char pad[0x50]; char *items; };
struct Ctx { char pad[0x6E20]; Table *t; };
struct S { float x,y,right,bottom; int z; short idx; unsigned short scale; char pad18[3]; unsigned char align; };
extern "C" Entry *func_00440498(void *, unsigned short) throw();
extern "C" float func_00440E50(S *, Ctx *, char **);
extern "C" void func_00445838(Entry *, Ctx *);
extern "C" void func_004755EC(float, float, float);
extern "C" float func_00440C48(S *s, Ctx *ctx, char **pp) {
    float offset;
    char *start = *pp;
    Entry *entries[64];
    Entry **out = entries;
    Entry **begin = out;
    float sum = 0.0f;
    char *tab = ctx->t->items + s->idx*0x18;
    for (;;) {
        char *p = *pp;
        char ch = *p;
        if (ch == 0 || ch == 13) { *pp = p-1; break; }
        *pp = p+1;
        Entry *e = func_00440498(tab,ch);
        if (e) {
            sum += (float)e->w * 0.05f;
            if (out < entries+64) *out++ = e;
        }
    }
    offset = 0.0f;
    float width = ((s->right-s->x)*1024.0f)/(float)s->scale;
    if (s->align == 2) offset = (width-sum)*0.5f;
    else if (s->align == 1) offset = width-sum;
    func_004755EC(offset,0.0f,0.0f);
    if (out < entries+64) {
        *out = 0;
        out = entries+1;
        Entry *e = *begin;
        while (e) {
            func_00445838(e,ctx);
            func_004755EC((float)e->w*0.05f,0.0f,0.0f);
            e = *out++;
        }
        return offset + sum;
    } else {
        func_00440E50(s,ctx,&start);
    }
    return offset + sum;
}
