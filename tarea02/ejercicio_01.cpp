#include <iostream>

using namespace std;


int mcd(int, int);


int main(void)
{
    int a, b, MCD;
    cout << "MCD DE DOS NUMEROS ***************************************************" << endl;
    cout << "Digite el numero mayor: " << endl;
    cin >> a;
    cout << "Digite digite el numero menor: " << endl;
    cin >> b;
    MCD = mcd(a, b);

    cout << "El valor del MCD de " << a << ", " << b << " = " << MCD << endl;  
    
    return 0;
}

int mcd(int a, int b){
    int aux = 0;
    aux = a%b;
    if(aux == 0)
        return b;
    else
        mcd(b, aux);
}
