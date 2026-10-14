struct N { N *next; }; struct S { int a,b; N *head; }; N *func_00393550(S *s) { N *n=s->head; if(n==0) return 0; s->head=n->next; return n; }
