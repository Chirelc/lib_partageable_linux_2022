#include <iostream>
#include <dlfcn.h>	
//#include "Composant1.h"
//#include "Composant2.h"
typedef int(* FUNC_ADD)(int, int); // define alias of function pointer
typedef char*(*FUNC_ADD2)();
int main(int argc, char ** argv)
{
void *handle = dlopen( "../lib/libComposant1.so", RTLD_LAZY);
void *handle2=dlopen("../lib/libComposant2.so",RTLD_LAZY);

if (!handle) {
std::cerr << "dlopen1 : " << dlerror() << std::endl;
exit(EXIT_FAILURE);
}
if (!handle2) {
std::cerr << "dlopen2 : " << dlerror() << std::endl;
exit(EXIT_FAILURE);
}

FUNC_ADD composant1=(FUNC_ADD)dlsym( handle, "composant1" );
FUNC_ADD2 getComposant1Version=(FUNC_ADD2)dlsym( handle, "getComposant1Version" );
FUNC_ADD composant2=(FUNC_ADD)dlsym(handle2,"composant2");
if (!composant1){
	std::cerr << "dlsym : " << dlerror() << std::endl;
	std::cout<<"ERREUR composant1"<<std::endl;
	exit(EXIT_FAILURE);
}
if (!composant2){
	std::cerr << "dlsym : " << dlerror() << std::endl;
	std::cout<<"ERREUR composant2"<<std::endl;
	exit(EXIT_FAILURE);
}

int data1=3;
int data2=5;
int valeur1;
int valeur2;
valeur1=composant1(data1,data2);
valeur2=composant2(data1,data2);
valeur2=6;
std::cout << getComposant1Version() << std::endl;
std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;
dlclose(handle);
exit(EXIT_SUCCESS);
}

