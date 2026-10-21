typedef struct {
    int w[6];
} Value_0033DE30;

typedef struct {
    char pad0[0xE3B8];
    Value_0033DE30 value;
    int tail;
} Node_0033DE30;

void func_002D0818(Node_0033DE30 *node, const Value_0033DE30 *v) {
    node->value = *v;
    node->tail = 1;
}
