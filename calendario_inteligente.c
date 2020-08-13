#include <stdio.h>

int y, n, d, x, b, dia, dia_um[12];
int dias_mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int pascoa(void){
	int g, c, z, e;
	
	g=(y%19)+1;
	c=(y/100)+1;
	x=((3*c)/4)-12;
	z=(((8*c)+5)/25)-5;
	e=((((11*g)+20)+z)-x)%30;	
	
	if(((e==25)&&(g>11))||(e==24))
		e=e+1;

	n = 44-e;
	if(n < 21)
		n = n+30;
	
	return 0;
}

int bissexto(void){
	int ano; 
	
	ano = y;
	if(ano%100==0)
	ano=ano/100;
	if(ano%4==0){
		b=1;// bissexto
	}
	else{
		b=0;//bissexto	
	}

	d=((5*y)/4)-(x+10);
	n=(n+7)-(d+n)%7;
	
	if(n>31){	// n de abril
		n = n-31;
		dia = 90+b+n;
	}
	else{	//n de março
		dia = 59+b+n;
	}
	return 0;
}

int diasemana(void){ 
		
	dia_um[0] = (7-(dia%7))+1;//janeiro
		if(dia_um[0]==7)
			dia_um[0]=0;
			
	dia_um[1] = (dias_mes[0]+dia_um[0])%7;//fevereiro
	
	dia_um[2] = ((dias_mes[1]+b)+dia_um[1])%7;//marco	
	
	dia_um[3] = (dias_mes[2]+dia_um[2])%7;//abril	
	
	dia_um[4] = (dias_mes[3]+dia_um[3])%7;//maio	
	
	dia_um[5] = (dias_mes[4]+dia_um[4])%7;//junho	
	
	dia_um[6] = (dias_mes[5]+dia_um[5])%7;//julho	
		
	dia_um[7] = (dias_mes[6]+dia_um[6])%7;//agosto
	
	dia_um[8] = (dias_mes[7]+dia_um[7])%7;//setembro
	
	dia_um[9] = (dias_mes[8]+dia_um[8])%7;//outubro
	
	dia_um[10] = (dias_mes[9]+dia_um[9])%7;//novembro	
	
	dia_um[11] = (dias_mes[10]+dia_um[10])%7;//dezembro	
    return 0;
}

int imprimecalendario(void){
	int mes_esq[6][7], mes_dir[6][7], cont_esq=1, cont_dir=1, i, j, k=0, l=0;
	printf("|-----------------------------||-----------------------------|\n");
	printf("|Janeiro                      ||Fevereiro                    |\n");
	printf("|-----------------------------||-----------------------------|\n");
	printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");			
	for(i=0; i<6; i++){
		printf("| ");
		for(j=0; j<7; j++){//janeiro
			if(k<dia_um[0]){
				printf(" -- ");
				k++;
			}
			else{
				if(cont_esq>dias_mes[0])
					printf(" -- ");
				else{
					mes_esq[i][j]=cont_esq;
					printf(" %.2d ", mes_esq[i][j]);
				cont_esq++;
				}
			}
		}
		printf("|");
		printf("| ");	
		for(j=0; j<7; j++){//fevereiro
			if(l<dia_um[1]){
				printf(" -- ");
				l++;
			}
			else{
				if(cont_dir>dias_mes[1]+b)
					printf(" -- ");
				else{
					mes_dir[i][j]=cont_dir;
				printf(" %.2d ", mes_dir[i][j]);
				cont_dir++;
				}
			}
		}
		printf("|\n");	
	}
	printf("|-----------------------------||-----------------------------|\n");
	
	printf("|Março                        ||Abril                        |\n");
	printf("|-----------------------------||-----------------------------|\n");
	printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");			
	cont_esq=1; cont_dir=1; k=0; l=0;
	for(i=0; i<6; i++){
			printf("| ");
			for(j=0; j<7; j++){//março
				if(k<dia_um[2]){
					printf(" -- ");
					k++;
				}
				else{
					if(cont_esq>dias_mes[2])
						printf(" -- ");
					else{
						mes_esq[i][j]=cont_esq;
						printf(" %.2d ", mes_esq[i][j]);
					cont_esq++;
					}
				}
			}
			printf("|");
			printf("| ");	
			for(j=0; j<7; j++){//abril
				if(l<dia_um[3]){
					printf(" -- ");
					l++;
				}
				else{
					if(cont_dir>dias_mes[3])
						printf(" -- ");
					else{
						mes_dir[i][j]=cont_dir;
						printf(" %.2d ", mes_dir[i][j]);
					cont_dir++;
					}
				}
			
		}
		printf("|\n");	
	}
	printf("|-----------------------------||-----------------------------|\n");

	printf("|Maio                         ||Junho                        |\n");
	printf("|-----------------------------||-----------------------------|\n");
	printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");			
	cont_esq=1; cont_dir=1; k=0; l=0;
	for(i=0; i<6; i++){
			printf("| ");
			for(j=0; j<7; j++){//maio
				if(k<dia_um[4]){
					printf(" -- ");
					k++;
				}
				else{
					if(cont_esq>dias_mes[4])
						printf(" -- ");
					else{
						mes_esq[i][j]=cont_esq;
						printf(" %.2d ", mes_esq[i][j]);
					cont_esq++;
					}
				}
			}
			printf("|");
			printf("| ");	
			for(j=0; j<7; j++){//junho
				if(l<dia_um[5]){
					printf(" -- ");
					l++;
				}
				else{
					if(cont_dir>dias_mes[5])
						printf(" -- ");
					else{
						mes_dir[i][j]=cont_dir;
						printf(" %.2d ", mes_dir[i][j]);
					cont_dir++;
					}
				}
			
		}
		printf("|\n");	
	}
	printf("|-----------------------------||-----------------------------|\n");

	printf("|Julho                        ||Agosto                       |\n");
	printf("|-----------------------------||-----------------------------|\n");
	printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");			
	cont_esq=1; cont_dir=1; k=0; l=0;
	for(i=0; i<6; i++){
			printf("| ");
			for(j=0; j<7; j++){//julho
				if(k<dia_um[6]){
					printf(" -- ");
					k++;
				}
				else{
					if(cont_esq>dias_mes[6])
						printf(" -- ");
					else{
						mes_esq[i][j]=cont_esq;
						printf(" %.2d ", mes_esq[i][j]);
					cont_esq++;
					}
				}
			}
			printf("|");
			printf("| ");	
			for(j=0; j<7; j++){//agosto
				if(l<dia_um[7]){
					printf(" -- ");
					l++;
				}
				else{
					if(cont_dir>dias_mes[7])
						printf(" -- ");
					else{
						mes_dir[i][j]=cont_dir;
						printf(" %.2d ", mes_dir[i][j]);
					cont_dir++;
					}
				}
			
		}
		printf("|\n");	
	}
	printf("|-----------------------------||-----------------------------|\n");

	printf("|Setembro                     ||Outubro                      |\n");
	printf("|-----------------------------||-----------------------------|\n");
	printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");			
	cont_esq=1; cont_dir=1; k=0; l=0;
	for(i=0; i<6; i++){
			printf("| ");
			for(j=0; j<7; j++){//setembro
				if(k<dia_um[8]){
					printf(" -- ");
					k++;
				}
				else{
					if(cont_esq>dias_mes[8])
						printf(" -- ");
					else{
						mes_esq[i][j]=cont_esq;
						printf(" %.2d ", mes_esq[i][j]);
					cont_esq++;
					}
				}
			}
			printf("|");
			printf("| ");	
			for(j=0; j<7; j++){//outubro
				if(l<dia_um[9]){
					printf(" -- ");
					l++;
				}
				else{
					if(cont_dir>dias_mes[9])
						printf(" -- ");
					else{
						mes_dir[i][j]=cont_dir;
						printf(" %.2d ", mes_dir[i][j]);
					cont_dir++;
					}
				}
			
		}
		printf("|\n");	
	}
	printf("|-----------------------------||-----------------------------|\n");

	printf("|Novembro                     ||Dezembro                     |\n");
	printf("|-----------------------------||-----------------------------|\n");
	printf("| dom seg ter qua qui sex sab || dom seg ter qua qui sex sab |\n");			
	cont_esq=1; cont_dir=1; k=0; l=0;
	for(i=0; i<6; i++){
			printf("| ");
			for(j=0; j<7; j++){//novembro
				if(k<dia_um[10]){
					printf(" -- ");
					k++;
				}
				else{
					if(cont_esq>dias_mes[10])
						printf(" -- ");
					else{
						mes_esq[i][j]=cont_esq;
						printf(" %.2d ", mes_esq[i][j]);
					cont_esq++;
					}
				}
			}
			printf("|");
			printf("| ");	
			for(j=0; j<7; j++){//dezembro
				if(l<dia_um[11]){
					printf(" -- ");
					l++;
				}
				else{
					if(cont_dir>dias_mes[11])
						printf(" -- ");
					else{
						mes_dir[i][j]=cont_dir;
						printf(" %.2d ", mes_dir[i][j]);
					cont_dir++;
					}
				}
			
		}
		printf("|\n");	
	}
	printf("|-----------------------------||-----------------------------|\n");

return 0;
}
int main() {
	
	scanf("%d", &y); 
	printf("Calendario do ano %d\n", y);
	
	pascoa(); //chamada da funcao de calculo da pascoa
	bissexto();// recebeu n; chamada da função de calculo do ano bissexto
	diasemana();// recebeu dia; chamada da função de calculo do diasemana
	imprimecalendario();//recebeu diasemana; chamada da funcao impremecalendario
		
	return 0;	
}