/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Car { char pad[0x1168]; int flags; };
struct List { char pad[8]; Car **head; };
struct Data { char pad[0x60]; List *list; };
struct Obj { char pad[0x6c]; Data *data; char pad70[0xF260-0x70]; Car *replacement; Car *old; };
extern "C" void func_003695A8(void *, int);
extern "C" void func_0037C048(void *, void *);
extern "C" void RaceSolitaire__loadReplaceData(Obj *self, char *src) {
    Car *car = self->replacement;
    if (!self->old) {
        Data *data = self->data;
        self->old = *data->list->head;
        *data->list->head = car;
    }
    func_003695A8(car, 0);
    func_0037C048(car, src + 0x960);
    car->flags = 0x100;
}
