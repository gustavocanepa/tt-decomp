struct Node;

struct Owner {
    char pad0[0x30];
    struct Node *head;
};

struct Node {
    struct Node *next;
    struct Owner *owner;
};

void func_004E6668(struct Node *n) {
    struct Node **pp = &n->owner->head;
    while (*pp != 0) {
        if (*pp == n) {
            *pp = n->next;
            return;
        }
        pp = &(*pp)->next;
    }
}
