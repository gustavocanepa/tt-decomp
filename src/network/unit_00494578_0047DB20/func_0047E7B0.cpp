extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Client {
    char pad0[0xA8];
    VEntry *vt;
};

struct Node {
    Client *client;
    int pad4;
    Node *next;
};

struct Server {
    char mutex[0xAC];
    Node *head;
};

extern "C" void func_0047E7B0(Server *self)
{
    func_004A4D68(self);
    for (Node *n = self->head; n != 0; n = n->next) {
        Client *c = n->client;
        VEntry *e = &c->vt[3];
        e->fn((char *)c + e->delta);
    }
    func_004A4DD8(self);
}
