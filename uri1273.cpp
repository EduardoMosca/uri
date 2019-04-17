#include <bits/stdc++.h>

using namespace std;

int maior(int *v, int t) {
    int i, a = 0;

    for(i = 0; i < t; i++) {
        if(a < v[i]) {
            a = v[i];
        }
    }
    return a;
}

int main(){

    int a, i, j, m = 0, var, cont = 0, cont2, aux2, boleano = 0;
    char esp = ' ', aux;
    char *t = new char[1];
    while(cin >> a) {
        if(a == 0) {
            break;
        }
        int *c = new int[a];
        char **v = new char*[a];
        for(i = 0; i < a; i++) {
            v[i] = new char[50];
        }
        for(i = 0; i < a; i++) {
            for(j = 0; j < 50; j++) {
                v[i][j] = ' ';
            }
        }
        i = 0;
        cont = 0;
        cin >> t;
        bloco:
            for(cont2 = 0; cont2 < strlen(t); cont2++) {
                v[cont][cont2] = t[cont2];
            }
            cont++;
            i++;
        cin.clear();
        if(i < a) {
            cin >> t;
            goto bloco;
        }
        for(i = 0; i < a; i++) {
            c[i] = 0;
            for(j = 0; j < strlen(v[i]); j++) {
                if(v[i][j] == ' ') {
                    break;
                }
                c[i]++;
            }
        }
        //percorre todas as palavras
        for(i = 0; i < a; i++) {
            aux2 = maior(c, a) - 1;
            cont = c[i] - 1;
            for(j = aux2; j >= (aux2 - cont); j--) {
                if(maior(c, a) == c[i]) {
                    break;
                }
                else{
                    v[i][aux2] = v[i][cont];
                    v[i][cont] = ' ';
                    aux2--;
                    cont--;
                }
            }
        }
        if(!boleano) {
            boleano = 1;
        }
        else {
            cout << endl;
        }
        for(i = 0; i < a; i++) {
            for(j = 0; j < maior(c, a); j++) {
                cout << v[i][j];
            }
            cout << endl;
        }

    }
    return 0;
}