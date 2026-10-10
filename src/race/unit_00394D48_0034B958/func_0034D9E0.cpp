struct Item { char d[0x20]; };
struct List {
    int count;
    Item items[1];
};
extern "C" void func_0038FBC8(void *ctx, Item *item);

extern "C" void func_0034D9E0(List *l, void *ctx)
{
    for (int i = 0; i < l->count; i++)
        func_0038FBC8(ctx, &l->items[i]);
}
