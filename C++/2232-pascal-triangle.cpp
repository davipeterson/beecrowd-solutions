#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, t;
    int result;
    cin >> t;

    while(t--){
        cin >> n;

        result = pow(2, n) - 1;
        cout << result << endl;
    }

    return 0;
}