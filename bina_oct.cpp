#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string binario_octal(string binario){
    string octal = "";
    int zeros = 0;
    int numeroConvertendo = 0;
    if (binario.length() % 3 != 0){
        zeros = 3 - (binario.length() % 3);
        for (int i = 0; i < zeros; i++){
            binario = "0" + binario;
        }
    }

	for (int i = binario.length()-1; i>=0; i-=3){
        for (int j = 0; j < 3; j++){
            if (binario[i-j] == '1'){
                numeroConvertendo += (int)pow(2, j);
            }
        }
        octal = to_string(numeroConvertendo) + octal;
        numeroConvertendo = 0;
    }
    cout << octal << endl;
	return octal;
}

string octal_binario (string octal)
{
    string binario = "";
    int numeroConvertendo = 0;
    for (int i = octal.length()-1; i>=0; i--)
    {
        numeroConvertendo = octal[i];
        for (int j = 1;j<=3;j++)
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
    cout << "Digite o tipo de entrada (binario/octal): ";
    cin >> tipo;
    if (tipo == "binario")
    {
        string binario;
        cout << "Digite um numero binario: ";
        cin >> binario;
        binario_octal(binario);
    }
    else if (tipo == "octal")
    {
        string octal;
        cout << "Digite um numero octal: ";
        cin >> octal;
        octal_binario(octal);
    }
    else
    {
        cout << "Tipo de entrada inválido: " << tipo << endl << "Tipos corretos: binario, octal" << endl;
    }
    return 0;
}