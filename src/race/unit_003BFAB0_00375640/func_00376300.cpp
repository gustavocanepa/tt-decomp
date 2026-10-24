/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Res { char pad[0x1CC]; int flag; };
struct Item { char pad[0x5450]; Res *record; };
struct List { volatile unsigned count; int pad; Item **items; };
struct Obj { char pad[0x60]; List *list; };
extern "C" void AutomobileControlRecord__Recorder__finish(void *);
static inline void finish(Item *item) {
    if (item->record->flag) AutomobileControlRecord__Recorder__finish((char *)item->record + 0xDC);
}
extern "C" void func_00376300(Obj *o) {
    unsigned i = 0;
    List *l = o->list;
    for (; i < l->count; i++) {
        finish(o->list->items[i]);
    }
}
