struct Node {
    Node *next;
    void *item;
};

extern "C" Node *D_005DB0F8;
extern "C" char D_006137E0[];
extern "C" int func_004C9E58(void *item, const char *name);

extern "C" int func_004C9E90(const char *name)
{
    if (!name)
        name = D_006137E0;
    for (Node *n = D_005DB0F8; n; n = n->next) {
        int r = func_004C9E58(n->item, name);
        if (r)
            return r;
    }
    return 0;
}
