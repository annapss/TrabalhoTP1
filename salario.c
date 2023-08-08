#include <stdio.h>
//Nomes: Pedro Silveira Vogel, Anna Paula Siqueira da Silva.

void lerFuncionario(int *numFuncionario, char *func, int *anos, int *contratadas, int *trabalhadas)
{
    char funcao2;
    int anos2, contratadas2, trabalhadas2;
    printf("Funcionario %d\n", *numFuncionario);
    fflush(stdin);
    //leitura da funcao
    do
    {
        printf("- Funcao: ");
        scanf("%c", &funcao2);
        if(funcao2 != 'a' && funcao2 != 'A' && funcao2 != 'p' && funcao2 != 'P' && funcao2 != 'g' && funcao2 != 'G')
        {
            printf("Voce digitou um valor invalido! Informe outro valor.\n");
            fflush(stdin);
        }
    } while (funcao2 != 'a' && funcao2 != 'A' && funcao2 != 'p' && funcao2 != 'P' && funcao2 != 'g' && funcao2 != 'G');
    *func = funcao2;
    fflush(stdin);

    //leitura dos anos de experiencia
    do
    {
        printf("- Anos de Exp.: ");
        scanf("%d", &anos2);
        if(anos2 < 0)
        {
            printf("Voce digitou um valor invalido! Informe outro valor.\n");
        }
    } while (anos2 < 0);
    *anos = anos2;
    fflush(stdin);

    //leitura de horas contratadas
    do
    {
        printf("- Horas contratadas: ");
        scanf("%d", &contratadas2);
        if(contratadas2 < 0)
        {
            printf("Voce digitou um valor invalido! Informe outro valor.\n");
        }
    } while (contratadas2 < 0);
    *contratadas = contratadas2;
    fflush(stdin);

    //leitura de horas trabalhadas
    do
    {
        printf("- Horas trabalhadas: ");
        scanf("%d", &trabalhadas2);
        if(trabalhadas2 < 0)
        {
            printf("Voce digitou um valor invalido! Informe outro valor.\n");
        }
    } while (trabalhadas2 < 0);
    *trabalhadas = trabalhadas2;
}

float calcularSalario(char *func, int *anos, int *contratadas, int *trabalhadas, float *brut, float *excedentes, float *inss, float *ir)
{
    float salarioliq;
    float valorhora;
    *excedentes = *trabalhadas - *contratadas;
    if(*excedentes <= 0)
    {
        *excedentes = 0;
    }
    *brut = 0;
    if(*func == 'P' || *func == 'p')
    {
        if(*anos <= 2)
        {
            valorhora = 25;
        }
        else if(*anos <= 5)
        {
            valorhora = 30;
        }
        else
        {
            valorhora = 38;
        }
    }
    else if(*func == 'A' || *func == 'a')
    {
        if (*anos <=2)
        {
            valorhora = 45;
        }
        else if (*anos <= 5)
        {
            valorhora = 55;
        }
        else
        {
            valorhora = 70;
        }
    }
    else
    {
        if (*anos <=2)
        {
            valorhora = 85;
        }
        else if (*anos <= 5)
        {
            valorhora = 102;
        }
        else
        {
            valorhora = 130;
        }
    }
    if(*excedentes > 0)
    {
        *brut += (*contratadas + *excedentes) * valorhora;
    }
    else
    {
        *brut += *trabalhadas * valorhora;
    }
    float porcentagemExc;
    if(*excedentes != 0)
    {
        if(*excedentes < 13)
        {
            porcentagemExc = 0.23;
        }
        else if(*excedentes < 22)
        {
            porcentagemExc = 0.37;
        }
        else
        {
            porcentagemExc = 0.56;
        }
        *brut += (valorhora * porcentagemExc) * *excedentes;
    }

    *inss = *brut * 0.11;    
    salarioliq = *brut - *inss;

    
    //desconto do ir
    *ir = (*brut - *inss);
    float porcentagemIr;
    if(*brut < 1500)
    {
        porcentagemIr = 0;
    }
    else if(*brut <= 2700)
    {
        porcentagemIr = 0.15;
    }
    else if(*brut < 4200)
    {
        porcentagemIr = 0.20;
    }
    else
    {
        porcentagemIr = 0.30;
    }
    *ir = *ir * (porcentagemIr);
    salarioliq = salarioliq * ((float)1 - porcentagemIr);
    return salarioliq;
}
void imprimirFolhaPagamento(int *i, int *q, float *bruto, float *hexc, float *descInss, float *descIr, float *liquido)
{
        printf("Folha de pagamento do funcionario %d", *i);
        printf("\n- Salario Bruto...(R$): %.2f", *bruto);
        if(*hexc > 0)
        {
            printf("\n- Horas Excedentes (h): %.0fhr", *hexc);   
        }
        printf("\n- Desconto INSS...(R$): %.2f", *descInss);
        printf("\n- Desconto IR.....(R$): %.2f", *descIr);
        printf("\n- Salario Liquido.(R$): %.2f\n", *liquido);
        if(*i != *q)
        {
            printf("=============\n");
        }

}



int main() {
	int quantFunc, exp, hcontr, htrab; 
    float bruto, hexc, descInss, descIr, liquido;
    char funcao;
    do
    {
        printf("Qtd: ");
        scanf("%d", &quantFunc);
        if(quantFunc <= 0)
        {
            printf("ATENCAO: a quantidade de funcionarios deve ser maior que zero. Informe novamente.\n");
        }
    }while(quantFunc <= 0);
    printf("=============\n");
    
    for(int i = 1; i <= quantFunc; i++)
    {
        lerFuncionario(&i,&funcao, &exp, &hcontr, &htrab);
        liquido = calcularSalario(&funcao, &exp, &hcontr, &htrab, &bruto, &hexc, &descInss, &descIr);
        imprimirFolhaPagamento(&i, &quantFunc, &bruto, &hexc, &descInss, &descIr, &liquido);
        bruto = 0;
        hexc = 0;
        descInss = 0;
        descIr = 0;
        liquido = 0;
    }

}