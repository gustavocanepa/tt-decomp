struct Node { Node *next; const char *name; };
extern "C" Node *D_005861F0;
extern "C" int func_004A8268(const char *a, const char *b);

extern "C" Node *func_0042F3E8(const char *name)
{
    Node *n; for (n = D_005861F0; n; n = n->next) if (!func_004A8268(n->name, name)) break; return n;
}
