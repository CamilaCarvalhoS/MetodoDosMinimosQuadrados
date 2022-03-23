/*
Camila Nunes Carvalho Souza


*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double soma_x(int n, double x[n]){
	int i;
	double soma;
	soma = 0;
	for(i=0;i<n;i++){
		soma = soma + x[i];
	}
	return soma;
}

double soma_x2(int n, double x[n]){
	int i;
	double x_2, soma;
	soma = 0;
	for(i=0;i<n;i++){
		x_2=powf(x[i],2);
		soma = soma + x_2;
	}
	return soma;
}

double soma_y(int n, double y[n]){
	int i;
	double soma;
	soma = 0;
	for(i=0;i<n;i++){
		soma = soma + (1/y[i]);
	}
	return soma;
}

double soma_xy(int n, double x[n], double y[n]){
	int i;
	double soma;
	soma = 0;
	for(i=0;i<n;i++){
		soma = soma + (x[i]/y[i]); 
	}
	return soma;
}

double soma_erro(int n,double y[n], double h[n]){
	int i;
	double soma;
	soma = 0;
	for(i=0;i<n;i++){
		soma = soma + powf((1/y[i]-h[i]),2);
	}
	return soma;
}

main(){

int i,j,n;
printf("Insira o tamanho do vetor x:");
scanf("%d", &n);
double x[n],y[n], A[2][2], b[2][1], fator_m, beta_1, beta_2, h[n], erro;

for(i=0;i<n;i++){
	printf("Agora insira o valor de x:");
	scanf("%lf",&x[i]);
	printf("Agora insira o seu respectivo f(%lf)",x[i]);
	scanf("%lf",&y[i]);
}

printf("Os valores inserido foram:\n");
for(i=0;i<n;i++){
	printf("x=%lf f(x)=%lf\n",x[i],y[i]);
}
printf("\nSendo assim temos:\n");
A[0][0] = soma_x2(n, x);
A[0][1]= soma_x(n, x);
A[1][0] = soma_x(n, x);
A[1][1] = n;
b[0][0] = soma_xy(n, x, y);
b[1][0] = soma_y(n,y);
printf("A matriz das somatorias:\n");
for(i=0;i<2;i++){
	for(j=0;j<2;j++){
		printf("%lf\t",A[i][j]);
	}
	printf("\n");
}
printf("A matriz b das somatorias:\n");
for(i=0;i<2;i++){
	for(j=0;j<1;j++){
		printf("%lf\t",b[i][j]);
	}
	printf("\n");
}

fator_m = A[1][0]/A[0][0];
A[1][0] = A[1][0]-(fator_m*A[0][0]);
A[1][1] = A[1][1]-(fator_m*A[0][1]);
b[1][0] = b[1][0] - (fator_m*b[0][0]);

printf("A matriz de triangulacao inferior formada:\n");
for(i=0;i<2;i++){
	for(j=0;j<2;j++){
		printf("%lf\t",A[i][j]);
	}
	printf("\n");
}
printf("o vetor b triangulado:\n");
for(i=0;i<2;i++){
	for(j=0;j<1;j++){
		printf("%lf",b[i][j]);
	}
	printf("\n");
}

beta_2 = b[1][0]/A[1][1];
beta_1 = (b[0][0]-beta_2*A[0][1])/A[0][0];
printf("\nTemos entao que Beta1=%lf e Beta2=%lf, ou seja, h(x)=%lf x+ %lf",beta_1, beta_2, beta_1, beta_2);
printf("\nCom isso chegamos na g(x)=1/(%lf x + %lf)", beta_1, beta_2);

for(i=0;i<n;i++){
	h[i] = beta_1*x[i]+beta_2;
}
erro = soma_erro(n, y, h);
printf("\nO erro dessa interacao e:%lf",erro);

}
