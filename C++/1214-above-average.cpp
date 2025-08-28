#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int c, n, i, total, acima;
    float media, media1;

    cin >> c;
    while(c > 0){
        cin >> n;

        acima = 0;
        total = 0;

        int alunos[n];

        for(i = 0; i < n; i++){
            cin >> alunos[i];
            total += alunos[i];
        }

        media = (float)total / n;

        for(i = 0; i < n; i++){
            if(alunos[i] > media)
                acima++;
        }

        media1 = (float)acima / n * 100;
        cout << fixed << setprecision(3);
        cout << media1 << "%" << endl;

        c--;
    }

    return 0;
}