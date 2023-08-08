#include <stdio.h>
//Nomes: Pedro Silveira Vogel, Anna Paula Siqueira da Silva.
int main()
{
  double x, modulo, pot_um, fracao, pot_x, soma= 0;
  int n;
  
  scanf("%lf", &x);

  while (x>=1 || x<=-1) //restricao do modulo
  {
    printf("O valor absoluto de x deve ser menor que 1. Informe novamente.\n");
    scanf("%lf", &x);
  }
  

  scanf("%d", &n);

  while (n<0)
  {
    printf("O valor de n deve ser maior ou igual a 0. Informe novamente.\n");
    scanf("%d", &n);
  }

  for (int i = 0; i <= n; i++)
  {
    if (i % 2 == 0)
    {
      pot_um = 1;
    }
    else
    {
      pot_um = -1;
    }

    fracao = pot_um / (2 * (double) i + 1);

    if (i==0)
    {
      pot_x = x;
    }
    else
    {
      pot_x = pot_x * x * x;
    }

    soma += fracao * pot_x;

    
      
  }
  printf("%.5lf", soma);
  
  
  return 0;
}
