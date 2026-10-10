struct Obj {
    void *items[0x18];
    void *map;
};

extern "C" int func_004CEBD8(void *map, int key, int *index);

extern "C" int func_004CEF28(Obj *self, int key, void **out) {
    int index;
    int err = func_004CEBD8(self->map, key, &index);
    if (err == 0)
        *out = self->items[index];
    return err;
}
