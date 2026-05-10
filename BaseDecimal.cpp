#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//sub prog pra calcular  base 2/8/16 -> decimal
int base_decimal(string numero, int B){
	int decimal=0;
	int potencia=0;
	int algarismo=0;
	for(int i=numero.length()-1;i>=0;i--){//como vetor da string começa em 0 a condiçao tem que ser ate chegar em 0 e descontar da quantidade de caracteres(.length)
		//converçao das letras usadas no hexa
		if(numero[i]=='A') 
			algarismo=10;
		else if (numero[i]=='B') 
			algarismo=11;
		else if( numero[i]=='C') 
			algarismo=12;
		else if( numero[i]=='D' )
			algarismo=13;
		else if( numero[i]=='E') 
			algarismo=14;
		else if( numero[i]=='F')
			algarismo=15;
		//converçao do 0 ao 9, assim temos todos int caracteres necessarios para o calculo
		else {
			algarismo=numero[i]-'0';//- '0' converte numero string para int
	}
	
		decimal+=algarismo*pow(B,potencia);
		potencia++;
		
	}
return decimal;
}
int main(){
	string A;
	int B;
	cin>>A>>B;
	cout<<base_decimal(A, B);
return 0;
}
		
	
	 
	
