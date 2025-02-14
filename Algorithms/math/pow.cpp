// a ^ b
int _pow(int a, int b){
    int ans = 1;
    if (a >= MOD) a %= MOD;
    for (int i=0;(1LL<<i)<=b;i++,a=1LL*a*a%MOD){
        if (b & (1LL<<i))
            ans = 1LL * ans * a % MOD;
    }
    return ans;
}
