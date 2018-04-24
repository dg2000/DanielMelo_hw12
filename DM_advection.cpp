#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;


int main()
{
  //Defino las constantes del problema
  double c = 1.0;

  double ht = 0.001;

  double hx = 0.001;

  double L = 4.0;

  int nx = int(L/hx);;

  int nt = 700;

  //Declaro los arreglos que guardan los snapchots

  double* nuevo = new double[nx];

  double* viejo = new double[nx];

  double* original = new double[nx];
  
  double* segundo = new double[nx];

  double* tercero = new double[nx];
   
  double* cuarto = new double[nx];
  

  //Inicializo la funcion inicial
   for (int i=0; i < nx; i++)
    {

      if (pow( (i*hx-2.0)*(i*hx-2.0)  , 0.5)  > 0.5)
	{
	  viejo[i] = 0.0;
	  original[i] = 0.0;
	}

      else
	{
	  
	  viejo[i] = 0.5;
	  original[i] = 0.5;
	}
    }


   for (int t = 0; t < nt; t++)
     {
       for ( int i = 1; i < nx-1; i++)
	 {
	   //Aplico la ecuacion de Backward diffenrence
	   nuevo[i] = viejo[i] - c*ht*( viejo[i]-viejo[i-1] )/hx;
	 }
     
       //Reinicio el algoritmo
       for (int i = 0; i < nx; i++)
	 {
	   viejo[i] = nuevo[i];
	 }
       //incializo un snapchot en cada caso
       if ( pow(t*t, 0.5) - nt/4.0  < 0.01)
	 {
	   for (int i = 0; i < nx; i++)
	     {
	       segundo[i] = viejo[i];
	     }
	   
	 }
       else if ( pow(t*t, 0.5) - 2.0*nt/4.0  < 0.01)
	 {
	   for (int i = 0; i < nx; i++)
	     {
	       tercero[i] = viejo[i];
	     }

	 }
       else if ( pow(t*t, 0.5) - 3.0*nt/4.0  < 0.01)
	 {
	   for (int i = 0; i < nx; i++)
	     { 
	       cuarto[i] = viejo[i];
	     }
	 }
       
     }
   
       
   //Envio los datos  a la pantalla
   for (int i = 0; i < nx; i++)
     {
       cout << i*hx-2.0 << " " << original[i] << " " << segundo[i] << " " << tercero[i] << " " << cuarto[i] << " " << nuevo[i] <<  endl;
     }

   return 0;
}
