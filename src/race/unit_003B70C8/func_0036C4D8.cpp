union W{int i;short h[2];};W*func_0036C4D8(W*s){int n=s[3].i;if(n<0)return 0;W*p=s+n*2;unsigned short old=s[2].h[0];s[3].i=p->h[0];p->h[0]=old;s[2].i=n;return p;}
