struct func_004C1BF0_Msg {
    int index;
};

struct func_004C1BF0_Handler {
    void (*fn)(void *arg, func_004C1BF0_Msg *msg);
    void *arg;
};

struct func_004C1BF0_Obj {
    char pad[0xA4];
    func_004C1BF0_Handler handlers[1];
};

extern "C" void func_004C1C78(func_004C1BF0_Obj *self, func_004C1BF0_Msg *msg);

extern "C" int func_004C1BF0(func_004C1BF0_Obj *self, int type, func_004C1BF0_Msg *msg) {
    func_004C1BF0_Handler *h = &self->handlers[msg->index];
    switch (type) {
    case 1:
    case 2:
    case 4:
        if (h->fn)
            func_004C1C78(self, msg);
        break;
    case 3:
    case 5:
        if (h->fn)
            h->fn(h->arg, msg);
        break;
    }
    return 0;
}
