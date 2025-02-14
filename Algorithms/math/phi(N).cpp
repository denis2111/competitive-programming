//number of coprime numbers with N less then N for all numbers from 1 to N
// O(NlogN)
int* getPhiAll(int N){
    int* phi = new int[N+1];
    for (int i=0;i<=N;i++) phi[i]=i;

    for (int i=2;i<=N;i++)
       if (phi[i]==i)
          for (int j=i;j<=N;j+=i) phi[j] /=i, phi[j] *= (i-1);
    return phi;
}

// number of coprime numbers with N and less then N
// O(sqrt(N))
int getPhi(int N){
    int ans = 1;
    for (int i=2;1LL * i*i<=N;i++){
        if (N % i == 0){
             while (N % i == 0){
                N /= i;
                ans *= i;
            }
            ans = ans / i * (i-1);
        }
    }
    if (N > 1) ans = ans * (N-1);
    return ans;
}