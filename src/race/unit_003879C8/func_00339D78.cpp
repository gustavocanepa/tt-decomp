/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { int x; unsigned int value; };
struct Node { Node *next; Data *data; };
extern Node *D_00583EE4;
extern unsigned int D_00583EE0;
static inline void insert(Node *&head, Node *node) { node->next=head; head=node; }
static inline void maximize(unsigned int &max, Data *data) { unsigned int value=data->value; if(max<value) max=value; }
extern "C" void func_00339D78(Node *node, Data *data) {
    node->data=data;
    insert(D_00583EE4,node);
    maximize(D_00583EE0,data);
}
