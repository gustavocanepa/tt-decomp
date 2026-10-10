struct Unk64 {
    short unk0;
    short pad2;
    int unk4;
};

struct Node {
    int unk0;
    char pad[0x60];
    Unk64 *unk64;
};

extern char func_00550B70[];
extern char func_00551160[];

extern Node **func_0017C860(void);
extern int func_0050DB48(int, void *, int, void *, void *, void *);

int func_0017C870(void)
{
    Node **temp_v0;
    Node *temp_v1;
    int var_v1;
    int var_v0;

    temp_v0 = func_0017C860();
    var_v1 = 0;
    if (temp_v0 != 0) {
        temp_v1 = *temp_v0;
        if (temp_v1 != 0) {
            Unk64 *u = temp_v1->unk64;
            var_v0 = func_0050DB48(u->unk4, func_00550B70, 0,
                                    (char *)temp_v1 + u->unk0,
                                    func_00551160, temp_v1);
        } else {
            var_v0 = 0;
        }
        var_v1 = var_v0;
    }
    return var_v1;
}
