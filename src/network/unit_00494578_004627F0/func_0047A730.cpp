/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; int length; char data[1]; };
extern "C" void *func_004F64C4(void *, const void *, unsigned int);
extern "C" void func_0047A730(char *out, const char *input) {
    Node head;
    Node reverse;
    head.next = 0;
    head.length = 0;
    head.data[0] = 0;
    const char *p = input;
    for (;;) {
        while (*p == '/') p++;
        if (*p == 0) break;
        const char *start = p;
        while (*p != 0 && *p != '/') p++;
        int length = p - start;
        if (length == 1 && start[0] == '.') continue;
        if (length == 2 && start[0] == '.' && start[1] == start[0]) {
            if (head.next != 0) head.next = head.next->next;
            continue;
        }
        Node *node = (Node *)__builtin_alloca(length + sizeof(Node));
        func_004F64C4(node->data, start, length);
        node->data[length] = 0;
        node->length = length;
        node->next = head.next;
        head.next = node;
    }
    reverse.next = 0;
    reverse.data[0] = 0;
    while (head.next != 0) {
        Node *node = head.next;
        head.next = node->next;
        node->next = reverse.next;
        reverse.next = node;
    }
    head.next = reverse.next;
    char *dest = out;
    for (Node *node = head.next; node != 0; node = node->next) {
        if (dest != out) *dest++ = '/';
        func_004F64C4(dest, node->data, node->length);
        dest += node->length;
    }
    *dest = 0;
}
