#include <iostream>
#include <string>
using namespace std;
//sub prog pra calcular decimal para  base 2/8/16 
string base_decimal(int decimal, int B){
 // tem caracteres usados em todas bases 01 binaro,0 a 7 octal e 0 a F hexa
	 string caracter="0123456789ABCDEF";
	 string resultado="";
	 int resto;//necessario pra saber qual é o caracter
		while(decimal>0){
			resto= decimal%B;
			decimal=decimal/B;
// pega o caracter de acordo com o resto da divisao e soma na string resultado formando o numero da base pedida
			resultado=caracter[resto]+ resultado;
		}
	return resultado;
}

