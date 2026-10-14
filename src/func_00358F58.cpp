/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Event { int pad0, pad4, kind, id; };
struct Packed { unsigned int kind : 4; unsigned int id : 28; };
union Word { Packed p; unsigned int w; };
extern "C" unsigned int RaceDisplayMessageEvent__encode(Event *e) {
    Word value;
    value.p.kind = e->kind;
    value.p.id = e->id;
    return value.w;
}
