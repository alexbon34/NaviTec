/////////////////////////////////////////////////// SEGUNDO PROYECTO PROGRAMADO ///////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>  
#include <stdlib.h>  
#include "Estructuras.h"

//////////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
///////////////////////////////////////////////// FUNCION PRINCIPAL DEL PROGRAMA \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//////////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

int main(){
	FILE *archivoTXT;   //Se crea fichero para la carga y guardado de datos
	
	ABB *arbol;    ///////// Se crea el árbol /////////
	arbol=nuevoABB();   //Se inicializa
	
	ListaNi *ListaSimpleNinxs;    ////// Se crea la lista simple de los ninxs \\\\\\\*
	ListaSimpleNinxs = listaSimpleNuevaNinxs();
	
	ListaABC *ListaAbc;
	ListaAbc=listaSimpleNuevaABC();
	
	NodoLNinxs *NN;     /////////// Se crean los punteros de nodos temporales \\\\\\\\\\\\\*
	NodoLNinxs *NNAnt;
	NodoAbc *NAbc;
	NodoABB *NABB;
	NodoABB *NABBAnt;
	
	Ninx N;
	Juguete J;
	int opcion;      /////////// Se crean las variables temporales \\\\\\\\\\\\\*
	int id;
	char nombre[30]; 
	
	insertarDatoABCListaSimple(ListaAbc,"a");
	insertarDatoABCListaSimple(ListaAbc,"b");
	insertarDatoABCListaSimple(ListaAbc,"c");
	insertarDatoABCListaSimple(ListaAbc,"d");
	insertarDatoABCListaSimple(ListaAbc,"e");
	insertarDatoABCListaSimple(ListaAbc,"f");
	insertarDatoABCListaSimple(ListaAbc,"g");
	insertarDatoABCListaSimple(ListaAbc,"h");
	insertarDatoABCListaSimple(ListaAbc,"i");
	insertarDatoABCListaSimple(ListaAbc,"j");
	insertarDatoABCListaSimple(ListaAbc,"k");
	insertarDatoABCListaSimple(ListaAbc,"l");    /////////// Se agrega el abecedario a una lista \\\\\\\\\\\\\*
	insertarDatoABCListaSimple(ListaAbc,"m");
	insertarDatoABCListaSimple(ListaAbc,"n");
	insertarDatoABCListaSimple(ListaAbc,"o");
	insertarDatoABCListaSimple(ListaAbc,"p");
	insertarDatoABCListaSimple(ListaAbc,"q");
	insertarDatoABCListaSimple(ListaAbc,"r");
	insertarDatoABCListaSimple(ListaAbc,"s");
	insertarDatoABCListaSimple(ListaAbc,"t");
	insertarDatoABCListaSimple(ListaAbc,"u");
	insertarDatoABCListaSimple(ListaAbc,"v");
	insertarDatoABCListaSimple(ListaAbc,"w");
	insertarDatoABCListaSimple(ListaAbc,"x");
	insertarDatoABCListaSimple(ListaAbc,"y");
	insertarDatoABCListaSimple(ListaAbc,"z");
	
	do{
		printf("_____________________                _____________________\n");
		printf("_____________________ MENU PRINCIPAL _____________________\n\n");
		printf("1) Seccion de Ninos y Ninas \n2) Seccion de Ayudantes \n3) Seccion de Juguetes \n4) Seccion de Lugares de domicilio \n5) Seccion de Cartas para santa \n6) Entrega de juguetes \n7) Analisis de datos \n8) Salir del sistema\n");
		printf("----Elija alguna de las opciones anteriores: ");
		scanf("%i",&opcion);
		switch(opcion){
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\*
			case 1:               /*Sección de Ninxs*/ 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 				printf("Ha elegido la opcion %i [Seccion de Ninos y Ninas]\n\n",opcion);
				printf("1) -Registrar Nino o Nina\n2) -Eliminar Nino o Nina\n3) -Modificar Nino o Nina\n");
				printf("----Elija alguna de las opciones anteriores: ");
				scanf("%i",&opcion);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////				
													//Si se quiere registrar un ninx
				if(opcion==1){     
					printf("\nIngrese nombre: ");  //Se ingresa el nombre del miembro
					fflush(stdin);
					scanf("%[^\n]s", &N.nombre);					
					printf("\nIngrese la identificacion: ");  //Se ingresa la cedula del miembro
					fflush(stdin);
					scanf("%d", &N.ID);								
					printf("\nIngrese el nombre de usuario: ");     //Se ingresa el correo del miembro
					fflush(stdin);
					scanf("%[^\n]s",&N.nombreUsuario);
					printf("\nIngrese la edad: ");     //Se ingresa el numero telefonico del miembro
					fflush(stdin);
					scanf("%d",&N.edad);		  
					printf("\nIngrese el lugar de residencia: ");         //Se ingresa el nivel de acceso del miembro
					fflush(stdin);
					scanf("%[^\n]s",&N.residencia);
					printf("\nIngrese el correo electronico: ");         //Se ingresa el nivel de acceso del miembro
					fflush(stdin);
					scanf("%[^\n]s",&N.correo);		
					printf("\nIngrese la fecha de nacimiento: ");         //Se ingresa el nivel de acceso del miembro
					fflush(stdin);
					scanf("%[^\n]s",&N.nacimiento);
					printf("\nIngrese las necesidades especiales (en caso de tener): ");         //Se ingresa el nivel de acceso del miembro
					fflush(stdin);
					scanf("%[^\n]s",&N.nececidadesEspeciales);
						
					insertarDatoNinxsListaSimple(ListaSimpleNinxs, N);  //Se ingresa el miembro a la lista
					printf("\n\n°°°°°°°°°°°°Se registro el Nino o Nina con exito°°°°°°°°°°°°\n\n");	
					printf("La cantidad de Ninos y Ninas en el sistema es: %d\n",cantidadElementosNinxs(ListaSimpleNinxs));	
					system("PAUSE");
				}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			                                               	//Si se quiere eliminar un ninx
				else if(opcion==2){
					NN=ListaSimpleNinxs->inicio;
					NNAnt=ListaSimpleNinxs->inicio;
					printf("Ingrese la identificacion del nino o nina que desea eliminar: \n");
					fflush(stdin);
					scanf("%d",&id);
					if(NN==NULL){                 //Valida si la lista de ninxs esta vacia
						printf("La lista de ninos y ninas esta vacia\n");
						system("PAUSE");
						break;
					}
					printf("\n");
					for(NN=ListaSimpleNinxs->inicio;NN!=NULL;NN=NN->siguiente){    //ciclo para volidar que el niño este en la lista
	 					if(NN->siguiente==NULL){
	 						if(NN->dato.ID!=id){
	 							printf("El Nino o Nina que desea eliminar no se encuentra en el sistema!!\n");
								system("PAUSE");
								break;
								break;
							}
	 					}
	 				}
					if(ListaSimpleNinxs->inicio->dato.ID==id){
						ListaSimpleNinxs->inicio=ListaSimpleNinxs->inicio->siguiente;
						printf("\n°°°°°°°°°°°°Se elimino el Nino o Nina con exito°°°°°°°°°°°°\n\n");
						system("PAUSE");
						break;
					}				
					for(NN=ListaSimpleNinxs->inicio;NN!=NULL;NN=NN->siguiente){    //ciclo para recorrer la lista
	 					if(NN->dato.ID==id){          //Se detecta el ninx con el id
	 						NNAnt->siguiente=NN->siguiente;
	 						NN=NULL;
	 						printf("\n\n°°°°°°°°°°°°Se elimino el Nino o Nina con exito°°°°°°°°°°°°\n\n");
							system("PAUSE");
							break;
						}
						NNAnt=NN;
					}					
				}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			                                           	//Si se quiere modificar la info de un ninx
				else if(opcion==3){
					NN=ListaSimpleNinxs->inicio;
					printf("Ingrese la identificacion del nino o nina que desea modificar: \n");
					fflush(stdin);
					scanf("%d",&id);
					if(NN==NULL){                 //Valida si la lista de ninxs esta vacia
						printf("La lista de ninos y ninas esta vacia\n");
						system("PAUSE");
						break;
					}
					printf("\n");
					for(NN=ListaSimpleNinxs->inicio;NN!=NULL;NN=NN->siguiente){    //ciclo para volidar que el niño este en la lista
	 					if(NN->siguiente==NULL){
	 						if(NN->dato.ID!=id){
	 							printf("El Nino o Nina que desea modificar no se encuentra en el sistema!!\n");
								system("PAUSE");
								break;
								break;
							}
	 					}
	 				}
					for(NN=ListaSimpleNinxs->inicio;NN!=NULL;NN=NN->siguiente){    //ciclo para recorrer la lista
	 					if(NN->dato.ID==id){          //Se detecta el ninx con el id
	 						printf("La informacion del nino/nina a modificar es la siguiente:\n");  //e imprimir los datos.
						 	printf("Identificacion: %d\n",NN->dato.ID);                              
							printf("Nombre: %s\n",NN->dato.nombre);
							printf("Nombre de Usuario: %s\n",NN->dato.nombreUsuario);
							printf("Lugar de residencia: %s\n",NN->dato.residencia);
							printf("Correo electronico: %s\n",NN->dato.correo);	
							printf("Fecha de nacimiento: %s\n",NN->dato.nacimiento);
							printf("Edad: %d\n",NN->dato.edad);
							printf("Necesidades especiales: %s\n",NN->dato.nececidadesEspeciales);
							break;
							
						}
					}
					printf("\nIngrese el nombre de usuario: ");
					fflush(stdin);
					scanf("%[^\n]s",&NN->dato.nombreUsuario);           //Se cambia el nombre de usuario
					printf("\nIngrese la identificacion: ");
					fflush(stdin);
					scanf("%d",&NN->dato.ID);           //Se cambia el id 
					printf("\nIngrese el nombre: ");
					fflush(stdin);
					scanf("%[^\n]s",&NN->dato.nombre);           //Se cambia el nombre 
					printf("\nIngrese el lugar de residencia: ");
					fflush(stdin);
					scanf("%[^\n]s",&NN->dato.residencia);           //Se cambia la residencia
					printf("\nIngrese el correo electronico: ");
					fflush(stdin);
					scanf("%[^\n]s",&NN->dato.correo);           //Se cambia el correo
					printf("\nIngrese la fecha de nacimiento: ");
					fflush(stdin);
					scanf("%[^\n]s",&NN->dato.nacimiento);           //Se cambia la fecha de nacimkiento
					printf("\nIngrese la edad: ");
					fflush(stdin);
					scanf("%d",&NN->dato.edad);           //Se cambia la edad
					printf("\nIngrese las necesidades especiales del nino/nina: ");
					fflush(stdin);
					scanf("%[^\n]s",&NN->dato.nececidadesEspeciales);           //Se cambian las necesidades especiales
					
					printf("\nLa informacion del nino/nina modificado es la siguiente: \n");   //Se imprime la info del ninx modificado
					printf("Nombre de usuario: %s\n",NN->dato.nombreUsuario);                              
					printf("Identificacion: %d\n",NN->dato.ID);
					printf("Nombre: %s\n",NN->dato.nombre);
					printf("Lugar de residencia: %s\n",NN->dato.residencia);
					printf("Correo electronico: %s\n",NN->dato.correo);	
					printf("Fecha de nacimiento: %s\n",NN->dato.nacimiento);
					printf("Edad: %d\n",NN->dato.edad);
					printf("Necesidades especiales: %s\n",NN->dato.nececidadesEspeciales);
					printf("\n\n°°°°°°°°°°°°Se modifico el nino/nina con exito°°°°°°°°°°°°\n\n");	
					system("PAUSE");
					break;
				}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			                                //Valida que el usuario ingrese la opcion correcta
				else{                  
					printf("La opcion ingresada es incorrecta!\n");
					system("PAUSE");
					break;
				}
			break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\*
			case 2:               /*Sección Ayudantes*/                
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
				printf("Ha elegido la opcion %i [Seccion de ]\n\n",opcion);
				printf("1) -Registrar \n2) -Eliminar \n3) -Modificar \n");
				printf("----Elija alguna de las opciones anteriores: ");
				scanf("%i",&opcion);
				system("PAUSE");
			break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\*
			case 3:               /*Sección Juguetes*/                     
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
	 			printf("Ha elegido la opcion %i [Seccion de Juguetes]\n\n",opcion);
				printf("1) -Registrar Juguete\n2) -Eliminar Juguete\n3) -Modificar Juguete\n");
				printf("----Elija alguna de las opciones anteriores: ");
				scanf("%i",&opcion);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////				
													//Si se quiere registrar un juguete
				if(opcion==1){     
					printf("\nIngrese nombre: ");  //Se ingresa el nombre del miembro
					fflush(stdin);
					scanf("%[^\n]s", &J.nombre);					
					/*printf("\nIngrese el codigo del juguete: ");  //Se ingresa la cedula del miembro
					fflush(stdin);
					scanf("%d", &J.codigo);								
					printf("\nIngrese la descripcion: ");     //Se ingresa el correo del miembro
					fflush(stdin);
					scanf("%[^\n]s",&J.descripcion);
					printf("\nIngrese el rango de edad: ");     //Se ingresa el numero telefonico del miembro
					fflush(stdin);
					scanf("%[^\n]s",&J.rangoEdad);		  
					printf("\nIngrese el costo total: ");         //Se ingresa el nivel de acceso del miembro
					fflush(stdin);
					scanf("%d",&J.costo);
					printf("\nIngrese la categoria del juguete: ");         //Se ingresa el nivel de acceso del miembro
					fflush(stdin);
					scanf("%[^\n]s",&J.categoria);*/
					
					insertarJuguete(arbol,J,ListaAbc);      //Se inserta el juguete al ABB	
					printf("\nJuguete en la raiz del arbol: %s\n",arbol->raiz->info.nombre);
					printf("Recorrido en orden del arbol:\n");
					imprimirEnOrden(arbol->raiz);
					printf("\n\n°°°°°°°°°°°°Se registro el juguete con exito°°°°°°°°°°°°\n\n");		
					system("PAUSE");
					break;
				}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			                                               	//Si se quiere eliminar un juguete
				else if(opcion==2){
					NABB=arbol->raiz;
					if(arbol->raiz==NULL){     //Valida si la lista de juguetes esta vacia
						printf("El ABB de los juguetes esta vacio\n");
						system("PAUSE");
						break;
					}
					printf("\n");
					eliminarJuguete(arbol, ListaAbc);
					printf("Recorrido en orden del arbol:\n");
					imprimirEnOrden(arbol->raiz);
					printf("\n\n°°°°°°°°°°°°Se elimino el juguete con exito°°°°°°°°°°°°\n\n");		
					system("PAUSE");
					break;
				}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		 	                                    	//Si se quiere modificar la info de un juguete
				else if(opcion==3){
					printf("Ingrese la nombre del juguete que desea modificar: \n");
					fflush(stdin);  
					scanf("%[^\n]s",&nombre);  
					if(arbol->raiz==NULL){                 //Valida si la lista de juguetes esta vacia
						printf("El ABB de los juguetes se encuentra vacio\n");
						system("PAUSE");
						break;
					}
					printf("\n");
					NABB=buscarImprimir(arbol->raiz,nombre);    //Funcion para recorrer el ABB, encontrar el juguete,							
					printf("\nIngrese el nombre: ");            //y obtener el nodo en el cual se van hacer los cambios
					fflush(stdin);
					scanf("%[^\n]s",&NABB->info.nombre);           //Se cambia el nombre
					printf("\nIngrese el costo: ");
					fflush(stdin);
					scanf("%d",&NABB->info.costo);           //Se cambia el costo total
					printf("\nIngrese la categoria del juguete: ");
					fflush(stdin);
					scanf("%[^\n]s",&NABB->info.categoria);           //Se cambia la categoria
					printf("\nIngrese el lugar de residencia: ");
					fflush(stdin);
					scanf("%[^\n]s",&NABB->info.descripcion);           //Se cambia la descripcion
					printf("\nIngrese el rango de edad: ");
					fflush(stdin);
					scanf("%[^\n]s",&NABB->info.rangoEdad);           //Se cambia el rango de edad
					printf("\nIngrese el codigo: ");
					fflush(stdin);
					scanf("%d",&NABB->info.codigo);           //Se cambia la fecha de nacimiento
					printf("\nIngrese el rango de edad: ");
					fflush(stdin);
					scanf("%d",&NABB->info.rangoEdad);           //Se cambia la edad
					
					printf("\nLa informacion del juguete modificado es la siguiente: \n");   //Se imprime la info del ninx modificado
					printf("Nombre: %s\n",NABB->info.nombre);
					printf("Codigo: %d\n",NABB->info.codigo);
					printf("Costo: %d\n",NABB->info.costo);
					printf("Categoria: %s\n",NABB->info.categoria);
					printf("Rango Edad: %s\n",NABB->info.rangoEdad);
					printf("Descripcion: %s\n",NABB->info.descripcion);
					printf("\n\n°°°°°°°°°°°°Se modifico el juguete con exito°°°°°°°°°°°°\n\n");
					system("PAUSE");
					break;
				}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			                                //Valida que el usuario ingrese la opcion correcta
				else{                  
					printf("La opcion ingresada es incorrecta!\n");
					system("PAUSE");
					break;
				}			
			break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\*
			case 4:               /*Sección Lugares de domicilio*/                     
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
				printf("\n\n");
				

				system("PAUSE");
			break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\*
			case 5:               /*Sección Cartas para Santa*/                     
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
			
				system("PAUSE"); 
			break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\*
			case 6:               /*Sección Entrega de juguete*/                     
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
				system("PAUSE");
			break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 7:               /*Sección de analisis de datos*/                     
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
				system("PAUSE");
			break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\*
			case 8:               /*Función Salir del sistema*/                     
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
			break;
			
			default:           //Valida que la opcion ingresada sea la correcta
				printf("\n\t\tOPCION INCORRECTA!\nDebe escoger una opcion entre el 1 y el 8\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
			break;
			}
	}while(opcion!=8);
}

