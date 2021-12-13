#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { // алгоритм Евклида
	/*
        Алгоритм нахождения наибольшего общего
        делителя двух чисал (НОД)
        O(log(n))
    */
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
    /*
        Алгоритм нахождения наименьшего общего
        кратного двух чисал (НОК)
        O(log(n))
    */
    return a * b / gcd(a, b);
}

bool isPrime(int n) { 
    // O(sqrt(n))
    if (n == 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) 
            return 0;
    }
    return 1;
}

vector<bool> resheto(int n) { // решето Эратосфена
    /*
        Для каждого из чисел от 1 до n определяет оно
        простое или нет за 
        O(n * log(log(n)))
    */
    vector <bool> p(n + 1, true);
    p[1] = p[0] = 0;
    for (int i = 2; i <= n; i++) {
        if (p[i] == true && i * 1ll * i <= n) {
            for (int j = i * i; j <= n; j += i) { // i*2, i*3, i*4, i*5, i*6...
                p[j] = false;
            }
        }   
    }

    return p;
}

int phi (int n) { 
    /*
        Функция Эйлера
        phi(n) - количество чисел от 1 до n, взаимно простых с n
        O(sqrt(n))
    */
    int result = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    /*
        n = p1^a1 * p2^a2 * p3^a3 * p4^a4...
        количество делителей числа n = (a1+1) * (a2+1) * (a3+1) * (a4+1)...
    */ 

    int n;
    cin >> n;
    
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            cout << i << ' ';
        }
    }
    if (n > 1) 
        cout << n;
}
// 1 3 5 7
