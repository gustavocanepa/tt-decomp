struct func_0046B090_Cmd {
    int pad0;
    float value;
    unsigned char kind;
    unsigned char flags;
};

struct func_0046B090_Obj {
    char pad0[0x18];
    int x18;
    int x1c;
    char pad1[0x30 - 0x20];
    int x30;
    char pad2[0xB10 - 0x34];
    float xb10;
    float xb14;
};

extern signed char D_00587158[];

extern "C" {
void func_0046CC98(func_0046B090_Obj *self, float v);
void func_0046CC10(func_0046B090_Obj *self);
void func_0046CF68(func_0046B090_Obj *self, float v);
void func_0046CEE8(func_0046B090_Obj *self);
void func_0046CB90(func_0046B090_Obj *self);
void func_0046AFF8(func_0046B090_Obj *self);
}

extern "C" void func_0046B090(func_0046B090_Obj *self, func_0046B090_Cmd *cmd) {
    unsigned char k = cmd->kind;
    unsigned int type = k & 0x1F;
    float f;
    self->x18 = 0x16;
    self->x1c = D_00587158[k >> 5];
    self->x30 = 0;
    f = 255.0f;
    if ((unsigned char)(cmd->flags & 1) == 0)
        f = 128.0f;
    self->xb10 = f;
    f = 255.0f;
    if (!(cmd->flags & 2))
        f = 128.0f;
    self->xb14 = f;
    switch (type) {
    case 2:
        func_0046CC98(self, cmd->value);
        return func_0046CC10(self);
    case 3:
        func_0046CF68(self, cmd->value);
        return func_0046CEE8(self);
    case 5:
        return func_0046CB90(self);
    case 6:
        return func_0046AFF8(self);
    case 0:
    case 1:
    case 4:
        break;
    }
}
