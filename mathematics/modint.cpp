#include<bits/stdc++.h>
using namespace std;
template<long mod = 1000000007>
struct modint {
    long value;
    /*constexpr modint operator = (int x){
        this->value = x % mod;
        return *this;
    constexpr modint operator = (long x){
        this->value = x % mod;
        return *this;
    }*/
    modint(long value){ this->value = value % mod; }
    /*modint<mod> operator = (modint<mod> i){
        this->value = i.value;
        return *this;
    }*/
    modint<mod> operator + (modint<mod> i){
        return {(this->value + i.value) % mod};
    }
    modint<mod> operator - (modint<mod> i){
        return {(this->value - i.value + mod) % mod};
    }
    modint<mod> operator * (modint<mod> i){
        return {(this->value * i.value) % mod};
    }
    modint<mod> operator / (modint<mod> i){
        return {(this->value * inv(i).value) % mod};
    }
    modint<mod> operator += (modint<mod> i){
        (this->value += i.value) %= mod;
        return *this;
    }
    modint<mod> operator -= (modint<mod> i){
        (this->value += mod - i.value) %= mod;
        return *this;
    }
    modint<mod> operator *= (modint<mod> i){
        (this->value *= i.value) %= mod;
        return *this;
    }
    modint<mod> operator /= (modint<mod> i){
        (this->value *= inv(i).value) %= mod;
        return *this;
    }
private:
    modint<mod> inv(modint<mod> i){
        long exp = mod - 2;
        modint<mod> ret(1);
        while(exp){
            if(exp % 2) ret *= i;
            i *= i;
            exp /= 2;
        }
        return ret;
    }
};
template<long mod>
ostream& operator << (ostream& os, modint<mod> i){
    os << i.value;
    return os;
}

int main(){
    modint<11> x(3), y = {5};
    cout<<x + y<<endl;
    cout<<x - y<<endl;
    cout<<x * y<<endl;
    cout<<x / y<<endl;
}