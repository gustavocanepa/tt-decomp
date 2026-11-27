struct Node {
    Node *next;
};

struct Obj {
    char pad[8];
    Node *unk8;
    Node *unkC;
};

extern "C" Node *func_002E0A88(Obj *arg0) {
    Obj *self = arg0;
    Node *temp = self->unkC;
    if (temp == 0) {
        return 0;
    }
    Node *n = temp->next;
    Node *old = self->unk8;
    self->unkC = n;
    temp->next = old;
    self->unk8 = temp;
    return temp;
}
