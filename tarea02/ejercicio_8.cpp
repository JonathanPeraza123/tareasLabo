#include <iostream>

using namespace std;

void contar(int, int);

int main(void)
{
    int num = 0;
    cout << "CONTADOR RARO ***************************************************" << endl;
    cout << "Digite un numero: " << endl;
    cin >> num;
    cout << "---------------------------------" <<endl; 
    contar(num, 1);
    return 0;
}

void contar(int a, int b){
    cout << b << endl;
    if(a == 1)
        if (b == 1)
            return;
        else
            return contar(a, b-1);
    else
        return contar(a-1, b+1); 
}

