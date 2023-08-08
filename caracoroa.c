#include <stdio.h>
//Nomes: Pedro Silveira Vogel, Anna Paula Siqueira da Silva.
int main()
{
  size_t n;
  int r;
  int maria=0;
  int joao=0;
  int checagem=0;
  
  do
  { 
    maria=0;
    joao=0;
    checagem=0;

    scanf("%llu",&n);
    fflush(stdin);
    while (n< 0 || n > 10000)
    {
      printf("O numero de rodadas precisa ser maior ou igual a 0. Informe outro valor.\n");
      scanf("%llu",&n);
      fflush(stdin);
    }
    if (n!=0)
    {
      for (size_t i = 0; i < n; i++)
      {
        scanf("%d", &r);

        if (r!=0 && r!=1)
        {
          checagem=1;
          fflush(stdin);
          i = n + 1; //faz um break
        }
        else if (r==0)
        {
          maria++;
        }
        else 
        {
          joao++;
        }
        
      }
      fflush(stdin);
      //o if faz o efeito de um continue no loop
      if (checagem==1)
      {
        printf("ERRO, Rodada encerrada, valor invalido.Insira valores para uma nova rodada.\n");
        checagem = 0;
      }
      else
      {
        printf("Maria venceu %d vez(es) e Joao venceu %d vez(es).\n", maria, joao);
      }
    }
    

  } while (n!=0);
  return 0;
}
