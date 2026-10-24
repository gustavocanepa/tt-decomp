struct S{char p[0x58];int size,index;};int func_003FAE30(S*s,int n){int r=s->index!=n;if(n==s->size-1){++s->index;if(s->index>=s->size)s->index=0;}return r;}
