/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { char pad[0x23968]; int count; };
struct Item { char pad[0x4F4]; };
struct Obj { Data *data; int count; int other; Item items[1]; };
extern "C" void func_00426748(Item *, Item *, int);
extern "C" void func_00425D60(Obj *obj) {
    obj->count = obj->data->count;
    for (int i = 0; i < obj->count; i++)
        func_00426748(&obj->items[i], obj->items, obj->count);
}
