

				       Midi2PLAY v.1.0  (for Windows 32/64)
				           by  Rodrivas78 


Sum�rio:
1. Introdu��o
2. Compatibilidade
3. Guia r�pido 
4. Formata��o (do arquivo "mml.txt")
5. Exemplo de utiliza��o
6. Concatenando compassos
7. Dicas 
8. Limita��es e problemas conhecidos 
9. Considera��es finais 



1. Introdu��o

 O "Midi2PLAY" � uma ferramenta que auxilia no processo de convers�o de arquivos MIDI (.mid) tornando-os compat�veis 
com a sintaxe aceita pelo comando "PLAY" do MSX-BASIC. 

 Este programa funciona como extens�o do programa 3ML Editor, isto �, depende deste para efetuar o processo de convers�o. 
O 3ML Editor � gratuito e pode ser baixado no link:  http://3ml.jp/download.html  (No momento em que este manual � redigido est� na vers�o: 2.0.3)

  Resumo do processo de convers�o:

 Arquivo MIDI --> 3ML Editor --> Arquivo MML(.txt) --> Midi2PLAY --> Arquivo .BAS  

1)  Importar o arquivo MIDI no 3ML Editor. 
2)  Ainda no 3ML Editor: exportar o arquivo MML. (Salvar como "mml.txt")
3)  Executar o "Midi2PLAY" (com o "mml.txt" na mesma pasta, adequadamente formatado)
4)  Ser� gerado o arquivo "play.txt". Basta salv�-lo como ".bas" e utiliz�-lo no MSX. 

   Fica-se compreendido que o Midi2PLAY poderia (ou deveria!) se chamar "mml2play", visto que sua fun��o � a convers�o da sintaxe "mml" (Music Macro Language) para a sintaxe aceita pelo comando PLAY. Mas como o formato "MML" n�o � t�o conhecido, e para que a fun��o do programa torne-se autoexplicativa, optei pelo nome atual.  


2. Compatibilidade:
    
  O Midi2PLAY � compat�vel com Windows 32/64 (em breve tamb�m p/ iOS).  
  A sintaxe gerada por ele � compat�vel com qualquer vers�o de MSX (desde o MSX1), sem necessidade de harware adicional como MSX-Audio ou MSX-Music/FM-Pac. 
                                                    


3. Guia r�pido / Quick Guide

A convers�o do arquivo MIDI (para ser executado pelo comando PLAY do MSX) ocorre em duas etapas: 

1) No 3ML Editor importa-se o arquivo MIDI (.mid) (File > Import Standar MIDI file). 

Obs.: Se o arquivo possuir mais de 3 canais/tracks, voc� ter� que escolher apenas 3 dos canais pois � o m�ximo que o PSG do MSX suporta. 

2) Ainda no 3ML Editor anote a oitava da primeira nota de cada �track�. Esta informa��o pode ser conseguida colocando-se o ponteiro do mouse sobre a primeira nota de cada "track" no grid, ao lado direito do piano virtual (veja imagem anexada: "getting_octave.png"). Ao passar o mouse sobre a nota, surgir� um bal�o (na "mesma cor" do "track") com o n�mero da oitava ap�s a letra "o", (exemplo: surgir� algo como "O5 V8 Gate24", isso quer dizer que a nota est� na oitava 5). Fa�a isso para cada um dos tracks.

3) Ainda no 3ML Editor, exporte o MML (como tipo "MabiMML Compatible Format") para o clipboard ("File > Export MML to Clipboard").   Selecione (na janela de exporta��o, � esquerda) quais tracks ser�o exportados.

4) Cole o arquivo no bloco de nota e salve como "mml.txt". 

5) Mova este arquivo ("mml.txt") para a pasta onde est� o Midi2PLAY. 

6) Agora � necess�rio fazer uma r�pida "formata��o" no arquivo para que possa ser lido corretamente pelo Midi2PLAY. 
 


4. Formatando o arquivo "mml.txt"

    ------------------------------------------------- Formata��o -----------------------------------------------------

  Esta etapa � muito importante. Se o arquivo "mml.txt" n�o for formatado corretamente o Midi2PLAY n�o conseguir� converter o arquivo.

  � recomend�vel que juntamente com estas instru��es de formata��o, voc� veja os arquivos presentes na pasta "Formatation Examples". Os arquivos citados nesta se��o est�o presentes nesta pasta.

A formata��o consiste em dois passos:

1) Remover do arquivo "mml.txt" tudo que n�o sejam as linhas de strings e os "[Channel ]" (veja "formatting_step1.jpg"). 
2) Apagar as indica��es de compasso duplicadas (veja "formatting_step2.jpg", o EXEMPLO 1 abaixo e a se��o "Dicas" deste manual).
3) N�o se esque�a de manter o caractere  "]" ao fim do documento.

  Se houver alguma indica��o de compasso duplicada, voc� ter� que remov�-la manualmente do arquivo "mml.txt":

EXEMPLO 1   -  Removendo duplica��es nas indica��es de compasso

Veja abaixo que h� dois "/*M 1*/" dentro no canal 1.

----------------------------------"mml.txt"---------------------------------
[Channel1]
/*M 0  */  >d4&d16&d64r32.<f16d16a+4&a+16&a+64r32.f16>d16
/*M 1  */  c32d32c32d32c32d32c32<a+32>c32<a+32>c32<a+32a+32a32a16a+8.&a+64r32.<a+8.&a+64
/*M 1  */  r32.
/*M 2  */  >a+4&a+16&a+64r32.a+16>d16c4&c16&c64r32.<g16e16
/*M 3  */  >c16<a+16a16a+16a8>c8c8<a16a+16a16a+16a16a+16
...
-----------------------------------------------------------------------------

Ap�s rodar o "Midi2PLAY" o arquivo "temp.txt" conter� a seguinte sa�da:


------------------------------"temp.txt"-----------------------------------------

[C1]/*M1*/[C2][C3]


-------------------------------------------------------------------------------

Informando que a indica��o  /*M1*/ est� duplicada no canal 1  ("[C1]")

Edite o arquivo, eliminando apenas o segundo  "/*M 1 */". O resultado dever� ficar (mais ou menos) assim: 

/*M 0  */  >d4&d16&d64r32.<f16d16a+4&a+16&a+64r32.f16>d16
/*M 1  */  c32d32c32d32c32d32c32<a+32>c32<a+32>c32<a+32a+32a32a16a+8.&a+64r32.<a+8.&a+64
           r32.
/*M 2  */  >a+4&a+16&a+64r32.a+16>d16c4&c16&c64r32.<g16e16
/*M 3  */  >c16<a+16a16a+16a8>c8c8<a16a+16a16a+16a16a+16


Obs.: N�o importa a tabula��o (quantidade de espa�os) deixada. Basta apagar o segundo "/*M 1 */", de barra a barra.

A fase de formata��o est� agora conclu�da, isto �, o arquivo j� est� pronto para ser convertido no Midi2PLAY.

-----------------------------------------------fim da etapa de formata��o--------------------------------------------------


(continua��o)
7) Ap�s a formata��o salve o arquivo.
8) Execute novamente o Midi2PLAY, insira os dados conforme o programa vai solicitando: se deseja ou n�o concatenar os compassos (sobre isso veja o EXEMPLO 3 mais abaixo) e depois a oitava (apenas o n�mero) em que cada canal inicia. Basta digitar cada valor e teclar ENTER.
9) O resultado poder� ser visto no arquivo "play.txt". 
10) Para finalizar apague as indica��es de canal ("[Channel]") e inicialize as matrizes e loop (for/next), como abaixo (EXEMPLO 2), e salve o arquivo como ".BAS".


5. Exemplo de utiliza��o:

Abaixo temos o arquivo "play.txt", que nada mais � que o "mml_ready.txt" (da pasta "Formatation Examples") ap�s convers�o efetuada pelo Midi2PLAY. Trata-se de uma m�sica polif�nica com 3 canais/tracks. 

EXEMPLO 2

--------------------------------------"play.txt"-------------------------------------------------

[Channel1]
10 A$(1)="o4g8.a8o5c16o4b8.g8.o5c8.d8"
20 A$(2)="f16e8.d8.d+8.d8c16o4a+8."
30 A$(3)="o5d+8.a+8.g8d+16d8.g8e4"
40 A$(4)="e16"
[Channel2]
50 B$(1)="o5e8o4g16o5d8o4a16o5c8o4g16a8o5c16e8o4g16o5d8"
60 B$(2)="o4a16o5c8o4g16o5c8g16g+8g16f8d+16d8"
70 B$(3)="c16o4a+8o5d16d+8f16d+8c16f16d16o4a16o5d16o4b16a4"
80 B$(4)="a16"
[Channel3]
90 C$(1)="o4g8o5c16d8f16e8c16d8a16g8c16d8"
100 C$(2)="f16e8c16g8b16o6c8o5a+16g+8g16f8"
110 C$(3)="d+16d8o4a+16o5a+8o6c16o5a+8g16a16f16d16g16e16d4"
120 C$(4)="d16" 
----------------------------------------------------------------------------------------------------

Como pode-se notar nosso programa em BASIC est� quase pronto, j� temos no arquivo "play.txt" as linhas e as matrizes com as strings de cada canal. Precisamos agora apenas apagar os "[Channel ]", inicializar as matrizes e criar um la�o para gerar execu��o simult�nea de cada canal:

-------------------------------------------"GALAGA.BAS"-----------------------------------------------------------

5 DIM A$(4): DIM B$(4): DIM C$(4)
7 T$="s9m50000t100"
10 A$(1)="o4g8.a8o5c16o4b8.g8.o5c8.d8"
20 A$(2)="f16e8.d8.d+8.d8c16o4a+8."
30 A$(3)="o5d+8.a+8.g8d+16d8.g8e4"
40 A$(4)="e16"
50 B$(1)="o5e8o4g16o5d8o4a16o5c8o4g16a8o5c16e8o4g16o5d8"
60 B$(2)="o4a16o5c8o4g16o5c8g16g+8g16f8d+16d8"
70 B$(3)="c16o4a+8o5d16d+8f16d+8c16f16d16o4a16o5d16o4b16a4"
80 B$(4)="a16"
90 C$(1)="o4g8o5c16d8f16e8c16d8a16g8c16d8"
100 C$(2)="f16e8c16g8b16o6c8o5a+16g+8g16f8"
110 C$(3)="d+16d8o4a+16o5a+8o6c16o5a+8g16a16f16d16g16e16d4"
120 C$(4)="d16" 
2000 PLAY T$, T$, T$
2010 FOR X=1 to 4
2020 PLAY A$(X), B$(X), C$(X)
2030 NEXT X
--------------------------------------------------------------------------------------------

Agora basta grav�-lo como .BAS para utiliza��o no MSX.

------------------------------------------------------------------------------------------------------------


6. Concatenando compassos.

No Midi2PLAY h� a op��o de o usu�rio escolher se deseja ou n�o concatenar os compassos. 
Se a op��o de concatenar compassos for selecionada, lhe ser� perguntado quantos compassos por linha. Pode-se concatenar 2, 3 ou 4 compassos por linha.

Abaixo o mesmo "mml_ready.txt" mas aqui foi escolhida concatena��o de 2 compassos por linha:

EXEMPLO 3

[Channel1]
10 A$(1)="o4g8.a8o5c16o4b8.g8.o5c8.d8f16e8.d8.d+8.d8c16o4a+8."
20 A$(2)="o5d+8.a+8.g8d+16d8.g8e4e16"
[Channel2]
30 B$(1)="o5e8o4g16o5d8o4a16o5c8o4g16a8o5c16e8o4g16o5d8o4a16o5c8o4g16o5c8g16g+8g16f8d+16d8"
40 B$(2)="c16o4a+8o5d16d+8f16d+8c16f16d16o4a16o5d16o4b16a4a16"
[Channel3]
50 C$(1)="o4g8o5c16d8f16e8c16d8a16g8c16d8f16e8c16g8b16o6c8o5a+16g+8g16f8"
60 C$(2)="d+16d8o4a+16o5a+8o6c16o5a+8g16a16f16d16g16e16d4d16" 


Obs.: Ao selecionar esta op��o deve-se tomar o cuidado para a string n�o ultrapassar os 255 caracteres, pois este � o tamanho m�ximo de string suportado pelo MSX-BASIC. 

--------------------------------------------------------------------------------------------------------------------


7. Dicas:

Descobrindo automaticamente as indica��es de compasso duplicadas.

    Para descobrir automaticamente quais as indica��es de compasso duplicadas, primeiro deixe o arquivo como visto em "formatting_step1.jpg". Execute o Midi2PLAY (insira a quantidade correta de compassos, n�o concatenar compassos e qualquer valor para as oitavas). O programa gerar� o arquivo "temp.txt", nele podem ser vistas as indica��es duplicadas. Se n�o houver nenhum *M* em "temp.txt" � que n�o h� indica��es duplicadas. Obs3.: Este m�todo � �til para m�sicas longas, com muitos compassos, onde torna-se dif�cil e trabalhoso procurar por duplica��es em cada um dos tracks.



8. Limita��es e problemas conhecidos.

  � necess�rio alertar aos usu�rios que o programa ainda possui algumas limita��es. Na atual vers�o mostrou-se consistente na convers�o de muitos dos arquivos "mml" gerados pelo 3ML Editor, por�m  alguns ainda podem apresentar imprecis�es na convers�o.  

Entre os problemas mais frequentes constam:

1) Oitava imprecisa. 
Ao rodar o Midi2Play a aplica��o pede para que seja informada a oitava da nota inicial e utilizando-se desta como refer�ncia, converte todas as outras notas subsequentes, respeitando as indica��es de mudan�a de oitava assinaladas pelos sinais ">" ou "<".  Alguns destes s�mbolos podem ser "duplicados" e o resultado disso � que ap�s a convers�o, o track soar� uma oitava acima ou uma oitava abaixo. 
  
  Esse problema � facilmente contorn�vel se o usu�rio editar manualmente o arquivo "mml.txt" no local onde ocorre o problema (geralmente pr�ximo ao in�cio de algum canal). Pode-se for�ar a oitava correta apagando-se manualmente um ou outro s�mbolos "<" ou ">" ou inserindo a letra "o" e o n�mero da oitava correta (por exemplo.: "o5"). Pode-se tamb�m informar outra oitava da nota inicial (nota refer�ncia) ao rodar o Midi2Play.

2) Pausas indesejadas.
Outro problema que pode aparecer e este s� � percept�vel ap�s escutar-se a m�sica convertida, � o surgimento de pausas indesejadas no decorrer da execu��o.  Isso geralmente ocorre em alguns arquivos midi onde o 3ML Editor trunca as vozes, fazendo com que algumas das pausas sejam longa demais em rela��o aos "compassos" que ele cria. 
 Para contornar este problema h� tr�s poss�veis solu��es:
1)  Tenta-se encontrar outro arquivo Midi da m�sica que se queira converter (um arquivo em que cada track esteja corretamente editado ou separado)*.
2) Escolha uma concatena��o de compassos diferente (de 2 a 4 compassos por linha). Esta a��o � feita automaticamente pelo programa (veja se��o 5 ou EXEMPLO 3 deste manual).
3) Outra solu��o � "consertar" o arquivo manualmente, encontrando as pausas longas pr�ximas ao fim do compasso. Diminuindo o valor desta pausa faz com que a m�sica flua normalmente. 

*Nem todos os arquivos ".mid" s�o aproveit�veis. Dependendo do arquivo os canais podem estar truncadas o que far� com que o 3ML Editor n�o o abra corretamente. Procure por arquivos que contenham as vozes separadas (como por exemplo neste link: http://stringsound.com/Page12.html ). 	

3) Problemas de sincronia entre tracks:
Algumas pausas mal colocadas (pelo 3ML Editor) tamb�m podem gerar falta de sincronismo entre os tracks. Esta falta de sincronismo geralmente � breve e perduram por um ou dois compassos.

Algumas m�sicas polif�nicas (2 ou mais canais) que apresentem anacruse, onde as pausas iniciais n�o est�o especificadas de forma correta no arquivo .mid, podem apresentar problemas de sincronia em alguns compassos, no decorrer da execu��o (do arquivo .BAS).
 Uma poss�vel solu��o pra esse problema � corrigir manualmente as vozes nos compassos onde aparece a anacruse, inserindo (no 3ML Editor) as devidas pausas no compasso inicial da m�sica.
					
4) Outros problemas:
Se a m�sica n�o foi convertida corretamente, verifique se todos os passos da formata��o foram seguidos � risca.
Exemplo:
Formatou corretamente o "mml.txt"?
Apagou as indica��es de compasso (/M*_/) duplicadas? Verifique o arquivo "temp.txt" a cada convers�o para ver se ainda h� alguma.
Acrescentou o "]" ao final deste documento ("mml.txt")?

5) Problemas (ou erros) ao executar no MSX:
Verifique se faltou deletar algum caractere remanescente da sintaxe mml ("[", ou "[Channel]", ou "]").
Verifique se dimensionou corretamente o tamanho das matrizes para cada voz.
Veja se alguma linha ultrapassou os 255 caracteres pois este � o tamanho m�ximo de string suportado pelo MSX-BASIC. Strings muito longas tamb�m podem gerar um pequeno delay e comprometer um pouco o sincronismo. 

Se acaso houver alguma discrep�ncia em rela��o � oitava. Verifique se cada track/canal do arquivo convertido inicia com a oitava correta. 

     Voc� tamb�m pode alterar alguns par�metros no momento da importa��o do arquivo Midi ("Import Settings" no 3ML Editor):

Selecione: reduce rest

Se o arquivo ou m�sica possui muitos ornamentos ou notas r�pidas (que fa�am com que a m�sica sofra "pequenas travadas" no momento em que s�o executadas no MSX), experimente diminuir o "Quantization Settings" no momento de import�-las no 3ML Editor (na janela "Import Settings"). Por exemplo se estiver em 1/64 altere para 1/32, ou altere de 1/32 para 1/16.


Considera��es finais:

N�o tive tempo de efetuar todos os testes necess�rios, portanto se poss�vel ajude reportando qualquer bug para o seguinte e-mail:   
rrivas2009@gmail.com
 Cr�ticas e sugest�es tamb�m s�o bem-vindas!    



-----------------------------------------------------------------------------------------------------------------------

Copyright 2018 Rodrivas78

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.




