<!DOCTYPE HTML>
<html lang="pt-br">
	
# O Modelo do Dilema do Prisioneiro
	
#### Prof. Nelson Canzian da Silva

#### Autor : Paola dos Santos Balestieri

<meta charset="UTF-8">

</head>

<p>O estudo de sistemas complexos é realizado teoricamente através da introdução de modelos relativamente simples que imitam o comportamento real
daqueles sistemas. Além das propriedades de equilíbrio e não equilíbrio dos
sistemas, tais modelos permitem também uma avaliação do comportamento
crítico dos sistemas, quando existente. Um exemplo interessante de modelo
matemático para o estudo de sistemas complexos é o chamado modelo do
dilema do prisioneiro (PD- Prisoner's Dilemma ), que aqui será apresentado. 
<p>De um ponto de vista puramente físico, mesmo a versão mais simples do
modelo pode apresentar comportamento caótico, diferentes fases absorventes,
coexistência de estados e transições de fases entre os estados absorventes e a
coexistência.  O modelo PD contém quatro ingredientes, que convenientemente defindos, podem imitar sistemas reais num ampla gama de áreaa de pesquisa:
os jogadores, suas estratégias, a recompensa recebida ao vencer uma partida
e uma dinâmica evolucionária de atualização dos estados do sistema. Nessa
versão, os jogadores são colocados sobre uma rede quadrada e os oponentes
de cada jogador podem ser escolhidos entre todos outros jogadores ou entre
jogadores colocados em uma certa região (primeiros vizinhos, por exemplo).
Considere que N jogadores idênticos possam assumir apenas duas estratégias: cooperação( C ) e deserção (ou não cooperação) ( D ). 
A regra de evolução para novas configurações pode ser especificada, por
exemplo, através da recompensa que seria recebida por um jogador e seu
oponente. Assim, se a recompensa recebida pelo jogador for maior ou igual
àquela recebida pelo seu oponente, o jogador permanece com sua estratégia.
Por outro lado, ele muda sua estratégia para aquela do oponente. Neste situação a tomada de decisão é completamente racional e semelhante à taxa de transição de Fermi-Dirac:

$$ w = \frac{1}{\left( 1+ e^{\frac{Ep - Eo}{K}} \right)}$$


<p> em T = 0 , se pensarmos no valor da recompensa como sendo o valor da energia. Para incluir algum grau de irracionalidade é possível definir uma probabilidade de transição para a mudança de estratégia
que leve em conta os valores das recompensas que seriam recebidos pelo jogador e pelo oponente e algum parâmetro capaz de incluir ruído nesta decisão Tal taxa, por exemplo, pode ser baseada na expressão de Fermi-Dirac com T &ne; 0 . É importante ressaltar que diferentes modos podem ser escolhidos para escolher o oponente de um jogador. Assim, um oponente pode ser
aleatoriamente escolhido ou pode ser aquele com maior recompensa a receber
dentro de uma certa vizinhança do jogador escolhido, podendo-se, ou não,
incluir auto-interação (que ocorre quando os jogadores levam em conta suas
estratégias para a determinação da recompensa a ser recebida). 
<p>Para se obter um resultado estocástico usou-se o método de Monte Carlo, que é  uma técnica estatística que se baseia em amostragens aleatórias para obter resultados numéricos. Repetindo-se sucessivas simulações de um modelo pode-se determinar a probabilidade de ocorrência
de determinado estado do sistema ou mesmo o cálculo de grandezas físicas
de interesse. Nessa versão do modelo do dilema do prisioneiro evolucionário os jogadores serão colocados sobre os sítios de uma rede quadrada de
comprimento linar L e uma variável \begin{eqnarray} S_i & = &  +1 ( S = −1 )\end{eqnarray} será assinalada para
um cooperador <i> i</i> com <i>i</i> = 1, .., L&sup2; 
<p>Um jogador p e um oponente
o serão aleatoriamente escolhidos. Se eles se enontrarem no mesmo estado,
nada acontece. Caso contrário será determinada uma dada probabilidade
de que o jogador p assuma o estado do seu oponente. Este procedimento é
repetido L &sup2;  vezes, permitindo definir a unidade de tempo como a chance de
todos os jogadores tentarem mudar, ao menos uma vez, seu estado. Em cada
unidade de tempo determinaremos a densidade de cooperadores e deserto-
res. Após um intervalo de tempo transiente estas grandezas atingem valores
estacionários, permitindo o cálculo de seus valores médios e a especificação
da fase do sistema (coexistencia de cooperadores e desertores ou o completo
preenchimento da rede com um dos elementos.
Para a determinação de ordem da transição e dos expoentes críticos associados utilizaremos as teorias de escala estacionária e dinâmica, nas quais
o parâmetro de ordem do sistema (densidade de cooperadores ou desertores)
obedece a relações matemáticas do tipo potência com o tempo (dinâmica)
ou com os parâmetros de tentação e ruído (estacionária).
<p>Para observar essa modelo físico, fez-se uma simulação utilizado a linguagem de programação Javascript, onde nessa simulação é possivel observar a evolução do modelo com base em parâmetros que pode ser definido pelo usuário, esses parâmetros são: <ul><li> Tamanho da rede</li> <li>Energia de interação do jogador coperator</li><li> Energia de interação do jogador defactor</li> <li> Temperatura</li></ul> O parâmetro tamanho da rede, serve para defenir as dimensões que a rede terá, já que por definição a rede é quadrada, então o usuário pode definir sua largura. A energia de interação dos jogadores, representa o quanto de domínio cada jogador tem sobre as suas jogadas, se a energia de interação de um for maior do que a do outro, isso significa que a probabilidade, que o jogador com energia maior tem de ganhar é maior. Porém, a energia do jogador a é dada pela expreção:
\begin{eqnarray} E_a & = a + S\end{eqnarray} e a do jogador defector é dado por \begin{eqnarray} E_b & = b S\end{eqnarray}
onde esse <b>S</b> representa o Delta de Kronecker.  Por tanto a probabilidade do jogador defector ganhar, quando o usuario selecionar a mesma energia de interação para os dois jogadores, é maior, já que seu E é sempre maior, quando suas energiar de intereção forem iguais. O que significa que para uma T = 0, para o coperator ganhar do defector, em qualquer tamanho de rede, sua energia de interação tem que ser maior do que a do coperator. 
<p> Já o parâmetro temperatura representa também uma energia de interação, já que quanto maior essa temperatura menos os jogadores se rederão ao jogo do adversário. Considerando um caso em que o usuário selecione a mesma energia de interação para os dois jogadores, porém adicione uma temperatura	&gt; 0 ao sistema, o jogador coperator terá chances de ganhar, mesmo que o E do defector seja maior, pois a temperatura adicionou ao comportamento do jogador coperator, uma vontade de permanecer em seu estado, fazendo assim, com que a rede não transite tão rápido para o estado de densidade 1 para defector.
<div style="text-align:center">
<input type="button" value="Simulação" onClick="botao()">
</div>

</body>
</html>
