

				       Midi2PLAY v.1.0  (for Windows 32/64)
				           by  Rodrivas78 


Sumário:
1. Introdução
2. Compatibilidade
3. Guia rápido 
4. Formatação (do arquivo "mml.txt")
5. Exemplo de utilização
6. Concatenando compassos
7. Dicas 
8. Limitações e problemas conhecidos 
9. Considerações finais 



1. Introdução

 O "Midi2PLAY" é uma ferramenta que auxilia no processo de conversão de arquivos MIDI (.mid) tornando-os compatíveis 
com a sintaxe aceita pelo comando "PLAY" do MSX-BASIC. 

 Este programa funciona como extensão do programa 3ML Editor, isto é, depende deste para efetuar o processo de conversão. 
O 3ML Editor é gratuito e pode ser baixado no link:  http://3ml.jp/download.html  (No momento em que este manual é redigido está na versão: 2.0.3)

  Resumo do processo de conversão:

 Arquivo MIDI --> 3ML Editor --> Arquivo MML(.txt) --> Midi2PLAY --> Arquivo .BAS  

1)  Importar o arquivo MIDI no 3ML Editor. 
2)  Ainda no 3ML Editor: exportar o arquivo MML. (Salvar como "mml.txt")
3)  Executar o "Midi2PLAY" (com o "mml.txt" na mesma pasta, adequadamente formatado)
4)  Será gerado o arquivo "play.txt". Basta salvá-lo como ".bas" e utilizá-lo no MSX. 

   Fica-se compreendido que o Midi2PLAY poderia (ou deveria!) se chamar "mml2play", visto que sua função é a conversão da sintaxe "mml" (Music Macro Language) para a sintaxe aceita pelo comando PLAY. Mas como o formato "MML" não é tão conhecido, e para que a função do programa torne-se autoexplicativa, optei pelo nome atual.  


2. Compatibilidade:
    
  O Midi2PLAY é compatível com Windows 32/64 (em breve também p/ iOS).  
  A sintaxe gerada por ele é compatível com qualquer versão de MSX (desde o MSX1), sem necessidade de harware adicional como MSX-Audio ou MSX-Music/FM-Pac. 
                                                    


3. Guia rápido / Quick Guide

A conversão do arquivo MIDI (para ser executado pelo comando PLAY do MSX) ocorre em duas etapas: 

1) No 3ML Editor importa-se o arquivo MIDI (.mid) (File > Import Standar MIDI file). 

Obs.: Se o arquivo possuir mais de 3 canais/tracks, você terá que escolher apenas 3 dos canais pois é o máximo que o PSG do MSX suporta. 

2) Ainda no 3ML Editor anote a oitava da primeira nota de cada “track”. Esta informação pode ser conseguida colocando-se o ponteiro do mouse sobre a primeira nota de cada "track" no grid, ao lado direito do piano virtual (veja imagem anexada: "getting_octave.png"). Ao passar o mouse sobre a nota, surgirá um balão (na "mesma cor" do "track") com o número da oitava após a letra "o", (exemplo: surgirá algo como "O5 V8 Gate24", isso quer dizer que a nota está na oitava 5). Faça isso para cada um dos tracks.

3) Ainda no 3ML Editor, exporte o MML (como tipo "MabiMML Compatible Format") para o clipboard ("File > Export MML to Clipboard").   Selecione (na janela de exportação, à esquerda) quais tracks serão exportados.

4) Cole o arquivo no bloco de nota e salve como "mml.txt". 

5) Mova este arquivo ("mml.txt") para a pasta onde está o Midi2PLAY. 

6) Agora é necessário fazer uma rápida "formatação" no arquivo para que possa ser lido corretamente pelo Midi2PLAY. 
 


4. Formatando o arquivo "mml.txt"

    ------------------------------------------------- Formatação -----------------------------------------------------

  Esta etapa é muito importante. Se o arquivo "mml.txt" não for formatado corretamente o Midi2PLAY não conseguirá converter o arquivo.

  É recomendável que juntamente com estas instruções de formatação, você veja os arquivos presentes na pasta "Formatation Examples". Os arquivos citados nesta seção estão presentes nesta pasta.

A formatação consiste em dois passos:

1) Remover do arquivo "mml.txt" tudo que não sejam as linhas de strings e os "[Channel ]" (veja "formatting_step1.jpg"). 
2) Apagar as indicações de compasso duplicadas (veja "formatting_step2.jpg", o EXEMPLO 1 abaixo e a seção "Dicas" deste manual).
3) Não se esqueça de manter o caractere  "]" ao fim do documento.

  Se houver alguma indicação de compasso duplicada, você terá que removê-la manualmente do arquivo "mml.txt":

EXEMPLO 1   -  Removendo duplicações nas indicações de compasso

Veja abaixo que há dois "/*M 1*/" dentro no canal 1.

----------------------------------"mml.txt"---------------------------------
[Channel1]
/*M 0  */  >d4&d16&d64r32.<f16d16a+4&a+16&a+64r32.f16>d16
/*M 1  */  c32d32c32d32c32d32c32<a+32>c32<a+32>c32<a+32a+32a32a16a+8.&a+64r32.<a+8.&a+64
/*M 1  */  r32.
/*M 2  */  >a+4&a+16&a+64r32.a+16>d16c4&c16&c64r32.<g16e16
/*M 3  */  >c16<a+16a16a+16a8>c8c8<a16a+16a16a+16a16a+16
...
-----------------------------------------------------------------------------

Após rodar o "Midi2PLAY" o arquivo "temp.txt" conterá a seguinte saída:


------------------------------"temp.txt"-----------------------------------------

[C1]/*M1*/[C2][C3]


-------------------------------------------------------------------------------

Informando que a indicação  /*M1*/ está duplicada no canal 1  ("[C1]")

Edite o arquivo, eliminando apenas o segundo  "/*M 1 */". O resultado deverá ficar (mais ou menos) assim: 

/*M 0  */  >d4&d16&d64r32.<f16d16a+4&a+16&a+64r32.f16>d16
/*M 1  */  c32d32c32d32c32d32c32<a+32>c32<a+32>c32<a+32a+32a32a16a+8.&a+64r32.<a+8.&a+64
           r32.
/*M 2  */  >a+4&a+16&a+64r32.a+16>d16c4&c16&c64r32.<g16e16
/*M 3  */  >c16<a+16a16a+16a8>c8c8<a16a+16a16a+16a16a+16


Obs.: Não importa a tabulação (quantidade de espaços) deixada. Basta apagar o segundo "/*M 1 */", de barra a barra.

A fase de formatação está agora concluída, isto é, o arquivo já está pronto para ser convertido no Midi2PLAY.

-----------------------------------------------fim da etapa de formatação--------------------------------------------------


(continuação)
7) Após a formatação salve o arquivo.
8) Execute novamente o Midi2PLAY, insira os dados conforme o programa vai solicitando: se deseja ou não concatenar os compassos (sobre isso veja o EXEMPLO 3 mais abaixo) e depois a oitava (apenas o número) em que cada canal inicia. Basta digitar cada valor e teclar ENTER.
9) O resultado poderá ser visto no arquivo "play.txt". 
10) Para finalizar apague as indicações de canal ("[Channel]") e inicialize as matrizes e loop (for/next), como abaixo (EXEMPLO 2), e salve o arquivo como ".BAS".


5. Exemplo de utilização:

Abaixo temos o arquivo "play.txt", que nada mais é que o "mml_ready.txt" (da pasta "Formatation Examples") após conversão efetuada pelo Midi2PLAY. Trata-se de uma música polifônica com 3 canais/tracks. 

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

Como pode-se notar nosso programa em BASIC está quase pronto, já temos no arquivo "play.txt" as linhas e as matrizes com as strings de cada canal. Precisamos agora apenas apagar os "[Channel ]", inicializar as matrizes e criar um laço para gerar execução simultânea de cada canal:

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

Agora basta gravá-lo como .BAS para utilização no MSX.

------------------------------------------------------------------------------------------------------------


6. Concatenando compassos.

No Midi2PLAY há a opção de o usuário escolher se deseja ou não concatenar os compassos. 
Se a opção de concatenar compassos for selecionada, lhe será perguntado quantos compassos por linha. Pode-se concatenar 2, 3 ou 4 compassos por linha.

Abaixo o mesmo "mml_ready.txt" mas aqui foi escolhida concatenação de 2 compassos por linha:

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


Obs.: Ao selecionar esta opção deve-se tomar o cuidado para a string não ultrapassar os 255 caracteres, pois este é o tamanho máximo de string suportado pelo MSX-BASIC. 

--------------------------------------------------------------------------------------------------------------------


7. Dicas:

Descobrindo automaticamente as indicações de compasso duplicadas.

    Para descobrir automaticamente quais as indicações de compasso duplicadas, primeiro deixe o arquivo como visto em "formatting_step1.jpg". Execute o Midi2PLAY (insira a quantidade correta de compassos, não concatenar compassos e qualquer valor para as oitavas). O programa gerará o arquivo "temp.txt", nele podem ser vistas as indicações duplicadas. Se não houver nenhum *M* em "temp.txt" é que não há indicações duplicadas. Obs3.: Este método é útil para músicas longas, com muitos compassos, onde torna-se difícil e trabalhoso procurar por duplicações em cada um dos tracks.



8. Limitações e problemas conhecidos.

  É necessário alertar aos usuários que o programa ainda possui algumas limitações. Na atual versão mostrou-se consistente na conversão de muitos dos arquivos "mml" gerados pelo 3ML Editor, porém  alguns ainda podem apresentar imprecisões na conversão.  

Entre os problemas mais frequentes constam:

1) Oitava imprecisa. 
Ao rodar o Midi2Play a aplicação pede para que seja informada a oitava da nota inicial e utilizando-se desta como referência, converte todas as outras notas subsequentes, respeitando as indicações de mudança de oitava assinaladas pelos sinais ">" ou "<".  Alguns destes símbolos podem ser "duplicados" e o resultado disso é que após a conversão, o track soará uma oitava acima ou uma oitava abaixo. 
  
  Esse problema é facilmente contornável se o usuário editar manualmente o arquivo "mml.txt" no local onde ocorre o problema (geralmente próximo ao início de algum canal). Pode-se forçar a oitava correta apagando-se manualmente um ou outro símbolos "<" ou ">" ou inserindo a letra "o" e o número da oitava correta (por exemplo.: "o5"). Pode-se também informar outra oitava da nota inicial (nota referência) ao rodar o Midi2Play.

2) Pausas indesejadas.
Outro problema que pode aparecer e este só é perceptível após escutar-se a música convertida, é o surgimento de pausas indesejadas no decorrer da execução.  Isso geralmente ocorre em alguns arquivos midi onde o 3ML Editor trunca as vozes, fazendo com que algumas das pausas sejam longa demais em relação aos "compassos" que ele cria. 
 Para contornar este problema há três possíveis soluções:
1)  Tenta-se encontrar outro arquivo Midi da música que se queira converter (um arquivo em que cada track esteja corretamente editado ou separado)*.
2) Escolha uma concatenação de compassos diferente (de 2 a 4 compassos por linha). Esta ação é feita automaticamente pelo programa (veja seção 5 ou EXEMPLO 3 deste manual).
3) Outra solução é "consertar" o arquivo manualmente, encontrando as pausas longas próximas ao fim do compasso. Diminuindo o valor desta pausa faz com que a música flua normalmente. 

*Nem todos os arquivos ".mid" são aproveitáveis. Dependendo do arquivo os canais podem estar truncadas o que fará com que o 3ML Editor não o abra corretamente. Procure por arquivos que contenham as vozes separadas (como por exemplo neste link: http://stringsound.com/Page12.html ). 	

3) Problemas de sincronia entre tracks:
Algumas pausas mal colocadas (pelo 3ML Editor) também podem gerar falta de sincronismo entre os tracks. Esta falta de sincronismo geralmente é breve e perduram por um ou dois compassos.

Algumas músicas polifônicas (2 ou mais canais) que apresentem anacruse, onde as pausas iniciais não estão especificadas de forma correta no arquivo .mid, podem apresentar problemas de sincronia em alguns compassos, no decorrer da execução (do arquivo .BAS).
 Uma possível solução pra esse problema é corrigir manualmente as vozes nos compassos onde aparece a anacruse, inserindo (no 3ML Editor) as devidas pausas no compasso inicial da música.
					
4) Outros problemas:
Se a música não foi convertida corretamente, verifique se todos os passos da formatação foram seguidos à risca.
Exemplo:
Formatou corretamente o "mml.txt"?
Apagou as indicações de compasso (/M*_/) duplicadas? Verifique o arquivo "temp.txt" a cada conversão para ver se ainda há alguma.
Acrescentou o "]" ao final deste documento ("mml.txt")?

5) Problemas (ou erros) ao executar no MSX:
Verifique se faltou deletar algum caractere remanescente da sintaxe mml ("[", ou "[Channel]", ou "]").
Verifique se dimensionou corretamente o tamanho das matrizes para cada voz.
Veja se alguma linha ultrapassou os 255 caracteres pois este é o tamanho máximo de string suportado pelo MSX-BASIC. Strings muito longas também podem gerar um pequeno delay e comprometer um pouco o sincronismo. 

Se acaso houver alguma discrepância em relação à oitava. Verifique se cada track/canal do arquivo convertido inicia com a oitava correta. 

     Você também pode alterar alguns parâmetros no momento da importação do arquivo Midi ("Import Settings" no 3ML Editor):

Selecione: reduce rest

Se o arquivo ou música possui muitos ornamentos ou notas rápidas (que façam com que a música sofra "pequenas travadas" no momento em que são executadas no MSX), experimente diminuir o "Quantization Settings" no momento de importá-las no 3ML Editor (na janela "Import Settings"). Por exemplo se estiver em 1/64 altere para 1/32, ou altere de 1/32 para 1/16.


Considerações finais:

Não tive tempo de efetuar todos os testes necessários, portanto se possível ajude reportando qualquer bug para o seguinte e-mail:   
rrivas2009@gmail.com
 Críticas e sugestões também são bem-vindas!    



-----------------------------------------------------------------------------------------------------------------------

Copyright 2018 Rodrivas78

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.




