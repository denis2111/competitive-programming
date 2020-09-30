#define NMAX 100005
class Ctc{
private:
	int n;
	int viz[NMAX];
	vector<int> v[NMAX], v2[NMAX], st;

	void dfs(int nod){
		viz[nod] = 1;
		for (auto it : v[nod]){
			if (viz[it]) continue;
			dfs(it);
		}
		st.push_back(nod);
	}

	void dfs2(int nod){
		ctc.back().push_back(nod);
		viz[nod] = 2;
		for (auto it : v2[nod]){
			if (viz[it] == 2) continue;
			dfs2(it);
		}
	}

public:
	vector<vector<int>> ctc;
	vector<int> compressedCtc[NMAX];

	void setN(int _n){
		n = _n;
	}

	// add edge x->y
	void add(int x, int y){
		v[x].push_back(y);
		v2[y].push_back(x);
	}

	void run(){
		ctc.clear();
		for (int i=1;i<=n;i++) if (viz[i] == 0) dfs(i);

 		for (;!st.empty();st.pop_back()) if (viz[st.back()] != 2) {ctc.push_back(vector<int>()); dfs2(st.back());}
	}

	void compressCtc(){
		for (int i=0;i<ctc.size();i++) compressedCtc[i].clear();
		for (int i=0;i<ctc.size();i++) for (auto it : ctc[i]) viz[it] = i;

		set<pair<int,int>> uz;
		for (int i=1;i<=n;i++){
			for (auto it : v[i]){
				if (!uz.count({viz[i],viz[it]}) && viz[i] != viz[it]){
					uz.insert({viz[i],viz[it]});
					compressedCtc[viz[i]].push_back(viz[it]);
				}
			}
		}
	}
}ctc;
// ctc.SetN(n);
// ctc.run();
// ctc.compressCtc();