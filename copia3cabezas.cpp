#include<iostream>
#include<string.h>

using namespace std;
struct snodo {
	char* nom;
	snodo* sig1;
	char* apellido1;
	snodo* sig2;
	char* apellido2;
	snodo* sig3;


};

struct lista {

	snodo* cabeza1;
	snodo* cabeza2;
	snodo* cabeza3;
	int tam;
};
lista* crearlista() {
	lista* lista1 = new lista;

	lista1->cabeza1 = NULL;
	lista1->cabeza2 = NULL;
	lista1->cabeza3 = NULL;
	lista1->tam = 0;




}
bool listavacia(lista* lista) {

	if (lista->tam == 0) {
		return true;
	}
	else {
		return false;
	}



}
snodo* crearnodo() {
	snodo* nodo = new snodo; //direccion
	nodo->nom = new char[100];
	nodo->apellido1 = new char[100];
	nodo->apellido2 = new char[100];
	cout << "nombre: ";
	cin >> nodo->nom;
/*	cout << "apellido1: ";
	cin >> nodo->apellido1;

	cout << "apellido2: ";
	cin >> nodo->apellido2;*/
	nodo->sig1 = NULL;
	nodo->sig2 = NULL;
	nodo->sig3 = NULL;
	return nodo;

}
void insertarnodo(lista* lista1) {
	snodo* nodo = crearnodo();
	snodo* aux = lista1->cabeza1;
	int t = 0;
	bool es = false;
	if (listavacia(lista1) == true) {
		lista1->cabeza1 = nodo;
		lista1->cabeza2 = nodo;
		lista1->cabeza3 = nodo;

	}

	else {
		while (t < lista1->tam) {
			if (aux->sig1 == NULL) {
				aux->sig1 = nodo;

			}
			aux = aux->sig1;
			t++;
		}
		

	}










	lista1->tam++;
}





void imprimirnodo(lista* lista1) {
	snodo* auxi = lista1->cabeza1;
	snodo* auxi2 = lista1->cabeza2;
	snodo* auxi3 = lista1->cabeza3;

	while (auxi != NULL) {

		cout << auxi->nom << endl;


		auxi = auxi->sig1;
	}






}

void ordenarnodo(lista*&lista1) {
snodo*auxi1,*auxi2,*auxi3,*auxi4;
auxi1=lista1->cabeza1; 
auxi2=lista1->cabeza1->sig1;
int t=1;

while(auxi1->sig1!=NULL){  
	
	while(auxi2->sig1!=NULL){
		
	   if(strcmp(auxi1->nom,auxi2->nom)>0){
	   	    
	   	  	auxi3=auxi1;
	   	  	cout<<"nombre auxi3"<<auxi3->nom<<endl;
	   	    auxi1=auxi2;
	   	    cout<<"nombre auxi1"<<auxi1->nom<<endl;
	   	    auxi4=auxi2->sig1;
	   	    cout<<"nombre auxi4"<<auxi4->nom<<endl;
	   	    auxi3->sig1=auxi4;
	   	    cout<<"nombre auxi3 sig"<<auxi3->sig1->nom<<endl;
	   	    auxi1->sig1=auxi3;
	   	     cout<<"nombre auxi1 sig"<<auxi1->sig1->nom<<endl;
	   	
	   }
	   if(t==1){
	   
	  lista1->cabeza1=auxi1;
	   
	}
	 auxi2=auxi2->sig1;
    }
	 t=2;
	
	
 auxi1=auxi1->sig1;	
}








}


int main() {

	lista* lista1 = crearlista();
	int tam = 2;

	for (int i = 0; i < 3; i++) {
		insertarnodo(lista1);

	}
	cout<<endl;
	cout<<"<<imprimiendo>>"<<endl;
	imprimirnodo(lista1);
	ordenarnodo(lista1);
	cout<<"ordenada "<<endl;
	cout<<endl;
	imprimirnodo(lista1);
	return 0;
}
