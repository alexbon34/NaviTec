#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// LISTA SIMPLE DEL ABECEDARIO ///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ListaABC ListaABC;
typedef struct NodoAbc NodoAbc;

struct NodoAbc{
	char letra[2];
	NodoAbc *siguiente;
};

struct ListaABC{
	NodoAbc *inicio;
};

ListaABC *listaSimpleNuevaABC(void){
	ListaABC *L;
	L = (ListaABC *) malloc(sizeof(ListaABC));
	L->inicio = NULL;
	return L;
}

void insertarDatoABCListaSimple(ListaABC *L,char letra[2]){
	NodoAbc *n, *aux;
	if(L->inicio == NULL){ //Valida si la lista está vacía
		//Inserta al inicio de la lista
		L->inicio = (NodoAbc *) malloc(sizeof(NodoAbc));
		strcpy(L->inicio->letra,letra);
		L->inicio->siguiente = NULL;
		return;
	}
	n = L->inicio;
	while(n!= NULL){
		aux = n;
		n = n->siguiente;		
	}
	aux->siguiente = (NodoAbc *) malloc(sizeof(NodoAbc));
	aux->siguiente->siguiente = NULL;
	strcpy(aux->siguiente->letra,letra);
}

int posicion(ListaABC *L,char letra[2]){
	NodoAbc *aux;
	int contador=0;
	for(aux=L->inicio;aux!=NULL;aux=aux->siguiente){
		if(strcmp(aux->letra,letra)==0){
			contador++;
			return contador;
		}
		else{
			contador++;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// ABB DE LOS JUGUETES ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct NodoABB NodoABB;
typedef struct ABB ABB;
typedef struct Juguete Juguete;

struct Juguete{      //Estructura del Juguete.
	int codigo;
	int costo;
	char nombre[30];
	char descripcion[50];
	char categoria[30];
	char rangoEdad[30];
};

struct NodoABB{    //Estructura de los nodos del arbol
    Juguete info;
    struct NodoABB *izq;
    struct NodoABB *der;
};

struct ABB{         //Estructura del arbol
	NodoABB *raiz; 
};

ABB *nuevoABB(void){       //Funcion para inicializar el arbol
	ABB *arbol;
	arbol = (ABB *) malloc(sizeof(ABB));
	arbol->raiz = NULL;
	return arbol;
}

NodoABB *crearNodoABB(Juguete info){         //Funcion para crear un nuevo nodo
	NodoABB *nodo=(NodoABB *) malloc(sizeof(NodoABB));
	nodo->info=info;
	nodo->der=NULL;
	nodo->izq=NULL;
	return nodo;
}

void insertarJuguete(ABB *Arbol, Juguete info, ListaABC *LAbc){      //Funcion para insertar juguetes en el arbol
    int PosActual;
    int PosNueva;
    int cont;    
    char nombre[30];
    char letraActual[2];
    char letraNueva[2];
    
	NodoABB *nodoActual, *anterior;
	   
    if (Arbol->raiz==NULL){
    	Arbol->raiz=crearNodoABB(info);
        printf("El juguete se registro en la raiz del arbol.\n");
	}  
	else{
        anterior = NULL;
        nodoActual=Arbol->raiz;
        
        strcpy(nombre,info.nombre);        
        cont=1;
        while(cont<29){
        	nombre[cont]=00;
        	cont++;
		}             
        strcpy(letraNueva,nombre);
        
        while (nodoActual != NULL){
            anterior = nodoActual;
                       
            strcpy(nombre,nodoActual->info.nombre);
            
            cont=1;
        	while(cont<29){
        		nombre[cont]=00;
        		cont++;
			}
        	printf("letra del nombre del nodo actual: %s\n",nombre);
        	
            strcpy(letraActual,nombre);
            printf("Antes de comparar.\nContenido de letraActual: %s\n",letraActual);
            printf("Contenido de letraNueva: %s\n\n",letraNueva);
            
            PosActual=posicion(LAbc,letraActual);     ////Aqui se sacan las posiciones de cada letra en el abecedario
            PosNueva=posicion(LAbc,letraNueva);
           
		    if (PosNueva<PosActual)
                nodoActual = nodoActual->izq;       ////Aqui nos vamos moviendo en el arbol
            else
                nodoActual = nodoActual->der;                               
        }
        if (PosNueva<PosActual){
        	anterior->izq=crearNodoABB(info);      //Se inserta el juguete
        	printf("El juguete se inserto en el hijo izquierdo del juguete: %s",anterior->info.nombre);
        }
        else{
        	anterior->der=crearNodoABB(info);      //Se inserta el juguete
        	printf("El juguete se inserto en el hijo derecho del juguete: %s",anterior->info.nombre);
    	}
    }
}


void imprimirEnOrden(NodoABB *recorrer){    //Funcion para imprimir el arbol
	if (recorrer != NULL){
        imprimirEnOrden(recorrer->izq);
        printf("-%s\n",recorrer->info.nombre);
        imprimirEnOrden(recorrer->der);
    }
}

NodoABB *buscarImprimir(NodoABB *recorrer, char nombre[30]){ //Funcion para buscar un juguete e imprimir su informacion
	if (recorrer != NULL){                               //Esta funcion retorna un nodo para luego poder manipularlo
		if(strcmp(recorrer->info.nombre,nombre)==0){
			printf("Nombre: %s\n",recorrer->info.nombre);
			printf("Descripcion: %s\n",recorrer->info.descripcion);
			printf("Categoria: %s\n", recorrer->info.categoria);
			printf("Codigo: %d\n",recorrer->info.codigo);
			printf("Costo: %d\n",recorrer->info.costo);
			return recorrer;
		}
        buscarImprimir(recorrer->izq, nombre);
        buscarImprimir(recorrer->der, nombre);
    }
}

NodoABB *buscarImprimirEliminar(NodoABB *recorrer, NodoABB *padre, char nombre[30]){ //Funcion para buscar un juguete e imprimir su informacion
	if (recorrer != NULL){                               //Esta funcion retorna un nodo para luego poder manipularlo
		if(strcmp(recorrer->info.nombre,nombre)==0){
			printf("Nombre: %s\n",padre->info.nombre);
			printf("Descripcion: %s\n",padre->info.descripcion);
			printf("Categoria: %s\n", padre->info.categoria);
			printf("Codigo: %d\n",padre->info.codigo);
			printf("Costo: %d\n",padre->info.costo);
			return padre;
		}
        buscarImprimirEliminar(recorrer->izq, recorrer, nombre);
        buscarImprimirEliminar(recorrer->der, recorrer, nombre);
    }
}


int eliminarJuguete(ABB *Arbol, ListaABC *LAbc){
	char nombre[30];
    NodoABB *atrasi, *atrasd, *recorrer, *padre, *menor;
    
	printf("\n\nIngrese el nombre del juguete que desea eliminar: ");
	fflush(stdin);
	scanf("%[^\n]s",&nombre);
// SI ESTA EN LA RAIZ ///////////////////////////////////////////////////
	if(strcmp(Arbol->raiz->info.nombre,nombre)==0){ 
		recorrer=Arbol->raiz;
		menor=Arbol->raiz->der;
		if((recorrer->der==NULL) && (recorrer->izq==NULL)){      //Si la raiz es un nodo hoja  
			Arbol->raiz=NULL;    //La raiz se hace null
			return 0;
		}
		else if((menor->der==NULL)&&(menor->izq==NULL)){    ///Si la raiz solo tiene un hijo a la derecha
			printf("hola1\n");
			strcpy(recorrer->info.nombre, menor->info.nombre);      //Se intercambia el dato entre los nodos
			recorrer->der=NULL;
		    printf("Raiz: %s\n",Arbol->raiz->info.nombre);
			return 0;
		}
		else{
			while(menor->izq!=NULL){        //Aqui se busca el nodo menor en el subarbol derecho.
				menor=menor->izq;
			}
			recorrer->info=menor->info;    //Se intercambia el dato entre los nodos
			printf("Dato a intercambiar: %s",menor->info.nombre);
			printf("\nSe ha eliminado el dato. \n");
			printf("\nRecorrido enorden: \n");
		    imprimirEnOrden(Arbol->raiz);
		    printf("\n");
			return 0;
		}
	}  
	recorrer=buscarImprimir(Arbol->raiz, nombre);         /////Se encuentra el nodo a eliminar
	padre=buscarImprimirEliminar(Arbol->raiz, NULL, nombre);     ///Se encuentra el padre del nodo a eliminar
// SI NO TIENE HIJOS ////////////////////////////////////////////////*	
	if((recorrer->der==NULL) && (recorrer->izq==NULL)){       ///Aqui no quiere ingresar el sistema
		printf("padre: %s\n",padre->info.nombre);
		if(strcmp(padre->izq->info.nombre, nombre)==0){
			padre->izq=NULL;
			printf("\nRecorrido enorden: ");
		    imprimirEnOrden(Arbol->raiz);
		    printf("\n");
			return 0;
		}
		else{
			padre->der=NULL;
			printf("\nRecorrido enorden: ");
		    imprimirEnOrden(Arbol->raiz);
		    printf("\n");
			return 0;
		}
	}
// SI TIENE UN HIJO /////////////////////////////////////////////////*
	else if(((recorrer->der==NULL)&&(recorrer->izq!=NULL)) || ((recorrer->der!=NULL)&&(recorrer->izq==NULL))){ 
		if(strcmp(padre->izq->info.nombre,nombre)==0){   //Si estamos en el hijo izquierdo del anterior
			if(recorrer->der==NULL){       
				padre->izq=padre->izq->izq;
				return 0;
			}
			else{
				padre->izq=padre->der->der;
				return 0;
			}
		}
		else{                       //Si estamos en el hijo derecho del anterior
			if(recorrer->der==NULL){
				padre->der=padre->izq->izq;
				return 0;
			}
			else{
				padre->der=padre->der->der;
				return 0;
			}
		}
		printf("Se ha eliminado un dato");
		printf("\nRecorrido enorden: ");
	    imprimirEnOrden(Arbol->raiz);
	    printf("\n");
		return 0;
	}
	else{
// SI TIENE DOS HIJOS ////////////////////////////////////////////*  
		menor=recorrer->der;
		if((menor->der==NULL)&&(menor->izq==NULL)){    //Si el nodo derecho de recorrer es hoja
			printf("Dato a intercambiar: %s",menor->info.nombre);
			strcpy(recorrer->info.nombre, menor->info.nombre);
			recorrer->der=NULL;
			printf("\nSe ha eliminado un dato\n");
			printf("\nRecorrido enorden: ");
		    imprimirEnOrden(Arbol->raiz);
		    printf("\n");
			return 0;
		}
		while(menor->izq!=NULL){    //Se obtiene el dato menor de el subarbol derecho
			padre=menor;
			menor=menor->izq;
		}
		strcpy(recorrer->info.nombre, menor->info.nombre);
		padre->izq=NULL;
		printf("\nSe ha eliminado un dato\n");
		return 0;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// LISTA SIMPLE NINXS ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ListaNi ListaNi;
typedef struct NodoLNinxs NodoLNinxs;
typedef struct Ninx Ninx;

struct Ninx{     //Estructura del niño o niña.
	int ID;
	char nombre[30];
	char nombreUsuario[30];
	char residencia[30];
	char correo[30];
	char nacimiento[30];
	int edad;
	char nececidadesEspeciales[30];
};

struct NodoLNinxs{
	Ninx dato;
	NodoLNinxs *siguiente;
};

struct ListaNi{
	NodoLNinxs *inicio;
};

ListaNi *listaSimpleNuevaNinxs(void){
	ListaNi *L;
	L = (ListaNi *) malloc(sizeof(ListaNi));
	L->inicio = NULL;
	return L;
}

void insertarDatoNinxsListaSimple(ListaNi *L, struct Ninx dato){
	NodoLNinxs *n, *aux;
	if(L->inicio == NULL){ //Valida si la lista está vacía
		//Inserta al inicio de la lista
		L->inicio = (NodoLNinxs *) malloc(sizeof(NodoLNinxs));
		L->inicio->dato = dato;
		L->inicio->siguiente = NULL;
		return;
	}
	n = L->inicio;
	while(n!= NULL)
	{
		aux = n;
		n = n->siguiente;		
	}
	aux->siguiente = (NodoLNinxs *) malloc(sizeof(NodoLNinxs));
	aux->siguiente->siguiente = NULL;
	aux->siguiente->dato = dato;
}

int cantidadElementosNinxs(ListaNi *L){
	int cantidad=0;
	NodoLNinxs *i;
	for(i = L->inicio; i!= NULL; i = i->siguiente)
		cantidad+=1;
	return cantidad;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// GRAFO LUGARES DOMICILIO ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////













