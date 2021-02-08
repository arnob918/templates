lli mod = 1e9+7;

template<typename T>
class mat{
public:
	int r, c;
	vector<vector<T> > m;
	mat(int rr=0, int cc=0){
		m.resize(rr);
		for(auto &v: m) v.resize(cc);
		r = rr;
		c = cc;
	}
	mat operator + (const mat &o) const {
		int row = o.r;
		int col = o.c;
		mat res(row, col);
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				res.m[i][j] = (m[i][j] + o.m[i][j])%mod;
			}
		}
		return res;
	}
	
	mat operator - (const mat &o) const {
		int row = o.r;
		int col = o.c;
		mat res(row, col);
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				res.m[i][j] = (m[i][j] - o.m[i][j])%mod;
				res.m[i][j] = (res.m[i][j]+mod+mod)%mod;
			}
		}
		return res;
	}
	
	mat operator * (const mat &o) const {
		//int row = o.r;
		int col = o.c;
		mat res(r, col);
		for(int i=0; i<r; i++){
			for(int j=0; j<col; j++){
				T all = 0;
				for(int k=0; k<c; k++){
					all = (all+m[i][k]*o.m[k][j])%mod;
				}
				res.m[i][j] = all;
			}
		}
		return res;
	}
};
