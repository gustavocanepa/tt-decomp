struct Node {
    char pad[0x10];
    unsigned long long offset : 24;
    unsigned long long rest : 40;
};
extern "C" unsigned int func_003F6D60(Node *n);

extern "C" void func_003FB678(Node *n, unsigned int addr)
{
    n->offset = addr - func_003F6D60(n);
}
