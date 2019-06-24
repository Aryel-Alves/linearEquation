#include <stdio.h>
#include <stdlib.h>
#include <time.h> // permite utilizar comandos com utilização de data e hora
#include <locale.h> // permite a definição de uma lingua para a escrita do programa
#include <string.h>
#include <math.h>
#define E 0.001

double a, b, x, fa,fb, fx;

double funcao(double x) {
    return ((1/x) + (x*x) -5);
}

main()
{
	int escolha;
	void digiteAB(void);
	double funcao(double x); double xm(double a, double b); double bisseccao(); double falsa_posicao(); double gauss(); 
	
	setlocale(LC_ALL, "Portuguese"); // comando pra utilização de acento
	system("color f0"); // system("color XY"). onde X é a cor de fundo da tela e Y a cor da letra
	
	while (escolha!=5) // MENU 
	{
	
		printf("\n\n Escolha um metodo para determinar o zero da função: \n");
				
		printf("\n 1 - Bissecção ");
		printf("\n 2 - Falsa posição ");
		printf("\n 3 - Newton Rapson ");
		printf("\n 4 - Gauss ");
		printf("\n 5 - Fechar Programa ");
		printf("\n\n Escolha uma opcao: ");
		scanf("%d",&escolha);
		
		
	switch(escolha)
        {
            case 1:
            	system ("cls"); // comando para limpar a tela
            	printf("--------- Metodo da Bissecção -----------\n\n");
                digiteAB();
                bisseccao();
                printf ("Pressione uma tecla para retornar ao menu...");
            	getch(); // comando para aguardar até apertar uma tecla
            	system ("cls");
                break;

            case 2:
            	system ("cls");
            	printf("--------- Metodo da Falsa posição -----------\n\n");
                digiteAB();
                falsa_posicao();
                printf ("Pressione uma tecla para retornar ao menu...");
            	getch();
            	system ("cls");
                break;

            case 3:
                
                break;
            
            case 4:
                system ("cls");
                printf("--------- Metodo de Gauss -----------\n\n");
                gauss();
                printf ("\nPressione uma tecla para retornar ao menu...");
            	getch();
            	system ("cls");
                break;

            case 5:
    			return 0;
                break;

            default:
            	system ("cls"); 
                printf("!!!! Digite uma opção valida !!!!\n");
                
        }
    } while(escolha>=1 && escolha<=5); 
}

	double xm(double a, double b){
	    return (a+b)/2;
	}
	
	double bisseccao(){
	    fa = funcao(a);
    	fb = funcao(b);

    	if(fa*fb < 0){
	        //printf("%lf", fa*fb);
	        int achou=0;
	        int iteracao = 0;
	        do{
	            iteracao++; 
	             x = xm(a,b);
	             //printf("xm=%lf",xm);
	            fx = funcao(x);
	            fa = funcao(a);
	    		fb = funcao(b);
	    		
	    		printf("\n ------ Iteração %d -----", iteracao);
	            printf("\nA= %lf", a);
	            printf("  f(a)= %lf", fa);
	            printf("\nB= %lf", b);
	            printf("  f(b)= %lf", fb);
	    		
	            printf("\nXm= %lf", x);
	            printf("  f(xm)= %lf\n",fabs(fx));
	            if(fabs(fx)<E){
	                achou = 1;
	                printf("\nO valor absoluto do f(xm)= %lf é menor que a taxa de erro = %f\n",fabs(fx),E);
	                printf("\n !!! O zero da funcao é xm= %lf !!! \n\n\n", x);
	            }
	            else{
	                 if(fx < 0 && fa <0){
	                    a = x;
	                    
	                    //printf("1");
	                } else if(fx < 0 && fb <0){
	                    b = x;
	                    //printf("2");
	                } else if (fx > 0 && fa > 0){
	                    a = x;
	                    //printf("3");
	                } else if (fx > 0 && fb > 0){
	                    b = x;
	                    //printf("4");
	                }  
	            }
			}while(achou==0);
			return x;        
    	}
    else
        printf("\n\nNao existe zero entre A= %lf e B= %lf \n\n", a, b);
	}
	
	double xm_falsa_posicao(double a, double b){
	    return ((b*fa)-(a*fb))/ (fa-fb);
	}
	
	double falsa_posicao(){
	    fa = funcao(a);
    	fb = funcao(b);

    	if(fa*fb < 0){
	        //printf("%lf", fa*fb);
	        int achou=0;
	        int iteracao = 0;
	        do{
	            iteracao++;
	            printf("\n ------ Iteração %d -----", iteracao);
	            printf("\nA= %lf", a);
	            printf("  f(a)= %lf", fa);
	            printf("\nB= %lf", b);
	            printf("  f(b)= %lf", fb);
	            
	            x = xm_falsa_posicao(a,b);
	             
	            fx = funcao(x);
	            fa = funcao(a);
	    		fb = funcao(b);
	    		
	            printf("\nXm= %lf", x);
	            printf("  f(xm)= %lf\n",fx);
	             if(fabs(fx)<E){
	                achou = 1;
	                printf("\nO valor absoluto do f(xm)= %lf é menor que a taxa de erro = %f\n",fabs(fx),E);
	                printf("\n !!! O zero da funcao é xm= %lf !!! \n\n\n", x);
	             }
	             else{
	                 if(fx < 0 && fa <0){
	                    a = x;
	                    //printf("1");
	                } else if(fx < 0 && fb <0){
	                    b = x;
	                    //printf("2");
	                } else if (fx > 0 && fa > 0){
	                    a = x;
	                    //printf("3");
	                } else if (fx > 0 && fb > 0){
	                    b = x;
	                    //printf("4");
	                }  
	            }
			}while(achou==0);
			return x;        
    	}
    else
        printf("\n\nNao existe zero entre A= %lf e B= %lf \n\n", a, b);
	}
	
	void digiteAB(void){
		printf("Digite o valor de A: ");
	    scanf("%lf", &a);
	    printf("Digite o valor de B: ");
	    scanf("%lf", &b);
	    
	    while (a>=b){
	    	system ("cls");
	    	printf("Erro: O valor de A ou B invalido \n");
	    	printf("Digite o valor de A: ");
	    	scanf("%lf", &a);
	    	printf("Digite o valor de B: ");
	    	scanf("%lf", &b);
		};
		
	}
	
	double gauss(){
		int n=3, i, j, k, l;
		float A[n][n+1], x[n], termo;	
		float m;
			printf("Digite os valores dos coficientes e termos independentes do sistema\n\n");
				for (i=0; i<n;i++){
				for (j=0; j<n+1; j++){
			printf("Valor da matriz(%d,%d)= ",i+1,j+1);
			scanf("%f",&A[i][j]);
			//printf ("Valor contido na matriz(%d,%d)=%f\n",i+1,j+1,A[i][j]);
							}		
						}
			system ("cls");
			printf("Matriz Digitada:\n\n");
				for(i=0; i<n; i++) {
				for (j=0;j<n+1;j++){
					printf ("%f",A[i][j]);
				if(j==n) printf("\n");
				else printf("\t");
							}
						}
		//Implementando Método de Gauss
				for (k=0;k<n-1;k++){
				for (i=k+1; i<n;i++){
		//Multiplicadores
				m=-1*(A[i][k]/A[k][k]);
					for (j=0;j<n+1;j++){
				A[i][j]=(A[k][j]*m)+A[i][j];
								}
							}
			printf("\nMatriz A Transformada em Gauss:\n\n");
				for(i=0; i<n; i++) {
				for (j=0;j<n+1;j++){
			printf ("%f",A[i][j]);
				if(j==n) printf("\n");
				else printf("\t");
							}
								}
							}
		//Resolvendo o sistema
			for (i=0;i<n;i++){
				termo=0;
				l=n-i;
			for (j=l; j<n;j++){
			termo=termo+(x[j]*A[n-i-1][j]);
							}
			//printf ("\ntermo=%f\n",termo);
				x[n-i-1]=(A[n-1-i][n]-termo)/A[n-i-1][n-i-1];
			printf ("\nVariavel:\nx%d=%13.2f\n",n-i,x[n-i-1]);
							}
		return 0;
	}
