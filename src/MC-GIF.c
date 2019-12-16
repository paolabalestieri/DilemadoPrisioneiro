/*
   * todo jogador joga: primeiro os jogadores sao colocados em uma
   * fila desordenada. para cada jogador desta fila, escolhemos
   * aleatoriamente um dos vizinhos para ser o adversario.
   * autores: G.L.Nunes, P.S.Balestieri e V.Rech
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

/*
   definicoes abaixo permitem acessar os quatro vizinhos 
   numa lista unidimensional que simula uma  regiao
   bidimensional
*/

#define direita(k)      (((k+PASSO) >= N) ? k+PASSO-N : k+PASSO)
#define esquerda(k)     (((k-PASSO) < 0) ? k-PASSO+N : k-PASSO)
#define acima(k)        (((k+VOLTA) >= N) ? k+VOLTA-N : k+VOLTA)
#define abaixo(k)       (((k-VOLTA) < 0) ? k-VOLTA+N : k-VOLTA)

#define cooperator	1
#define defector	-1

/* o delta de Kronecker */
#define delta(a,b)	((a == b) ? 1 : 0)

void embaralha(int *,int);
double transicao(double, double);

int main(int argc, char **argv){
	int k; /*	variavel temporaria*/
	int L,N;  /* lado e area do retangulo */
	double b, w, a, bant;
	int soma;
	double densidade;
	double b1,b2,K,delta_b;
	int MC,pontos;
	FILE *f1=popen("gnuplot","w");
	
	L=100;
	MC=1000;
	if (argc == 5){
/*	    L = atoi(argv[1]);*/
	    b = atof(argv[1]);
	    a = atof(argv[2]);
	    K = atof(argv[3]);
/*	    MC = atoi(argv[4]);*/
	}
  	else{
    	printf("%s b a K nome.gif\n",argv[0]);
    	//puts("L  comprimento do quadrado");
    	puts("b ");
    	puts("a ");
    	//puts("b1 valor inferior de b (numero real) ");
    	//puts("b2 valor superior de b (numero real) ");
    	puts("K = eh um numero real ");
    	//puts("MC eh um inteiro, passos de MonteCarlo ");

    	return(1);
  	}

  	N = L*L;

  	//pontos = 5;
  	//delta_b=(b2-b1)/(1.0*pontos);

	srand(time(NULL));
	srand48(time(NULL));
	
	//while(a<10){
  		//for(b=b1;b<b2; b += delta_b){  /* loop dos bs  */
    		signed char s[N];
    		int n,j;
    		int jogador;  /* posicao do jogador da vez */
    		int aqui, adv, adver; /* adv=temporario adver=escolhido e do adversario  */
    		int PASSO, VOLTA, m;
    		int mc;   /* passo de monte carlo */
    		int yy[N], *zz;
    		double r, Ej, Ea;  /* Ej=EnergiaJogador Ea=EnergiaAdversario */

    		PASSO = 1;
    		VOLTA = L;


  			{ /* a coisa comeca aqui */
			 /* escolhemos inteiros de 0 a N em desordem */
    		zz = yy;
    		embaralha(zz,N);

			/*  escolhemos os defectors e cooperators */
    		for (n=0;n<N;n++){
     			k = rand()%2;
     			if (k!=0)
      				s[n]=1;
     			else s[n]=-1;
    		}
/*			for(n=0;n<N;n++){*/
/*     			if (n==L*L/2+L/2){s[n]=1;}*/
/*     			else{s[n]=-1;}*/
/*			}*/

			fprintf(f1,"set terminal gif enhanced animate\nset output \"%s\"\nset xrange [0:%d]\nset yrange [0:%d]\nset cbrange[-1:1]\nunset key\n",argv[4],L,L);
   			for (mc=0;mc<MC;mc++){  /* inicio dos tempos */
   				densidade = 0.0;
	    		j = 0;
    			for(n=0;n<N;n++){
					if (s[n] == 1) j++;
				}
   				densidade = (1.0*j)/(1.0*N);
   				
   				fprintf(f1,"set title \"b=%.2lf     a=%.2lf     K=%.2lf \\n{/*0.8 Densidade=%.2lf} \"\n",b,a,K,densidade);
  				/*
     			aqui comeca o jogo
  				*/
    			for (n=0;n<N;n++){
      				jogador = zz[n];
      				/* escolhemos um adversario */
      				adv = rand()%4;
      				switch(adv){
        				case 0:
	 					adver = direita(jogador);
						break;

						case 1:
	 					adver = esquerda(jogador);
	 					break;

						case 2:
	 					adver = acima(jogador);
	 					break;

						case 3:
	 					adver = abaixo(jogador);
	 					break;
      				}

      				if ( s[jogador] != s[adver] ){
		        		/* payoff do jogador */
						aqui = jogador;
        				soma = 0.0;
        				/* olhar os quatro vizinhos */
        				m = direita(aqui);
        				soma += 1.0*delta(s[aqui],s[m]);
        				m = esquerda(aqui);
        				soma += 1.0*delta(s[aqui],s[m]);
        				m = acima(aqui);
        				soma += 1.0*delta(s[aqui],s[m]);
        				m = abaixo(aqui);
        				soma += 1.0*delta(s[aqui],s[m]);
        				if ( s[aqui] == cooperator ) Ej = a + soma;
						else Ej = b*soma;

        				/* payoff do adversario */
						aqui = adver;
        				soma = 0.0;
        				/* olhar os quatro vizinhos */
        				m = direita(aqui);
        				soma += 1.0*delta(s[aqui],s[m]);
        				m = esquerda(aqui);
        				soma += 1.0*delta(s[aqui],s[m]);
        				m = acima(aqui);
        				soma += 1.0*delta(s[aqui],s[m]);
        				m = abaixo(aqui);
        				soma += 1.0*delta(s[aqui],s[m]);
        				if ( s[aqui] == cooperator ) Ea = a + soma;
						else Ea = b*soma;

       					w = transicao(Ej-Ea,K);

						/* decidimos agora se muda a estrategia */
						r = drand48();
						if (r <= w) s[jogador] = s[adver];
      				}
      
    			} /* fim do jogo...calcular a densidade agora */
				
				fprintf(f1,"plot '-' u 1:2:3 with points pt 7 ps 1 palette\n");
				for(n=0;n<=L*L;n++){
					fprintf(f1,"%d %d %d\n",n-(n/L)*L,n/L,s[n]);
				}
				fprintf(f1,"e\n");
   				
   				if(densidade==0.0||densidade==1.0){ break;}
    		}  /* fim dos tempos */

  			} /* fim de a coisa comeca aqui */

/*    		densidade = 0.0;*/
/*    		j = 0;*/
/*    		for(n=0;n<N;n++){*/
/*				if (s[n] == 1) j++;*/
/*			}*/
/*   */
/*   			densidade = (1.0*j)/(1.0*N);*/

/*			if(densidade!=1.0){*/
/*	   			printf("%f %f\n",a,b);*/
/*	   			a+=0.5;*/
/*   			}*/
   			fflush(NULL);
		//} /* loop dos bs */
	//}
	return(0);
}

/*
  a funcao abaixo retorna, no ponteiro  u, uma lista com os numeros
  0,1,2,3,4,....,LL  desordenados
  o valor de LL  nao deve ultrapassar 500.000 
  ou L = 707         
*/
void embaralha(int *u, int LL ){
	int max,j;
	int k,n, xx[LL];

  	for (n=0; n<LL;n++){
    	xx[n]=n;
	}

  	srand(time(NULL));

  	max = LL-1;
  	for (k=LL;k>0;k--){
    	j=rand()%k;
    	u[k-1]=xx[j];

    	/* retira a posicao j de xx */
    	for(n=j;n<max;n++)
     		xx[n]=xx[n+1];
    	max--;

  	}
}

double transicao(double E, double K){
	double y;
        
	if ( K == 0.0 ){
    	if (E <= 0.0) y = 1.0;
        else y = 0.0;
	}
	else
		y = 1.0/(1.0 + exp(E/K));
        
	return(y);
}
// gcc MC-GIF.c -lm
// ./a.out b a k nome.gif

