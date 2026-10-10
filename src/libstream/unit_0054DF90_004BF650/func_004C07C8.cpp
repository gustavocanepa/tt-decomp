struct func_004C07C8_Obj {
    int count[2];
    int handle[2];
    char pad0[0x6C - 0x10];
    int value[2];
    char pad1[0xF4 - 0x74];
    char block[8];
    int fc;
};

struct func_004C07C8_Msg {
    int pad0;
    int type;
    int index;
    char pad1[0x18 - 0xC];
    int size;
    int data;
};

extern "C" void func_004F6678(void *dst, int c, int n);
extern "C" int func_004CF028(func_004C07C8_Obj *self, int index, void *buf, int size, int a, int b);
extern "C" void func_004C2D50(int handle, void *data, int size, int flag);

extern "C" int func_004C07C8(func_004C07C8_Obj *self, func_004C07C8_Msg *msg) {
    int ret = 0;
    int index = msg->index;
    switch (msg->type) {
    case 3:
    case 4:
        break;
    case 2: {
        int *p = (int *)self + index;
        p[0x6C / 4] = 0;
        p[0]++;
        break;
    }
    case 1: {
        int zero;
        int *p = (int *)self + index;
        p[0]++;
        func_004F6678(self->block, 0, 8);
        zero = 0;
        func_004CF028(self, index, &zero, 4, 4, 1);
        p[0x6C / 4] = msg->data;
        self->fc = 0;
        break;
    }
    case 5:
        func_004C2D50(self->handle[index], &msg->data, msg->size, 1);
        break;
    case 6:
        ret = func_004CF028(self, index, &msg->data, msg->size, 4, 1);
        break;
    }
    return ret;
}
