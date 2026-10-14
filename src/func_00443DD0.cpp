struct S{char p[0x1c];unsigned char flags[128];char q[0x84];int dirty;};void func_00443DD0(S*s,unsigned int n){if(n<128){s->flags[n]=(s->flags[n]&0xfe)|8;s->dirty=1;}}
