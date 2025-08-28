#include <iostream>
#include <vector>

using namespace std;

vector<int> leia_inteiros() {
    vector<int> numeros;
    int numero;
    while (cin >> numero) {
        numeros.push_back(numero);
        if (cin.peek() == '\n') break;
    }
    return numeros;
}

int main() {
    vector<int> ent = leia_inteiros();
    int heax = ent[0] + ent[1] + ent[2] + ent[5];
    int ow = ent[3] + ent[4];

    if (heax >= ow) {
        cout << "Middle-earth is safe." << endl;
    } else {
        cout << "Sauron has returned." << endl;
    }

    return 0;
}