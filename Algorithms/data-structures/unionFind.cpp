class UnionFind{
private:
    int *T;
    int lg;
    int *sz;

public:

    // 0 indexed
    UnionFind(int _lg){
        lg = _lg;
        T = new int[lg];
        sz = new int[lg];
        for (int i=0;i<lg;i++) T[i] = i, sz[i] = 1;
    }

    int root(int x){
        int rx = x, aux = 0;
        while (T[rx] != rx) rx = T[rx];
        while (T[x] != x){
            aux = T[x];
            T[x] = rx;
            x = aux;
        }
        return rx;
    }

    int _union(int x, int y){
        int rx = root(x);
        int ry = root(y);
        T[rx] = ry;
        if (rx != ry){
            sz[ry] += sz[rx];
        }
    }

    int getSz(int x){
        x = root(x);
        return sz[x];
    }
};