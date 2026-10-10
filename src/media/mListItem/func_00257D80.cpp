struct Item {
    char pad[0x1C];
    unsigned int lo : 16;
    unsigned int on : 1;
    unsigned int hi : 15;
};
extern "C" int func_002571D8(void *list);
extern "C" Item *func_002571B8(void *list, int i);

extern "C" void func_00257D80(void *list, int i, int on)
{
    if (i >= 0 && i < func_002571D8(list)) {
        Item *it = func_002571B8(list, i);
        it->on = on != 0;
    }
}
