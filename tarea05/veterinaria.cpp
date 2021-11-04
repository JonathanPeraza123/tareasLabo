#include <iostream>
#include <string>

using namespace std;

struct nodo{
    int id;
    string nameOwers;
    string race;
    float weight;
    int age;
    nodo *sig;
};

class ListaCircSimple{
    private: 
        nodo *pInicio;
    
    public:
        ListaCircSimple();
        ~ListaCircSimple();
        void eliminarListaCircRec(nodo *);
        void insertaNodo(void);
        void insInicio(int id, string dueno, string raza, float peso, int edad);
        void eliRegistro(void);
        bool eliminar(int id);
        void searchRegistro(void);
        void buscar(int id);
};

ListaCircSimple::ListaCircSimple(void)
{
    pInicio = NULL;
}

ListaCircSimple::~ListaCircSimple()
{
    cout << "Destructor ejecutándose" << endl;
    if(pInicio){
        eliminarListaCircRec(pInicio);
        pInicio = NULL;
    }
}

void ListaCircSimple::eliminarListaCircRec(nodo *p){
    if(p->sig != pInicio)
        eliminarListaCircRec(p->sig);
    delete p;
}

void ListaCircSimple::insertaNodo(void)
{
    int id;
    string nameOwers;
    string race;
    float weight;
    int age;

    cout << "Bienvenido vamos a registrar a tu mascota" <<endl;
    cout << "Id de la mascota: ";
    cin >> id;
    cout << "Nombre del dueño: ";
    cin >> nameOwers;
    cout << "Raza de la mascota: ";
    cin >> race;
    cout << "Peso de la mascota: ";
    cin >> weight;
    cout << "Edad de la mascota: ";
    cin >> age;

    insInicio(id, nameOwers, race, weight, age);
}

void ListaCircSimple::insInicio(int id, string dueno, string raza, float peso, int edad)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->id = id;
    nuevo->nameOwers = dueno;
    nuevo->race = raza;
    nuevo->weight = peso;
    nuevo->age = edad;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else{
        nuevo->sig = pInicio;
        nodo *saltarin = pInicio;
        while(saltarin->sig != pInicio){
            saltarin = saltarin->sig;
        }
        saltarin->sig = nuevo;
        pInicio = nuevo;
    }
}
void ListaCircSimple::eliRegistro(void)
{
    int dato = 0;
    bool aux;
    cout << "Por favor ingresar el id que desea eliminar: " << endl; 
    cin >> dato;
    aux = eliminar(dato);
    if (aux)
    {
        cout << "El registro del estudiante fue eliminado exitosamente :)" << endl << endl;
    }else{
        cout << "El registro con ese id no existe :(" << endl << endl;
    }
}

void ListaCircSimple::searchRegistro(void)
{
    int dato = 0;
    bool aux;
    cout << "Por favor ingresar el id del registro que desea buscar: " << endl; 
    cin >> dato;
    buscar(dato);
}

bool ListaCircSimple::eliminar(int dato)
{
    if(!pInicio){
        return false;
    } else {
        nodo *s = pInicio, *p;
        if(s->id == dato) {
            pInicio = pInicio->sig;
            delete s;
            return true;
        } 
        else {
            while (s->sig && s->sig->id != dato)
                s = s->sig;
                if (!s->sig)
                {
                    return false;
                } else {
                    p = p->sig;
                    s->sig = s->sig->sig;
                    delete p;
                    return true;
                }
        }
    }
}

void ListaCircSimple::buscar(int dato)
{
    if(!pInicio){
        cout << "La lista esta vacia" <<endl;
    } else {
        nodo *s = pInicio, *p;
        if(s->id == dato) {
            pInicio = pInicio->sig;
            cout << "----------------------" <<endl;
            cout << "ID: " << pInicio->id <<endl;
            cout << "Dueno: " << pInicio->nameOwers <<endl;
            cout << "Raza: " << pInicio->race <<endl;
            cout << "Peso: " << pInicio->weight <<endl;
            cout << "Edad: " << pInicio->age <<endl;
            cout << "----------------------" <<endl;
        } 
        else {
            while (s->sig && s->sig->id != dato)
                s = s->sig;
                if (!s->sig)
                {
                    cout << "No encontre el registro" <<endl;
                } else {
                    p = p->sig;
                    s->sig = s->sig->sig;
                    cout << "----------------------" <<endl;
                    cout << "ID: " << s->id <<endl;
                    cout << "Dueno: " << s->nameOwers <<endl;
                    cout << "Raza: " << s->race <<endl;
                    cout << "Peso: " << s->weight <<endl;
                    cout << "Edad: " << s->age <<endl;
                    cout << "----------------------" <<endl;
                }
        }
    }
}




int main(void)
{
    bool continuar = true;
    int opcion = 0;
    ListaCircSimple objListaCircSimple;
    cout << endl;
    cout << "ADMINISTRACIÓN DE VETERINARIA" << endl << endl;
    do{
        cout << "1) Agregar una nueva mascota." << endl;
        cout << "2) Mostrar una mascota." << endl;
        cout << "3) Borrar una mascota." << endl;
        cout << "4) Salir." << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            objListaCircSimple.insertaNodo();
            cout << "Se a registrado la mascota con exito!" <<endl;
            break;
        case 2:
            objListaCircSimple.searchRegistro();
            break;
        case 3:
            objListaCircSimple.eliRegistro();
            break;
        case 4:
            continuar = false;
            break;        
        default:
            cout << "La opcion no es valida, favor intente denuevo." << endl;
            break;
        }
    } while (continuar);
     

    return 0;
}






