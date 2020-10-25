
lli bigmod(lli a, lli b, lli m)//a^b%m
{
    lli gg = a%m;
    lli ret = 1;
    while(b){
        if(b%2){
            ret = (ret*gg) % m;
        }
        gg = (gg*gg) % m;
        b/=2;
    }
    return ret;
}
