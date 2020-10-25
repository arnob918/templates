
void radix_sort(vector<pair<pair<int, int>, int> > &a)
{
    int n = a.size();
    {
        vector<int> cnt(n);
        for(auto x: a){
            cnt[x.first.second]++;
        }
        vector<pair<pair<int, int>, int> > a_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for(int i=1; i<n; i++){
            pos[i] = pos[i-1]+cnt[i-1];
        }
        for(auto x: a){
            int i = x.first.second;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
    {
        vector<int> cnt(n);
        for(auto x: a){
            cnt[x.first.first]++;
        }
        vector<pair<pair<int, int>, int> > a_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for(int i=1; i<n; i++){
            pos[i] = pos[i-1]+cnt[i-1];
        }
        for(auto x: a){
            int i = x.first.first;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
}

vector<int> suff_array(string s)
{
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    vector<pair<char, int> > a(n);
    for(int i=0; i<n; i++){
        a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for(int i=1; i<n; i++){
        if(a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
        else c[p[i]] = c[p[i-1]]+1;
    }
    int k = 0;
    while((1<<k) < n){
        vector<pair<pair<int, int>, int> > a(n);
        for(int i=0; i<n; i++){
            a[i] = {{c[p[i]], c[(p[i]+(1<<k)) % n]}, p[i]};
        }
        radix_sort(a);
        for(int i=0; i<n; i++){
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for(int i=1; i<n; i++){
            if(a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]]+1;
        }
        k++;
    }
    return p;
}
