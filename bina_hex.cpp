#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string binario_hexadecimal(string binario){
    string hexadecimal = "";
    int zeros = 0;
    int numeroConvertendo = 0;
    if (binario.length() % 4 != 0){
        zeros = 4 - (binario.length() % 4);
        for (int i = 0; i < zeros; i++){
            binario = "0" + binario;
        }
    }

	for (int i = binario.length()-1; i>=0; i-=4){
        for (int j = 0; j < 4; j++){
            if (binario[i-j] == '1'){
                numeroConvertendo += (int)pow(2, j);
            }
        }
        if (numeroConvertendo >= 10 && numeroConvertendo <= 15) 
        {
            numeroConvertendo += 55;//to usando a tabela dos caracteres la (A=65, f=70)
            hexadecimal = char(numeroConvertendo) + hexadecimal;
            numeroConvertendo = 0;
        }
        else
        {
            hexadecimal = to_string(numeroConvertendo) + hexadecimal;
            numeroConvertendo = 0;
        }
    }
    cout << hexadecimal << endl;
	return hexadecimal;
}


string hexadecimal_binario(string hexadecimal)
{
    string binario = "";
    int numeroConvertendo = 0;
    for (int i = hexadecimal.length()-1; i>=0; i--)
    {
        if (int(hexadecimal[i])>= 65 && int(hexadecimal[i])<=70)
        {
            numeroConvertendo = int(hexadecimal[i])-55;
        }
        else
        {
            numeroConvertendo = int(hexadecimal[i]);
        }
    
        for (int j = 1;j<=4;j++)
        {
            if (numeroConvertendo%2 == 0)
            {
                binario = "0" + binario;
                numeroConvertendo = floor(numeroConvertendo/2);
            }
            else
            {
                binario = "1" + binario;
                numeroConvertendo = floor(numeroConvertendo/2);
            }
        }
    }
    numeroConvertendo = 0;
    cout << binario << endl;
    return binario;
}


int main(){
    string tipo;
    cout << "Digite o tipo de entrada (binario/hexadecimal): ";
    cin >> tipo;
    if (tipo == "binario")
    {
        string binario;
        cout << "Digite um numero binario: ";
        cin >> binario;
        binario_hexadecimal(binario);
    }
    else if (tipo == "hexadecimal")
    {
        string hexadecimal;
        cout << "Digite um numero hexadecimal: ";
        cin >> hexadecimal;
        hexadecimal_binario(hexadecimal);
    }
    else
    {
        cout << "Tipo de entrada inválido: " << tipo << endl << "Tipos corretos: binario, hexadecimal" << endl;
    }
    return 0;
}