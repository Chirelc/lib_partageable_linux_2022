#include <dlfcn.h>
#include <iostream>
//#include "Composant1.h"
#include "Composant2.h"

typedef int(* FUNC_ADD)(int, int); // define alias of function pointer
typedef char*(*FUNC_ADD2)();
//typedef int(*FUNC_ADD3)(int,int);
const char* dllPath = "./libComposant1.so";
//const char* dllPath2="/lib/libComposant2.so";

int main(int argc, char ** argv)
{
// Ouverture de la bibliothèque
 void *handle = dlopen(dllPath, RTLD_LAZY);
// void *handle2=dlopen(dllPath2,RTLD_LAZY);
 if( !handle )
	{
		std::cout<<"dlopen error"<<std::endl;
		exit( EXIT_FAILURE );
	}
/* if(!handle2){
	 std::cout<<"dlopen 2 error"<<std::endl;
		exit( EXIT_FAILURE );
	}*/
 // Chargement de la fonction "func"
 // for resource handle
FUNC_ADD composant1=(FUNC_ADD)dlsym( handle, "composant1" );
FUNC_ADD2 getComposant1Version=(FUNC_ADD2)dlsym( handle, "getComposant1Version" );
//FUNC_ADD3 composant2=(FUNC_ADD3)dlsym(handle2,"composant2");
	int data1=3;
	int data2=5;

	int valeur1;
	int valeur2;

	valeur1=composant1(data1,data2);
//	valeur2=composant2(data1,data2);
	valeur2=6;
	std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;

    // Fermeture de la bibliothèque
    dlclose(handle);
}
