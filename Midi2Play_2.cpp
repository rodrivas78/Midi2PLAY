//
// Midi2PLAY  v.1.1    -    Por Rodrigo Gonzales (Rodrivas78)  email: rrivas2009@gmail.com
// Esta aplicação converte sintaxe "mml" para a sintaxe aceita pelo
// comando PLAY do MSX-BASIC. Trabalha com arquivos contendo um máximo de 3 canais simultaneos.
// É necessário a utilização do programa "3ML Editor" para a conversão do arquivo MIDI (.mid) para MML. 
// Também é necessária a formatação do arquivo de entrada ("mml.txt"). 
// Fazendo-se imprescindível a leitura das instruções.
// Compatível com todas as versões de MSX, não sendo necessário a utilização de  
// hardwares musicais especializado como 
// MSX-AUDIO, MSX-MUSIC, FM-PAC e etc.)
// 

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>

#include "MultiArrayTester.h"

using namespace std;

int main()
{
	int oitava;
	const char token = '>'; //aumenta uma oitava
	const char token2 = '<';  //diminui uma oitava
	const char token3 = '&';
	const char token4 = '[';
	const char token5 = '/';
	const char token6 = '"';
	const char token7 = ']';
	const char asteris = '*';
	string channel = "Track ";
	char strStore[1000]={};
	char error ;
	bool activateAsterCount = false;
	bool activateCharCount = false;
	int charCounter = 0;
	int asterCounter = 0; 
	int braCount = 0;
	int braCount2 = 0;
	int braCount3 = 0;
	int slashCount = 0;
	int slashVar;
	char decision;
	int decision2;	
	int copyCount = 0;
	int tokenCounter = 0;	
	const char a = 'A'; 
	const char b = 'B';  
	const char c = 'C';
	char newChar = ' ';
	char charHolder;
	int measures;
	int measures2;
	int mControl=0;
	int m = 0;
	int line = 10;
	int matrixNum = 1;	

	int test=0;
		
   char strNew= ' ';   
   char strNew2 = 'o'; //String 'O'
   string strNew3= "";
   //Novas variáveis 
   bool foundLetterO = false;
   int charCounter2=0;
   bool activNewCharCount = false;
   int charNewCounter=0;
   int lessOrGreaterThan=0;
   int foundO=0;
 
 
    ifstream filein("mml.txt"); //File to read from
	ofstream fileout("t1.txt"); //Temporary file	
		
    if(!filein || !fileout) //if both files are not available
	{
        cout << " File (mml.txt) NOT FOUND!" << endl;
		cout << " Press any key and ENTER" << endl;
		cin >> error;
        return 1;
    }
	else
	{
		cout << endl;
		cout << "Found: mml.txt" << endl << endl;
	}
	
	cout << endl;
	cout << " Do you wish concatenate measures?" << endl;
	cout << " Y or N  " << "(and press ENTER)" << endl;
	cin >> decision;
	cout << endl;

	if(decision == 'N' || decision=='n')
	{
		slashVar = 3;
	}
	else
	{
		cout << " 2, 3 or 4 measures per line? (type the number and press ENTER)" << endl;
			cin >> decision2;
			switch (decision2)
			{
			case 2 : slashVar=5;
					 cout << endl; 			
				break;
			case 3 : slashVar=7;
					 cout << endl; 
				break;
			case 4 : slashVar=9;
					 cout << endl; 
				break;

				default: cout << " Not a valid value, measures will not be concatenated! " << endl << endl;
					slashVar=3;
			}

	}
	
	string strTemp0; 
	string strTemp2; 
	string strTemp3; 
	char charTemp2;	// Nova variável: rotina de pagar as / 
    char strTemp;	//char strTemp;

//----------------------Parser_support2----------------------------------------//
//-----------------------------------------------------------------------------

	//Eliminação das barras '/' token5 //tipo:char
	while(filein >> charTemp2)
	{
		if(charTemp2==token5)
		{
			charTemp2=strNew;
		}
		
		fileout << charTemp2;
	}

fileout.close(); //Default

//Rotina para a contagem de compassos
	ifstream filein9("t1.txt"); //File to read from
	ofstream fileout9("t0.txt"); //Temporary file	

	while(filein9 >> strTemp0)//it will check line from test to strTemp string
    {
		if(strTemp0 == strReplace[0])
		{
			braCount++;
		}
		
		//itera sobre os a matriz ignorando as indicações de compasso duplicadas
		if(strTemp0 == strReplace[m] && braCount==1)
		{
            m++; //vai para a próxima posição da matriz					
		}
		
		measures = m;
		fileout9 << measures;
 }
	filein9.close();
	fileout9.close();

	measures2 = measures;
	m = 0; 
	braCount = 0;

    ifstream filein2("t1.txt"); //File to read from
	ofstream fileout2("t2.txt"); //Temporary file	

	//Elimina duplicaçoes dos *M1* etc.    Tipo: string
 while(filein2 >> strTemp2)//it will check line from test to strTemp string
    {
		
		//Procura e apaga as marcações fazendo sobrar as marcações duplicadas. Os valores da matriz estão no header
		if(strTemp2 == strReplace[m])//if your word found then replace
		{
         
			strTemp2 = strNew;		
			m++; //vai para a próxima posição da matriz
			mControl++; //mControl é a quantidade de compassos por voz			
		
			if(mControl==measures)
			{
            strTemp2 = strNew;		
			m=0;
			mControl=0;
			}	
		}
		
	fileout2 << strTemp2;//output everything to fileout(temp.txt)
 }

fileout2.close();
filein2.close(); 

ifstream filein4("t2.txt"); //File to read from
ofstream fileout4("t3.txt"); //Temporary file	
ifstream filein5("void.txt"); //File to read from
ofstream fileout5("temp.txt"); //Temporary file

//Procura (em "temp.txt") por coinscidências, ao encontrar armazena as strings em outra matriz
// ou as envia ao arquivo void
// Detecta o caracater '*', se encontra 2 * para a contagem.

while(filein4 >> charTemp2)
	{
		if(activateCharCount==true)
		{
			charCounter++;		
		}
		
		if(charTemp2==asteris)
		{
			asterCounter++;
			if(asterCounter==2)
			{
		    fileout5 << charTemp2;
			activateCharCount=false;
			fileout5 << ',';
			asterCounter=0;
			charCounter=0;
			}
			else
			{
				activateCharCount=true;
				fileout5 << charTemp2;
			}
			
		}
		
		if(charCounter==1 && asterCounter!=2)
		{
			fileout5 << charTemp2;			
		}
		else if(charCounter==2 && asterCounter!=2)
		{
			fileout5 << charTemp2;			
		}
		else if(charCounter==3 && asterCounter!=2)
		{
			fileout5 << charTemp2;			
		}
		else if(charCounter==4 && asterCounter!=2)
		{
			fileout5 << charTemp2;			
		}
			
		//Mostra no documento (temp) em que canal está a duplicação 
		if(charTemp2=='[')
		{
			braCount++;
			if(braCount==1)
			{
				fileout5 << charTemp2;
                fileout5 << "C1]";
				braCount2=braCount;
			}
			else if(braCount==2)
			{
				fileout5 << charTemp2;
				fileout5 << "C2]";
				braCount2=braCount;
			}
			else if(braCount==3)
			{
				fileout5 << charTemp2;
				fileout5 << "C3]";
				braCount2=braCount;
				braCount=0;
			}
		}
		fileout4 << charTemp2;
		
	}

filein4.close();
fileout4.close();


//----------------------------Parser_test2---------------------------------------------//
//-------------------------------------------------------------------------------------//

 ifstream filein6("mml.txt"); //File to read from
 ofstream fileout6("t4.txt"); //Temporary file			
	

	while(filein6 >> strTemp)//it will check line from test to strTemp char
    {				 
		
		//Procura pelo O para atualizar o valor da oitava
		if(strTemp=='o')
		{
			foundLetterO = true;
			foundO++;
			//charCounter2++;
		}

		if(foundLetterO==true)
		{
			charCounter2++;						
		}

			if(charCounter2==2)
		{
			oitava=(int)strTemp;
			oitava=oitava-48; 
			charCounter2 = 0;
			//fileout << oitava;
			foundLetterO = false;				
		}

		//ativa a contagem de caracteres
		if(activateCharCount = true)
		{		
		//conta os caracteres para encontrar a alteração de oitava logo após o /*M0*/ 
		charCounter++;
		}
		if(activNewCharCount = true)
		{		
		//conta os caracteres para que não haja alteração de oitava logo após as barras na primeira vez (ver caso "canon") 
		charNewCounter++;
		}
		// conta as 2 chaves ([ e ]) e incrementa braCount3 para controle da última aspas do canal
		if(strTemp==token4 || strTemp==token7)
		{
			braCount3++;			
		}

		if(charCounter==16) //Acrescenta o valor da oitava corrente 'o(n)' no inicio do fluxo do canal
		{
			fileout6 << strNew2;			
		    fileout6 << oitava;	
		}

		if(strTemp==token || strTemp==token2)
		{
			//greaterThan++;
			lessOrGreaterThan++;
		}
				
		  //inicia a contagem de caracteres ao encontrar '/' /trocar tudo por token asterisco
		  if(strTemp == token5)  //token5  = '/' 					
		 {					
			 activateCharCount=true;
			 slashCount++;
			 //apaga o '/' ao encontra-lo
 			 strTemp = strNew;

			 //adição de aspas mais mudança de linha de acordo com o número de barras (slashs) encontradas		
			  if(slashCount==1)
			 {
				 fileout6 << token6; //token6 = " " "  aspas
			 }	
			  //É possível permitir ao usuário a escolha de agrupamento de compassos
			  //se pretende agrupar os compassos de 2 em 2 -> slashCount==5, se de 3 em 3 -> slashCount==7
			  //Default: slashCount==3 (sem agrupamento).
			  else if(slashCount == 2)
			  {
				  //fileout6 << '#';
				  activNewCharCount = true;
				  charNewCounter=0; //Devido à essa variável é que o # esta sendo impresso duas vezes
			  }
			   else if(slashCount==slashVar) //else if(slashCount==7||braCount2%3)
			 {
				 slashCount=1;
				 fileout6 << token6; //token6 = " " "  aspas
				 fileout6 << "\n";
				 fileout6 << token6;				 
			 }						 			 		 
        } 
		  //Insere últimas aspas de cada canal e zera o contador de barras
		  if(braCount3==3)
		  {
			  slashCount=0;
			  fileout6 << token6;
			  braCount3=1;			 			  
			 
		  }

		 //rotina para eliminar > e inserir o O(n)  
		 if(strTemp == token)//if your word > found then replace		
		 {		
			  //este condicional evita duplicação na alteração de oitavas
			 if(charCounter==16)
			 {					
				strTemp = strNew;					
			 }			 
				 	
			    else 
				 {
					 oitava++;	
			strTemp = strNew;	
			fileout6 << strNew2;			
		    fileout6 << oitava;		
				 }									
			 			
         }     		
		 //rotina para eliminar < e inserir o O(n)  
		 if(strTemp == token2)//if your word is < found then replace					
		 {		
			
			 //este condicional evita duplicação na alteração de oitavas
			if(charCounter==16)
			 {					
				strTemp = strNew;					
			 }			
			 else 
			 { 			
			oitava--;				
			strTemp = strNew;	
			fileout6 << strNew2;			
		    fileout6 << oitava;	
			}
			
        }  
		  //rotina para eliminar o &
		 if(strTemp == token3)
		{											
			strTemp = strNew;				
        }  				   

		 if(strTemp==token4) //token 4 = [
			 {				 
		     braCount++; //Conta as chaves [ para atribuir a oitava selecionada para cada voz		 
			 cout << "In which octave ";
			 cout << token6 << channel << braCount << token6 << " begins: "  <<endl;
			 cin >> oitava;
			 fileout6 << "\n\n";
			 charCounter = 0; // Zera a contagem para eliminação de > ou < logo após /*M0*/
			 activateCharCount = false; //desativa a contagem de caracateres
			 activNewCharCount = false;
             lessOrGreaterThan = 0;
			 foundO = 0;
			 }

		fileout6 << strTemp; //output everything to fileout(play.txt)			
    }

fileout6.close();

//-----------Measure_mark_eliminator-----Parser_test3------------------------------------//
//---------------------------------------------------------------------------------------//
	
activateCharCount=false;
charCounter=0;
braCount=0;
braCount3=0;
m=0;

    ifstream filein7("t4.txt"); //File to read from
    ofstream fileout7("t5.txt"); //Temporary file
	//Iteração após a retirada de /* e */

	while(filein7 >> strTemp3)//it will check line from test to strTemp string
    {
		//Modelo padrão, não funciona com *M* duplicados
		//Elimina as indicações de compasso. Os valores da matriz estão no header
		if(strTemp3 == strReplace[m])//if your word found then replace
		{
            strTemp3 = strNew3;		
			m++; //quantidade de compassos/measures
			mControl++; //mControl é a quantidade de compassos por voz
			
			if(mControl==measures2)
		    {
            strTemp3 = strNew3;		
			m=0;
			mControl=0;
		    }				
        } 

		fileout7 << strTemp3;//output everything to fileout(temp.txt)
 }
	
   filein7.close();
   fileout7.close();  
	
   	ifstream filein8("t5.txt"); //2nd file to read from
    ofstream fileout8("play.txt"); //2nd temporary file	

	while(filein8 >> charTemp2)//it will check line from test to strTemp string
    {

		if(charTemp2 == token4)  //token 4 = '['
		{
			fileout8  << '\n';
			braCount++;			
			matrixNum = 0;
		}
		// Apaga o último ']'
		if(charTemp2 == token7) //token 7 = ']'
		{
					
			m++;

			if(m==2 && braCount2==1) 
			{
				charTemp2 = newChar;				
			}
			else if(m==3 && braCount2==2)
			{
				charTemp2 = newChar;				
			}
			else if(m==4 && braCount2==3)
			{
				charTemp2 = newChar;
			}	
		
		}

		if(braCount==1)
			{
				charHolder=(int)65;
			}
			else if(braCount==2)
			{
				charHolder=(int)66;			
			}
			else if(braCount==3)
			{
				charHolder=(int)67;				
			}	
			else if(braCount==4)
			{
				charHolder=(int)68;				
			}	
			else if(braCount==5)
			{
				charHolder=(int)69;				
			}	
			else if(braCount==6)
			{
				charHolder=(int)70;				
			}	
			else if(braCount==7)
			{
				charHolder=(int)71;				
			}	
			else if(braCount==8)
			{
				charHolder=(int)72;				
			}	
			else if(braCount==9)
			{
				charHolder=(int)73;				
			}	
			else if(braCount==10)
			{
				charHolder=(int)74;				
			}	
			else if(braCount==11)
			{
				charHolder=(int)75;				
			}	
			else if(braCount==12)
			{
				charHolder=(int)76;				
			}	
			

		if(charTemp2 == '"')//ao encontrar as aspas há uma quebra de linha
		{
            tokenCounter++;							
			
			// Controla o momento em que há troca das letras das matrizes
			if(tokenCounter==1)
			{
				matrixNum = 1;
				fileout8  << '\n';	
				fileout8 << line;
				line+=10;
				fileout8 << " ";
				fileout8 << charHolder;
				fileout8 << "$(";
				fileout8 << matrixNum;
				fileout8 << ")=";
			}
			if(tokenCounter==3)
			{
				matrixNum++;
			    fileout8  << '\n';
			    fileout8 << line;
				line+=10;
				fileout8 << " ";
				fileout8 << charHolder;
				fileout8 << "$(";
				fileout8 << matrixNum;
				fileout8 << ")=";
			    tokenCounter=1;			
			}             	

        }			
			fileout8 << charTemp2;		 
    }

	//Remove os arquivos temporários
	filein8.close();

	remove("t0.txt");
	remove("t1.txt");
	remove("t2.txt");
	remove("t3.txt");
	remove("t4.txt");
	remove("t5.txt");

	 return 0;
}

