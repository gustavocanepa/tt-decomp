struct Unk64 {
    short unk0;
    short pad2;
    int unk4;
};

struct NodeB {
    int unk0;
    Unk64 *unk64;
};

extern char func_00512000[];
extern char func_00550120[];

extern void *func_0050DB48(int, void *, int, void *, void *, void *);
extern void func_002C0FE8(void *);
extern void func_002C1050(void *);

int func_0011DEC8(void **arg0, NodeB **arg1)
{
    NodeB *temp_v1;
    void *var_s0;
    int var_v0;

    var_s0 = 0;
    temp_v1 = *arg1;
    if (temp_v1 != 0) {
        Unk64 *u = temp_v1->unk64;
        var_s0 = func_0050DB48(u->unk4, func_00512000, 0,
                                (char *)temp_v1 + u->unk0,
                                func_00550120, temp_v1);
    }
    if (var_s0 != 0) {
        func_002C0FE8(var_s0);
        if (*arg0 != 0) {
            func_002C1050(*arg0);
        }
        *arg0 = var_s0;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
