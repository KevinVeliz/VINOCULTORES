#include <iostream>
#include <fstream>
using namespace std;

void calculos(int,char,double,float);
int menu(int);
void escribir();
void leer();


int main() 
{
  int tam;
  char tip;
  float kil,pre;
  int op,x;
   do{
   switch (menu(op))
   {
    case 1:
    escribir();
    system("read -p 'Presiona Enter para continuar...' var"); 
    break;
    case 2:
    leer();
    system("read -p 'Presiona Enter para continuar...' var"); 
    break;
    case 3:
    cout<<"------GRACIAS-----\n";
      x=3;
      system("read -p 'Presiona Enter para continuar...' var"); 
    break;
   }
system("clear");
  }while(x !=3);
}

int menu(int op)
{
  op= -1;
  while((op< 0) || (op>3)) 
  {
    cout<<"***************************"<<endl;
    cout<<"*  1- INGRESAR DATOS      *" << endl;
    cout<<"*  2- LEER DATOS          *" << endl;
    cout<<"*  3- SALIR               *" << endl;
    cout<<"***************************"<<endl;
    cout<<"Digite la opción: ";
    cin>>op;
    if((op< 0) || (op> 3)) 
    {
      cout << "Opción no válida" << endl;
    }
  }
  return op;
}

void escribir()
{
  ofstream archivo;
  string nombreArchivo;
  string tip;
  char r; 
  int e;
  double ga,pre,precio;
  int tam;
  float kil;

    cout<<"INGRESA EL NOMBRE DEL ARCHIVO: ";
    cin.ignore();
    getline(cin,nombreArchivo);
    archivo.open(nombreArchivo.c_str(),ios::app);
      do
    {
    cout<<"Ingresar tipo de uva: ";
    getline(cin,tip,'\n');
    if (tip=="A" || tip=="B")
    {
        cout<<"Ingresar tamaño de la uva: ";
    cin>>tam;
    cout<<"Ingresar precio de la uva: ";
    cin>>pre;
    cout<<"Ingresar kilo de uva: ";
    cin>>kil;
      if(tip == "A")
    {

      if(tam == 1)
      {
        precio=pre+0.20;
            ga = precio*kil;
      cout<<"La ganancia es: "<<ga<<endl;
      }
      else 
      {
        precio = pre+0.30;
            ga = precio*kil;
      cout<<"La ganancia es: "<<ga<<endl;
      }
    }
  else if(tip == "B")
  {
    if(tam == 1)
    {
      precio=pre-0.20;
          ga = precio*kil;
    cout<<"La pérdida es: "<<ga<<endl;
    }
    else 
    {
      precio = pre-0.30;
          ga = precio*kil;
    cout<<"La pérdida es: "<<ga<<endl;
    }
  } 

    }
    else 
    {
      cout<<"ERROR DATOS INCORRECTOS"<<endl;
    }

    archivo<<tip<<" "<<tam<<" "<<pre<<" "<<kil<<" "<<ga<<"\n";
    cout<<"DESEA AGREGAR OTRO DATO s/n: ";
    cin>>r;
    cin.ignore();
}while(r=='s');

  archivo.close();
}

void leer()
{
    ifstream archivoLectura ("uvas.txt");
    string texto;
    string tip;
    float ga;
    double pre;
    int tam;
    float kil;
     int e;
        while(!archivoLectura.eof())
        {
            archivoLectura>>tip>>tam>>pre>>kil>>ga;
            if (!archivoLectura.fail())
                {
                    cout<<"**********************"<<endl;
                    cout<<"El tipo es :          "<<tip<<endl;
                    cout<<"El tamaño es :        "<<tam<<endl;
                    cout<<"El precio es :        "<<pre<<endl;
                    cout<<"Los kilos son :       "<<kil<<endl;
                    cout<<"La ganancia es :      "<<ga<<endl;
                    cout<<"**********************"<<endl;
                }
        }
    archivoLectura.close();
}
