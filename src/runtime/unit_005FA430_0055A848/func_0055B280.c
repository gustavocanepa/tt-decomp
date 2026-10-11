typedef struct N { struct N *next; char pad[0xAC]; } N;
typedef struct P { N *head; N n[8]; } P;
void func_0055B280(P *arg0) {
    int i;
    for (i = 0; i < 7; i++) arg0->n[i].next = &arg0->n[i + 1];
    arg0->head = &arg0->n[0];
    arg0->n[7].next = 0;
}
