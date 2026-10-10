/* compiler: ee-gcc2.96-as2004 */
struct Item {
    char pad[0xC];
    int priority;
};

struct Node {
    Item *item;
    Node *prev;
    Node *next;
};

struct List {
    Node *head;
};

extern "C" char D_0058C558[];
extern "C" List D_0058C588;
extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);
extern "C" void func_004AC860(List *list, Node *pos, Item *item);

extern "C" void func_0047C618(Item *item) {
    func_004A4D68(D_0058C558);
    int p = item->priority;
    Node *n = D_0058C588.head;
    while (n != 0 && p >= n->item->priority)
        n = n->next;
    func_004AC860(&D_0058C588, n, item);
    func_004A4DD8(D_0058C558);
}
