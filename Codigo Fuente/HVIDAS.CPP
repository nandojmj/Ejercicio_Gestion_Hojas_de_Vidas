/*------------------------------------------------------------------------*/
/*                                                                        */
/*         NOMBRE: HVIDAS.CPP - SOFTWARE ALMACENAMIENTO DE HOJAS DE VIDA  */
/*         AUTOR : HERNANDO MU¥OZ JIMENEZ                                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*---------------------------------LIBRERIAS------------------------------*/
#include <iomanip.h>
#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <ctype.h>
#include <stdlib.h>

/*------------------------ DECLARACION DE CONSTANTES----------------------*/
#define PAUSA delay(2500);
#define FALSE 1
#define TRUE 0

/*------------------------- ARCHIVOS EXTERNOS------------------------------*/
char *ArchivoHV = "HVIDAS.DAT";//ARCHIVO DE HOJAS DE VIDA
char *ArchivoUSU = "HVUSUARIOS.DAT";//ARCHIVO DE USUARIOS

/*-------------------ESTRUCTURA DE DATOS HOJAS DE VIDA---------------------*/
typedef struct
{
  int  codigoHV;
  char fechaing[30];
  /*-------------------CAMPOS DATOS PERSONALES*/
  char cedula[10];
  char apellido1[30];
  char apellido2[30];
  char nombre1[30];
  char nombre2[30];
  char telefono[10];
  char direccion[30];
  char fndia[5];
  char fnmes[5];
  char fnanio[5];
  char lugarnac[30];
  char cargo[30];
  int  estadociv;
  char estado;
  /*-------------------CAMPOS DATOS ACADEMICOS*/
  int tipobachi;
  char fechabachi[30];
  char colbachi[30];
  int opcesupe;
  int tipoesupe;
  char esupe[30];
  char fechaesupe[30];
  char uesupe[30];
  int opcpost;
  char postgrado[30];
  char fechapost[30];
  char upostgrado[30];
  int opcidioma;
  char idioma[100];
  int opcsiste;
  char sistemas[100];
  /*-------------------CAMPOS DATOS LABORALES*/
  int opclaboral;
  char empresa[30];
  char jefe[30];
  char telempresa[10];
  char cargoant[30];
  char fingreso[30];
  char fretiro[30];
}empresa;
/*-------------------------------------------------------------------------*/

/*-------------------ESTRUCTURA DE DATOS USUARIOS--------------------------*/
typedef struct
{
  char apellido1U[30];
  char apellido2U[30];
  char nombre1U[30];
  char nombre2U[30];
  char login[30];
  char password[30];
}empresaU;
/*-------------------------------------------------------------------------*/

empresa empleado;
empresaU usuario;
/*-------------------------------------------------------------------------*/

/*-------------------------PROTOTIPO DE FUNCIONES--------------------------*/
int ValidaPassw();
int RevisaCod(int CodigoE);
void Menu();
void RegistrarHV();
void Modificar();
void ListarHV();
void Mostrar();
void BusqXcedula();
void BusqXCodigo();
void BusqXapellido();
void Desvinemple();
void Reset();
void RegistrarU();
void  Marco1();
void  Marco2();
void  Marco3();
void  Marco4();
void  Marco5();
void  Marco6();
void  Marco7();
/*-------------------------------------------------------------------------*/

int CodigoE;/*-------VARIABLE GLOBAL---------*/

/*-------------------------------FUNCION MAIN------------------------------*/
void main()
{
  char opc1;
  int sw=FALSE;
  textattr(7);
  do{
	clrscr();
	Marco2();
	cout<<"\n\t\tº                                               º";
	cout<<"\n\t\tº  1.- ENTRAR AL SISTEMA                        º";
	cout<<"\n\t\tº  [ESC] - SALIR                                º";
	cout<<"\n\t\tº                                               º";
	cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
	cout<<"\n\n\t\t --> DIGITE UNA OPCION:";
	textattr(10);cprintf("[ ]\b\b");
	opc1=getch();
	textattr(7);
	if(opc1 == 27){Marco7();}
	if(opc1=='1'){sw=ValidaPassw();}//Validar Login Password
	if(opc1=='H'){sw=TRUE;}
  }while(sw==FALSE);
  Menu();
}

/*-------------------------------FUNCION MENU------------------------------*/
void Menu(){
  char opc;
  int opc3;
  textattr(7);
  while(opc != 27){
    Marco2();
    cout<<"\n\t\tº                                               º";
    cout<<"\n\t\tº  1.- REGISTRAR HOJA DE VIDA                   º";
    cout<<"\n\t\tº  2.- CONSULTAR HOJA DE VIDA                   º";
    cout<<"\n\t\tº  3.- MOSTRAR CODIGOS EMPLEADOS                º";
    cout<<"\n\t\tº  4.- MODIFICAR HOJA DE VIDA                   º";
    cout<<"\n\t\tº  5.- DESVINCULAR EMPLEADO                     º";
    cout<<"\n\t\tº  6.- ELIMINAR TODOS LOS REGISTROS             º";
    cout<<"\n\t\tº  7.- REGISTRAR USUARIO                        º";
    cout<<"\n\t\tº  [ESC] - SALIR                                º";
    cout<<"\n\t\tº                                               º";
    cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
    cout<<"\n\n\t\t --> DIGITE UNA OPCION : ";
    textattr(10);cprintf("[ ]\b\b");
    opc=getch();
    textattr(7);
    switch (opc){
      case '1': RegistrarHV();
		break;
      case '2': do{
		   Marco2();
		   cout<<"\n\t\tº                                               º";
		   cout<<"\n\t\tº  CONSULTAR HOJA DE VIDA POR:                  º";
		   cout<<"\n\t\tº  1.- CODIGO DE EMPLEADO                       º";
		   cout<<"\n\t\tº  2.- APELLIDOS - NOMBRE                       º";
		   cout<<"\n\t\tº  3.- N§ DE CEDULA                             º";
		   cout<<"\n\t\tº  0.- SALIR                                    º";
		   cout<<"\n\t\tº                                               º";
		   cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
		   cout<<"\n\n\t\t --> DIGITE UNA OPCION:";
		   textattr(10);cprintf("[ ]\b\b");
		   cin>>opc3;
		   textattr(7);
		}while(opc3>=4);
		if(opc3==0){break;}
		if(opc3==1){BusqXCodigo();}
		if(opc3==2){BusqXapellido();}
		if(opc3==3){BusqXcedula();}
		break;

      case '3': ListarHV();
		break;
      case '4': Modificar();
		break;
      case '5': Desvinemple();
		break;
      case '6': Reset();
		break;
      case '7': RegistrarU();
		break;
      default : if(opc == 27){Marco7();}
    }
  }
}

/*-----------------FUNCION VALIDA LOGIN & PASSWORD USUARIO-----------------*/
int ValidaPassw()
{
  char pass[10],login[10];
  int numReg;
  int sw=FALSE;
  fstream Archivo;
  Archivo.open(ArchivoUSU,ios::in|ios::out|ios::binary);
  if (!Archivo){
	Marco3();
  }
  else{
      numReg=0;
      clrscr();
      Marco1();
      cout<<"\n\n\t\t     ------ VALIDACION DE USUARIO ------";
      cout<<"\n\n\t\t DIGITE EL LOGIN       : ";
      gets(login);
      cout<<"\n\t\t DIGITE EL PASSWORD    : ";
      gets(pass);
      clrscr();
      do{
	 numReg++;
	 Archivo.read( (char *)&usuario, sizeof(usuario) );
	 if(Archivo.eof()){
	    clrscr();
	    Marco2();
	    cout<<"\n\t\tº                                               º";
	    cout<<"\n\t\tº       ------ USUARIO NO VALIDO ------         º";
	    cout<<"\n\t\tº                                               º";
	    cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
	    PAUSA;
	    break;
	 }
	 //stricmp compara las cadenas sin distinguir Mayusculas
	 if((stricmp(pass,usuario.password)==0)&&(stricmp(login,usuario.login)==0)){
	     Marco1();
	     cout<<"\n\n\n\t\t        -------    BIENVENIDO    -------";
	     cout<<"\n\n\n\t\t         USUARIO        :"<<usuario.nombre1U<<" "<<usuario.apellido1U;;
	     sw=TRUE;
	     delay(3000);
	     cout<<resetiosflags(ios::left)<<setiosflags(ios::fixed | ios::showpoint);
	     break;
	 }
      }while(!Archivo.eof());
      Archivo.close();
  }
  return sw;//Retorna False o True - Validar usuario
}

/*------------FUNCION CAPTURA & GUARDA LOS DATOS DE LAS HOJAS VIDA----------*/
void RegistrarHV()
{
  int sw=FALSE;
  char res;
  do{
     clrscr();
     Marco1();
     cout<<"\n\n\t\t  DIGITE EL CODIGO DEL EMPLEADO [0]-SALIR: ";
     textattr(10);cprintf("[   ]\b\b\b\b");
     cin>>CodigoE;//Nuevo Codigo
     textattr(7);
     sw=RevisaCod(CodigoE);//Revisa si el codigo ya es utilizado
  }while(sw==FALSE);
  if (CodigoE != 0){
      ofstream Archivo;
      Archivo.open(ArchivoHV, ios::ate);
      if (!Archivo){
	   Marco3();
      }
      else{
	   empleado.codigoHV=CodigoE;
	   empleado.estado='V';
	   cout<<"\n\t\t REGISTRAR HOJA DE VIDA ";
	   cout<<"\n\n\t\t FECHA DE VINCULACION (dd/mm/aa): ";
	   gets(empleado.fechaing);
	   cout<<"\n\t\t------DATOS PERSONALES------\n";
	   cout<<"\n\t\tPrimer Apellido: ";
	   gets(empleado.apellido1);
	   cout<<"\t\tSegundo Apellido: ";
	   gets(empleado.apellido2);
	   cout<<"\t\tPrimer Nombre: ";
	   gets(empleado.nombre1);
	   cout<<"\t\tSegundo Nombre: ";
	   gets(empleado.nombre2);
	   cout<<"\t\tCedula: ";
	   gets(empleado.cedula);
	   cout<<"\t\tTel‚fono: ";
	   gets(empleado.telefono);
	   cout<<"\t\tDirecci¢n: ";
	   gets(empleado.direccion);
	   cout<<"\t\tFecha de Nacimiento: ";
	   do{
		cout<<"\n\t\tDigite el d¡a (dd): ";
		gets(empleado.fndia);
	   }while((atoi(empleado.fndia)>=32)||(atoi(empleado.fndia)<=0));
	   do{
		cout<<"\t\tDigite el mes (mm): ";
		gets(empleado.fnmes);
	   }while((atoi(empleado.fnmes)>=13)||(atoi(empleado.fnmes)<=0));
	   do{
	   cout<<"\t\tDigite el a¤o (aaaa): ";
	   gets(empleado.fnanio);
	   }while((atoi(empleado.fnanio)<=1900)||(atoi(empleado.fnanio)>=2005));
	   cout<<"\t\tLugar de Nacimiento: ";
	   gets(empleado.lugarnac);
	   cout<<"\t\tCargo Actual: ";
	   gets(empleado.cargo);
	   do{
	      cout<<"\t\tEstado Civil : ";
	      cout<<"\t 1.Soltero(a)";
	      cout<<"   2.Casado (a): ->";
	      textattr(10);cprintf("[ ]\b\b");
	      cin>>empleado.estadociv;
	      textattr(7);
	   }while((empleado.estadociv<1)||(empleado.estadociv)>=3);
	   cout<<"\n\t\t------DATOS ACADEMICOS------\n";
	  do{
	     cout<<"\n\t\t----BACHILLERATO----: ";
	     cout<<"\n\t\t 1.Cl sico";
	     cout<<"\n\t\t 2.Comercial";
	     cout<<"\n\t\t 3.T‚cnico : -->";
	     textattr(10);cprintf("[ ]\b\b");
	     cin>>empleado.tipobachi;
	     textattr(7);
	  }while((empleado.tipobachi<1)||(empleado.tipobachi)>=4);
	  cout<<"\n\t\t Nombre de la Instituci¢n: ";
	  gets(empleado.colbachi);
	  cout<<"\t\t A¤o Finalizaci¢n: ";
	  gets(empleado.fechabachi);
	  do{
	     cout<<"\n\t\t----EDUCACION SUPERIOR----: ";
	     cout<<"\n\t\t 1.Si";
	     cout<<"\n\t\t 2.No : -->";
	     textattr(10);cprintf("[ ]\b\b");
	     cin>>empleado.opcesupe;
	     textattr(7);
	  }while((empleado.opcesupe<1)||(empleado.opcesupe)>=3);
	  if(empleado.opcesupe==1){
	      do{
		 cout<<"\n\t\t 1.T‚nico";
		 cout<<"\n\t\t 2.Tecnol¢gico";
		 cout<<"\n\t\t 3.Profesional : -->";
		 textattr(10);cprintf("[ ]\b\b");
		 cin>>empleado.tipoesupe;
		 textattr(7);
	      }while((empleado.tipoesupe<1)||(empleado.tipoesupe)>=4);
	      cout<<"\n\t\t Titulo Obtenido: ";
	      gets(empleado.esupe);
	      cout<<"\t\t Nombre de la Instituci¢n: ";
	      gets(empleado.uesupe);
	      cout<<"\t\t A¤o Finalizaci¢n: ";
	      gets(empleado.fechaesupe);
	      do{
		 cout<<"\n\t\t--POSTGRADO--: ";
		 cout<<"\n\t\t 1.Si";
		 cout<<"\n\t\t 2.No : -->";
		 textattr(10);cprintf("[ ]\b\b");
		 cin>>empleado.opcpost;
		 textattr(7);
	     }while((empleado.opcpost<1)||(empleado.opcpost)>=3);
	     if(empleado.opcpost==1){
		 cout<<"\n\t\t Titulo Obtenido: ";
		 gets(empleado.postgrado);
		 cout<<"\t\t Nombre de la Instituci¢n: ";
		 gets(empleado.upostgrado);
		 cout<<"\t\t A¤o Finalizaci¢n: ";
		 gets(empleado.fechapost);
	     }
	  }
	  do{
	      cout<<"\n\t\t----IDIOMAS----: ";
	      cout<<"\n\t\t 1.Si";
	      cout<<"\n\t\t 2.No : -->";
	      textattr(10);cprintf("[ ]\b\b");
	      cin>>empleado.opcidioma;
	      textattr(7);
	  }while((empleado.opcidioma<1)||(empleado.opcidioma)>=3);
	  if(empleado.opcidioma==1){
	       cout<<"\n\t\t ¨Que idioma(s) conoce?: ";
	       gets(empleado.idioma);
	  }
	  do{
	       cout<<"\n\t\t----SISTEMAS----: ";
	       cout<<"\n\t\t 1.Si";
	       cout<<"\n\t\t 2.No : -->";
	       textattr(10);cprintf("[ ]\b\b");
	       cin>>empleado.opcsiste;
	       textattr(7);
	  }while((empleado.opcsiste<1)||(empleado.opcsiste)>=3);
	  if(empleado.opcsiste==1){
	       cout<<"\n\t\t ¨Programa(s) que maneja?: ";
	       gets(empleado.sistemas);
	  }
	  do{
	       cout<<"\n\t\t------DATOS LABORALES------\n";
	       cout<<"\n\t\t----EXPERIENCIA LABORAL----: ";
	       cout<<"\n\t\t 1.Si";
	       cout<<"\n\t\t 2.No : -->";
	       textattr(10);cprintf("[ ]\b\b");
	       cin>>empleado.opclaboral;
	       textattr(7);
	  }while((empleado.opcsiste<1)||(empleado.opcsiste)>=3);
	  if (empleado.opclaboral==1){
	       cout<<"\n\t\t Nombre de la Empresa: ";
	       gets(empleado.empresa);
	       cout<<"\t\t Cargo que Ocupaba: ";
	       gets(empleado.cargoant);
	       cout<<"\t\t Nombre del Jefe Inmediato: ";
	       gets(empleado.jefe);
	       cout<<"\t\t Tel‚fono de la Empresa: ";
	       gets(empleado.telempresa);
	       cout<<"\t\t Fecha de Ingreso (dd/mm/aa): ";
	       gets(empleado.fingreso);
	       cout<<"\t\t Fecha de Retiro (dd/mm/aa): ";
	       gets(empleado.fretiro);
	  }
	  cout<<"\n\t\tDesea Guardar Registro? [S]-GUARDAR";
	  textattr(10);cprintf("[ ]\b\b");
	  res=getch();
	  textattr(7);
	  if(res=='s' || res=='S'){
	      Archivo.write((char *)&empleado, sizeof(empleado));
	      Marco4();
	  }
	  else{
	       Marco5();
	  }
      }
      Archivo.close();
 }

}

/*----------------------FUNCION VALIDA CODIGO A UTILIZAR-------------------*/
int RevisaCod(int CodigoE)
{
  int sw=TRUE;
  fstream rd(ArchivoHV, ios::in|ios::out|ios::binary);
  do{
     rd.read((char *)&empleado, sizeof(empleado));
     if(rd.eof())
	break;
     if(CodigoE == empleado.codigoHV){//Compara Codigo
	sw=FALSE;
	clrscr();
	Marco2();
	cout<<"\n\t\tº                                               º";
	cout<<"\n\t\tº            CODIGO DIGITADO EN USO!!           º";
	cout<<"\n\t\tº                                               º";
	cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
	PAUSA;
	break;
     }
  }while(!rd.eof());
  rd.close();
 return sw;
}

/*--------------------FUNCION IMPRIME X PANTALLA H. VIDAS------------------*/
void Mostrar()
{
  clrscr();
      int anios,dia,mes,anio;
      struct date d;//fecha
      getdate(&d); //Capturar fecha actual
      fflush(stdin);
      Marco1();
      cout<<"\n\n\t\t	    H O J A   D E   V I D A            ";
      cout<<"\n\t\t/-----------------------------------------------/";
      cout<<"\n\t\t CODIGO EMPLEADO     : "<<empleado.codigoHV;
      if(empleado.estado=='N'){cout<<"\n\t\t ESTADO              : NO VINCULADO";}
      if(empleado.estado=='V'){cout<<"\n\t\t ESTADO              : VINCULADO";}
      cout<<"\n\t\t/----------------------------------------------/\n";

      cout<<"\n\t\t/------------   DATOS PERSONALES    -----------/\n";
      cout<<"\n\t\t Primer Apellido     : "<<empleado.apellido1;
      cout<<"\n\t\t Segundo Apellido    : "<<empleado.apellido2;
      cout<<"\n\t\t 1er. Nombre         : "<<empleado.nombre1;
      cout<<"\n\t\t 2do. Nombre         : "<<empleado.nombre2;
      cout<<"\n\t\t Cedula              : "<<empleado.cedula;
      cout<<"\n\t\t Tel‚fono            : "<<empleado.telefono;
      cout<<"\n\t\t Direcci¢n           : "<<empleado.direccion;
      cout<<"\n\t\t Fecha de Nacimiento : "<<dia<<"/"<<mes<<"/"<<anio;
      dia=atoi(empleado.fndia);
      mes=atoi(empleado.fnmes);
      anio=atoi(empleado.fnanio);
      anios=(d.da_year-anio);/*--------Calcular Edad----------------*/
      if (d.da_mon<mes){
	anios--;
      }
      if ((d.da_mon==mes)&&(dia>d.da_day)){
	anios--;
      }
      /*------------------------------------------------------------*/
      cout<<"\n\t\t Edad                : "<<anios;
      cout<<"\n\t\t Lugar de Nacimiento : "<<empleado.lugarnac;
      cout<<"\n\t\t Cargo               : "<<empleado.cargo;
      if(empleado.estadociv==1){cout<<"\n\t\t Estado Civil        : Soltero(a)";}
      if(empleado.estadociv==2){cout<<"\n\t\t Estado Civil        : Casado(a)";}
      cout<<"\n\t\t/----------------------------------------------/";
      getch();
      clrscr();
      Marco1();
      cout<<"\n\t\t/-------------  DATOS ACADEMICOS  -------------/\n";
      cout<<"\n\t\t BACHILLERATO                : ";
      if(empleado.tipobachi==1){cout<<"\tCl sico";}
      if(empleado.tipobachi==2){cout<<"\tComercial";}
      if(empleado.tipobachi==3){cout<<"\tT‚cnico";}
      cout<<"\n\t\t Nombre de la Instituci¢n    : "<<empleado.colbachi;
      cout<<"\n\t\t A¤o de Finalizaci¢n         : "<<empleado.fechabachi;
      if(empleado.opcesupe==1){
	  cout<<"\n\n\t\t EDUCACION SUPERIOR          : ";
	  if(empleado.tipoesupe==1){cout<<"\tT‚cnico";}
	  if(empleado.tipoesupe==2){cout<<"\tTecnol¢gico";}
	  if(empleado.tipoesupe==3){cout<<"\tProfesional";}
	  cout<<"\n\t\t Titulo Obtenido             : "<<empleado.esupe;
	  cout<<"\n\t\t Nombre de la Instituci¢n    : "<<empleado.uesupe;
	  cout<<"\n\t\t A¤o de Finalizaci¢n         : "<<empleado.fechaesupe;
	  if(empleado.opcpost==1){
	      cout<<"\n\n\t\t POSTGRADO                   : ";
	      cout<<"\n\t\t Titulo Obtenido             : "<<empleado.postgrado;
	      cout<<"\n\t\t Nombre de la Instituci¢n    : "<<empleado.upostgrado;
	      cout<<"\n\t\t A¤o de Finalizaci¢n         : "<<empleado.fechapost;
	  }
      }
      if(empleado.opcidioma==1){
	 cout<<"\n\t\t Idiomas                     : "<<empleado.idioma;
      }
      if(empleado.opcsiste==1){
	 cout<<"\n\t\t Sistemas                    : "<<empleado.sistemas;
      }
      cout<<"\n\t\t/-----------------------------------------------/\n";
      getch();
      if(empleado.opclaboral==1){
	  clrscr();
	  Marco1();
	  cout<<"\n\t\t/-------------  EXPERIENCIA LABORAL  -----------/\n";
	  cout<<"\n\t\t Empresa             : "<<empleado.empresa;
	  cout<<"\n\t\t Cargo               : "<<empleado.cargoant;
	  cout<<"\n\t\t Jefe Inmediato      : "<<empleado.jefe;
	  cout<<"\n\t\t Tel‚fono            : "<<empleado.telempresa;
	  cout<<"\n\t\t Fecha de Ingreso    : "<<empleado.fingreso;
	  cout<<"\n\t\t Fecha de Retiro     : "<<empleado.fretiro;
	  cout<<"\n\t\t/----------------------------------------------/\n";
	  getch();
      }
}

/*---------------FUNCION CONSULTA DE H.VIDA X APELLIDOS & NOMBRE-----------*/
void BusqXapellido()
{
  char ape[30],ape2[30],nom[50];
  int numReg;
  fstream Archivo;
  Archivo.open(ArchivoHV,ios::in|ios::out|ios::binary);
  if (!Archivo){
	 Marco3();
  }
  else{
      numReg=0;
      clrscr();
      Marco1();
      cout<<"\n\n\t\t  ---------- CONSULTA DE HOJA DE VIDA ----------";
      cout<<"\n\n\t\tDIGITE EL 1er. APELLIDO: ";
      gets(ape);
      cout<<"\n\t\tDIGITE EL 2do. APELLIDO: ";
      gets(ape2);
      cout<<"\n\t\tDIGITE EL 1er. NOMBRE       : ";
      gets(nom);
      clrscr();
      do{
	 numReg++;
	 Archivo.read( (char *)&empleado, sizeof(empleado) );
	 if(Archivo.eof()){
	    Marco6();
	    break;
	 }
	 if((stricmp(ape,empleado.apellido1)==0)&&(stricmp(ape2,empleado.apellido2)==0)&&(stricmp(nom,empleado.nombre1)==0)){
	     Mostrar();
	     cout<<resetiosflags(ios::left)<<setiosflags(ios::fixed | ios::showpoint);
	     break;
	 }
      }while(!Archivo.eof());
      Archivo.close();
  }
}

/*-----------------FUNCION CONSULTA DE H.VIDA X N§ DE CEDULA---------------*/
void BusqXcedula()
{
  char ced[10];
  int numReg=0;
  clrscr();
  fstream Archivo;
  Archivo.open(ArchivoHV,ios::in|ios::out|ios::binary);
  if (!Archivo){
	 Marco3();
  }
  else{
      Marco1();
      cout<<"\n\n\t\t  ---------- CONSULTA DE HOJA DE VIDA ----------";
      cout<<"\n\n\t\tDIGITE EL N§ DE CEDULA: ";
      gets(ced);
      clrscr();
      do{
	 numReg++;
	 Archivo.read( (char *)&empleado, sizeof(empleado) );
	 if(Archivo.eof()){
	    Marco6();
	    break;
	 }
	 if(stricmp(ced,empleado.cedula)==0){
	     Mostrar();
	     cout<<resetiosflags(ios::left)<<setiosflags(ios::fixed | ios::showpoint);
	     break;
	 }
      }while(!Archivo.eof());
      Archivo.close();
  }
}

/*-----------------FUNCION CONSULTA DE H.VIDA X N§ DE CODIGO---------------*/
void BusqXCodigo()
{
  int CodigoE;
  int numReg;
  fstream Archivo;
  Archivo.open(ArchivoHV,ios::in|ios::out|ios::binary);
  if (!Archivo){
       Marco3();
  }
  else{
       numReg=0;
       clrscr();
       Marco1();
       cout<<"\n\n\t\t  ---------- CONSULTA DE HOJA DE VIDA ----------";
       cout<<"\n\n\t\tDIGITE EL CODIGO DEL EMPLEADO: ";
       cin>>CodigoE;
       clrscr();
       do{
	  numReg++;
	  Archivo.read( (char *)&empleado, sizeof(empleado) );
	  if(Archivo.eof()){
	     Marco6();
	     break;
	  }
	  if(CodigoE==empleado.codigoHV){
	     Mostrar();
	     cout<<resetiosflags(ios::left)<<setiosflags(ios::fixed | ios::showpoint);
	     break;
	  }
      }while(!Archivo.eof());
      Archivo.close();
  }
}

/*----------FUNCION MODIFICA LOS DATOS DE LAS HOJAS DE VIDA----------------*/
void Modificar()
{
   int numReg=0,CodigoE;
   char res1,res2,res3;
   clrscr();
   fstream Archivo;
   Archivo.open(ArchivoHV,ios::in|ios::out|ios::binary);
   if (!Archivo){
	Marco3();
   }
   else{
	Marco1();
	cout<<"\n\n\t\t  DIGITE EL CODIGO DEL EMPLEADO [0]-SALIR: ";
	textattr(10);cprintf("[ ]\b\b");
	cin>>CodigoE;
	textattr(7);
	clrscr();
	do{
	   numReg++;
	   Archivo.read( (char *)&empleado, sizeof(empleado) );
	   if(Archivo.eof()){
		Marco6();
		break;
	   }
	   if(CodigoE==empleado.codigoHV){
		clrscr();
		Marco1();
		cout<<"\n\t\t MODIFICAR DATOS PERSONALES? Si [S] / No [N]:";
		textattr(10);cprintf("[ ]\b\b");
		res1=getch();
		textattr(7);
		if(res1=='s' || res1=='S'){
		     cout<<"\n\n\t\t            MODIFICAR HOJA DE VIDA ";
		     cout<<"\n\n\t\t------DATOS PERSONALES------\n";
		     cout<<"\n\t\t1er. Apellido: ";
		     gets(empleado.apellido1);
		     cout<<"\t\t2do. Apellido: ";
		     gets(empleado.apellido2);
		     cout<<"\t\t1er. Nombre: ";
		     gets(empleado.nombre1);
		     cout<<"\t\t2do. Nombre: ";
		     gets(empleado.nombre2);
		     cout<<"\t\tCedula: ";
		     gets(empleado.cedula);
		     cout<<"\t\tTel‚fono: ";
		     gets(empleado.telefono);
		     cout<<"\t\tDirecci¢n: ";
		     gets(empleado.direccion);
		     cout<<"\t\tFecha de Nacimiento: ";
		     do{
			cout<<"\n\t\tDigite el d¡a (dd): ";
			gets(empleado.fndia);
		     }while((atoi(empleado.fndia)>=32)||(atoi(empleado.fndia)<=0));
		     do{
			cout<<"\t\tDigite el mes (mm): ";
			gets(empleado.fnmes);
		     }while((atoi(empleado.fnmes)>=13)||(atoi(empleado.fnmes)<=0));
		     do{
			cout<<"\t\tDigite el a¤o (aaaa): ";
			gets(empleado.fnanio);
		     }while((atoi(empleado.fnanio)<=1900)||(atoi(empleado.fnanio)>=2005));
		     cout<<"\t\tLugar de Nacimiento: ";
		     gets(empleado.lugarnac);
		     cout<<"\t\tCargo Actual: ";
		     gets(empleado.cargo);
		     do{
			cout<<"\t\tEstado Civil : ";
			cout<<"\t 1.Soltero(a)";
			cout<<"   2.Casado(a): ->";
			textattr(10);cprintf("[ ]\b\b");
			cin>>empleado.estadociv;
			textattr(7);
		     }while((empleado.estadociv<1)||(empleado.estadociv)>=3);
		}
		clrscr();
		Marco1();
		cout<<"\n\t\t MODIFICAR DATOS ACADEMICOS? Si [S] / No [N]:";
		textattr(10);cprintf("[ ]\b\b");
		res2=getch();
		textattr(7);
		if(res2=='s' || res2=='S'){
		    cout<<"\n\n\t\t            MODIFICAR HOJA DE VIDA ";
		    cout<<"\n\n\t\t------DATOS ACADEMICOS------\n";
		    do{
			cout<<"\n\t\t----BACHILLERATO----: ";
			cout<<"\n\t\t 1.Cl sico";
			cout<<"\n\t\t 2.Comercial";
			cout<<"\n\t\t 3.T‚cnico : ->";
			textattr(10);cprintf("[ ]\b\b");
			cin>>empleado.tipobachi;
			textattr(7);
		    }while((empleado.tipobachi<1)||(empleado.tipobachi)>=4);
		    cout<<"\n\t\t Nombre de la Instituci¢n: ";
		    gets(empleado.colbachi);
		    cout<<"\t\t A¤o Finalizaci¢n: ";
		    gets(empleado.fechabachi);
		    do{
			cout<<"\n\t\t----EDUCACION SUPERIOR----: ";
			cout<<"\n\t\t 1.Si";
			cout<<"\n\t\t 2.No : ->";
			textattr(10);cprintf("[ ]\b\b");
			cin>>empleado.opcesupe;
			textattr(7);
		    }while((empleado.opcesupe<1)||(empleado.opcesupe)>=3);
		    if(empleado.opcesupe==1){
			 do{
			     cout<<"\n\t\t 1.T‚nico";
			     cout<<"\n\t\t 2.Tecnol¢gico";
			     cout<<"\n\t\t 3.Profesional : ->";
			     textattr(10);cprintf("[ ]\b\b");
			     cin>>empleado.tipoesupe;
			     textattr(7);
			 }while((empleado.tipoesupe<1)||(empleado.tipoesupe)>=4);
			 cout<<"\n\t\t Titulo Obtenido: ";
			 gets(empleado.esupe);
			 cout<<"\t\t Nombre de la Instituci¢n: ";
			 gets(empleado.uesupe);
			 cout<<"\t\t A¤o Finalizaci¢n: ";
			 gets(empleado.fechaesupe);
			 do{
			     cout<<"\n\t\t--POSTGRADO--: ";
			     cout<<"\n\t\t 1.Si";
			     cout<<"\n\t\t 2.No : ->";
			     textattr(10);cprintf("[ ]\b\b");
			     cin>>empleado.opcpost;
			     textattr(7);
			 }while((empleado.opcpost<1)||(empleado.opcpost)>=3);
			 if(empleado.opcpost==1){
			     cout<<"\n\t\t Titulo Obtenido: ";
			     gets(empleado.postgrado);
			     cout<<"\t\t Nombre de la Instituci¢n: ";
			     gets(empleado.upostgrado);
			     cout<<"\t\t A¤o Finalizaci¢n: ";
			     gets(empleado.fechapost);
			 }
		    }
		    do{
			cout<<"\n\t\t----IDIOMAS----: ";
			cout<<"\n\t\t 1.Si";
			cout<<"\n\t\t 2.No : ->";
			textattr(10);cprintf("[ ]\b\b");
			cin>>empleado.opcidioma;
			textattr(7);
		    }while((empleado.opcidioma<1)||(empleado.opcidioma)>=3);
		    if(empleado.opcidioma==1){
			cout<<"\n\t\t ¨Que idioma(s) conoce?: ";
			gets(empleado.idioma);
		    }
		    do{
			cout<<"\n\t\t----SISTEMAS----: ";
			cout<<"\n\t\t 1.Si";
			cout<<"\n\t\t 2.No : ->";
			textattr(10);cprintf("[ ]\b\b");
			cin>>empleado.opcsiste;
			textattr(7);
		    }while((empleado.opcsiste<1)||(empleado.opcsiste)>=3);
		    if(empleado.opcsiste==1){
			cout<<"\n\t\t ¨Programa(s) que maneja?: ";
			gets(empleado.sistemas);
		    }
		}
		clrscr();
		Marco1();
		cout<<"\n\t\t MODIFICAR DATOS LABORALES? Si [S] / No [N]:";
		textattr(10);cprintf("[ ]\b\b");
		res3=getch();
		textattr(7);
		if(res3=='s' || res3=='S'){
		    do{
			cout<<"\n\n\t\t            MODIFICAR HOJA DE VIDA ";
			cout<<"\n\n\t\t------DATOS LABORALES------\n";
			cout<<"\n\t\t----EXPERIENCIA LABORAL----: ";
			cout<<"\n\t\t 1.Si";
			cout<<"\n\t\t 2.No : ->";
			textattr(10);cprintf("[ ]\b\b");
			cin>>empleado.opclaboral;
			textattr(7);
		    }while((empleado.opcsiste<1)||(empleado.opcsiste)>=3);
		    if (empleado.opclaboral==1){
			cout<<"\n\t\t Nombre de la Empresa: ";
			gets(empleado.empresa);
			cout<<"\t\t Cargo que Ocupaba: ";
			gets(empleado.cargoant);
			cout<<"\t\t Nombre del Jefe Inmediato: ";
			gets(empleado.jefe);
			cout<<"\t\t Tel‚fono de la Empresa: ";
			gets(empleado.telempresa);
			cout<<"\t\t Fecha de Ingreso: ";
			gets(empleado.fingreso);
			cout<<"\t\t Fecha de Retiro: ";
			gets(empleado.fretiro);
		    }
		}
		Archivo.seekp((numReg-1)*sizeof(empleado));
		Archivo.write((char *)&empleado,sizeof(empleado));
		break;
	   }
	}while(!Archivo.eof());
	Archivo.close();
   }
}

/*-----------------FUNCION MUESTRA TODAS H.VIDA (COD-APELL-NOM)-----------*/
void ListarHV()
{
  int numReg=0;
  fstream Archivo;
  clrscr();
  Archivo.open(ArchivoHV,ios::in|ios::binary);
  if (!Archivo){
      Marco3();
  }
  else{
      do{
	 numReg++;
	 Archivo.read( (char *)&empleado, sizeof(empleado) );
	 if(Archivo.eof()){
	     break;
	 }
	 cout<<resetiosflags(ios::left)<<setiosflags(ios::fixed | ios::showpoint);
	 cout<<"\n\t HVIDA V.01 ";
	 cout<<"\n\t CODIGO EMPLEADO     : "<<empleado.codigoHV;
	 if(empleado.estado=='N'){cout<<"\n\t ESTADO              : NO VINCULADO";}
	 if(empleado.estado=='V'){cout<<"\n\t ESTADO              : VINCULADO";}
	 cout<<"\n\t Cargo               : "<<empleado.cargo;
	 cout<<"\n\t Apellidos           : "<<empleado.apellido1<<" "<<empleado.apellido2;
	 cout<<"\n\t Nombres             : "<<empleado.nombre1<<" "<<empleado.nombre2;
	 cout<<"\n\t Cedula              : "<<empleado.cedula;
	 cout<<"\n\t/-----------------------------------------/\n";
	 getch();
      }while(!Archivo.eof());
      Archivo.close();
  }
}

/*-------------------FUNCION DESVINCULA EMPLEADO - EMPRESA ----------------*/
void Desvinemple()
{
  int numReg=0,CodigoE;
  clrscr();
  fstream Archivo;
  Archivo.open(ArchivoHV,ios::in|ios::out|ios::binary);
  if (!Archivo){
      Marco3();
  }
  else{
       Marco1();
       cout<<"\n\n\t\t    ---------- DESVINCULAR EMPLEADO ----------";
       cout<<"\n\n\t\tDIGITE EL N§ DE CODIGO DEL EMPLEADO: ";
       cin>>CodigoE;
       do{
	  numReg++;
	  Archivo.read( (char *)&empleado, sizeof(empleado) );
	  if(Archivo.eof()){
	     Marco6();
	     break;
	  }
	  if(CodigoE==empleado.codigoHV){
	      clrscr();
	      empleado.estado='N';//"N" en el campo estado del empleado
	      Marco2();
	      cout<<"\n\t\tº                                               º";
	      cout<<"\n\t\tº     ------ EMPLEADO DESVINCULADO ------       º";
	      cout<<"\n\t\tº                                               º";
	      cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
	      PAUSA;
	      Archivo.seekp((numReg-1)*sizeof(empleado));
	      Archivo.write((char *)&empleado,sizeof(empleado));
	      break;
	  }
       }while(!Archivo.eof());
       Archivo.close();
  }

}

/*--------------------FUNCION RESETEA EL ARCHIVO HVIDA.DAT-----------------*/
void Reset()
{
  int opc;
  Marco2();
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tº ALERTA:!ELIMINARA TODAS LAS DE HOJAS DE VIDA!!º";
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
  cout<<"\n\t\t         ¨ESTA SEGURO? SI [S] / No [N] :";
  textattr(10);cprintf("[ ]\b\b");
  opc=getch();
  textattr(7);
  if(opc=='s' || opc=='S'){
	ofstream arch;
	arch.open ("HVIDAS.DAT", ios::out);
	arch.close();
	Marco2();
	cout<<"\n\t\tº                                               º";
	cout<<"\n\t\tº              ARCHIVO RESETEADO!!!!            º";
	cout<<"\n\t\tº                                               º";
	cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
	PAUSA;
  }
}
/*----------------FUNCION REGISTRA USUARIO - LOGIN & PASSWORD-------------*/
void RegistrarU()
{
  char res;
     clrscr();
     ofstream Archivo;
     Archivo.open(ArchivoUSU, ios::ate);
      if (!Archivo){
	 Marco3();
      }
      else{
	   Marco1();
	   cout<<"\n\t\t REGISTRAR NUEVO USUARIO ";
	   cout<<"\n\t\t 1er. Apellido: ";
	   gets(usuario.apellido1U);
	   cout<<"\t\t 2do. Apellido: ";
	   gets(usuario.apellido2U);
	   cout<<"\t\t 1er. Nombre: ";
	   gets(usuario.nombre1U);
	   cout<<"\t\t 2do. Nombre: ";
	   gets(usuario.nombre2U);
	   cout<<"\t\t Digite un Login: ";
	   gets(usuario.login);
	   do{
	   cout<<"\t\t Digite un Password (6-10 CARACTERES):";
	   gets(usuario.password);
	   }while((strlen(usuario.password)>=11)||(strlen(usuario.password)<=5));
	   //strlen password entre 6 a 11 caracteres alfanumericos
	   cout<<"\n\t\tDesea Guardar Usuario? [S]-GUARDAR";
	   textattr(10);cprintf("[ ]\b\b");
	   res=getch();
	   textattr(7);
	   if(res=='s' || res=='S'){
	      Archivo.write((char *)&usuario, sizeof(usuario));
	      Marco4();
	  }
	  else{
	      Marco5();
	  }
      }
      Archivo.close();
}

/*--------------------- FUNCIONES VENTANAS UTILIZADAS ---------------------*/
void Marco1()
{
  cout<<"\n\t\tÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tº                  HVIDA V.02                   º";
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
}

/*-------------------------------------------------------------------------*/
void Marco2()
{
  clrscr();
  cout<<"\n\t\tÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tº                  HVIDA V.02                   º";
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹";
}

/*-------------------------------------------------------------------------*/
void Marco3()
{
  Marco2();
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tº     ----- ERROR AL ABRIR ARCHIVO ------       º";
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
  PAUSA;
}

/*-------------------------------------------------------------------------*/
void Marco4()
{
  Marco2();
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tº       ------ REGISTRO GUARDADO ------         º";
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
  PAUSA;
}

/*-------------------------------------------------------------------------*/
void Marco5()
{
  Marco2();
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tº      ------ REGISTRO NO GUARDADO ------       º";
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
  PAUSA;
}

/*-------------------------------------------------------------------------*/
void Marco6()
{
  Marco2();
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tº     ------ REGISTRO NO ENCONTRADO ------      º";
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
  PAUSA;
}
/*-------------------------------------------------------------------------*/
void Marco7()
{
  Marco2();
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tº        CERRANDO SOFTWARE HVIDA V.02           º";
  cout<<"\n\t\tº                                               º";
  cout<<"\n\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
  PAUSA;exit(0);
}
/*-------------------------------------------------------------------------*/