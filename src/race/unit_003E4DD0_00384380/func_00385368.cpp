/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Query { unsigned short index; short valid; };
struct Part { unsigned short index; char pad[10]; };
struct Name { char pad[12]; short index; short tail; };
struct Obj { char pad[0x6c]; unsigned short *names; char gap[4]; Name *entries; Part *parts; };
static inline unsigned short partIndex(Query *q) { return q->index; }
static inline unsigned short nameIndex(Part *p) { return p->index; }
extern "C" int func_00385368(Obj *o, Query *q) {
 if (q->valid < 0) return 0;
 Part *p = o->parts + partIndex(q);
 Name *n = o->entries + nameIndex(p);
 int index = n->index;
 if (index >= 0) return (int)(o->names + index);
 return 0;
}
