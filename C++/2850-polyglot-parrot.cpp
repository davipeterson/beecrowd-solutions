#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char** argv){
	string str;
	while(getline(cin,str))
	{
		if(str=="esquerda")cout<<"ingles\n";

		else if(str=="direita")cout<<"frances\n";

		else if(str=="nenhuma")cout<<"portugues\n";
		else cout<<"caiu\n";
	}
	return 0;
}