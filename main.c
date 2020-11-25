#include <stdio.h>

void remove_primeira_linha_e_coluna_c(int n, float m_entrada[n][n], float m_saida[n-1][n-1], int c);
float calcula_determinante(int n, float m_entrada[n][n]);

int main(){
	int n;
	scanf("%i", &n);

	float m_entrada[n][n];

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			scanf("%f", &m_entrada[i][j]);
		}
	}

	printf("%lf\n", calcula_determinante(n, m_entrada));

	return 0;
}

void remove_primeira_linha_e_coluna_c(int n, float m_entrada[n][n], float m_saida[n-1][n-1], int c){
	for (int i = 1; i < n; i++){
		for (int j = 0, aux = 0; j < n; j++, aux++){
			if(j != c){
				m_saida[i-1][aux] = m_entrada[i][j];
			}else {
				aux--;
			}
		}
	}
}

float calcula_determinante(int n, float m_entrada[n][n]){
	if(n == 1){
		return m_entrada[0][0];

	}else {

		float somatorio = 0;

		for (int i = 0; i < n; ++i){
			float m_saida[n-1][n-1];
			remove_primeira_linha_e_coluna_c(n, m_entrada, m_saida, i);
			
			if((2+i)%2==0){
				somatorio += m_entrada[0][i] * calcula_determinante(n-1, m_saida);
				
			}else {

				somatorio += m_entrada[0][i] * (-1) * calcula_determinante(n-1, m_saida);
			}
		}

		return somatorio;
	}
}