/*
	@title - PROGRAM FOR FAMILY PLANNING
	@author - ELIDIOMAR RODRIGUES
	@email - ELIDIOMAR.RODRIGUES@GMAIL.COM
	@language - PT-BR
	@version - 1.0
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

//CRIA A ESTRUTURA DESPESA
typedef struct{
	char descricao[16];
	float valor, total;
}tipo_despesa;

//CRIA A ESTRUTURA USUARIO
typedef struct{
	int id;
	char nome[81], funcao[36];
	float renda;
	tipo_despesa despesa_Pessoal[9];
	tipo_despesa despesa_Coletiva[9];
}usuario;

//PROTOTIPO DAS FUNCOES
void despesa_pessoal(int cadastro);
void despesa_coletiva(int cadastro);
int Relatorio();

//DECLARA AS VARIAVEIS
usuario membro[15];
float total_Desp_Coletiva = 0, total_Desp_Pessoal = 0, renda = 0, despesa = 0, valor = 0, especial = 0, total_trimestral = 0, total_Anual[2], trimestral[15] = {'\0'}, anual[2][15] = {'\0'};
int membros = 0, cont = 1, outro = 2, i = 1, j = 0, x = 1, y = 1, z = 1;
char temp[10], info[2][9][16] = {
				 				{"Escola", "Transporte", "Lazer", "Saude", "Previdencia", "Outras", " ", " ", " "},
								{ "Moradia", "Agua", "Luz", "Gas", "IPTU", "Carro", "Outras" , " ", " "}
								};

int main(void)
{
 	//INICIALIZA AS VARIAVEIS
    for (i=0; i<=14; i++)
	{
		strcpy(membro[i].nome,"");
		membro[i].id = 0;
   		for (j=0; j<=8; j++)
		{
		 	strcpy (membro[i].despesa_Pessoal[j].descricao, info[0][j]);
            membro[i].despesa_Pessoal[j].valor= 0;
		 	strcpy (membro[i].despesa_Coletiva[j].descricao, info[1][j]);
			membro[i].despesa_Coletiva[j].valor= 0;
		}
	}

	//ARMAZENA AS FUNCOES DOS MEMBROS NA FAMILIA
	strcpy (membro[0].funcao, "Pai\0");
	strcpy (membro[1].funcao, "Mae\0");
	for (i = 2; i <= 14; i++)
	{
		strcpy (membro[i].funcao, "Outro membro com mais de 18 anos\0");
	}

	// MENSAGEM INICIAL E INFORMACOES
	system("CLS");
	system("COLOR 06");
	printf("\a");

	// HABILITA ACENTUACAO DO IDIOMA LOCAL
	setlocale(LC_ALL, "Portuguese");

	printf("\n ================================================================");
	printf("\n               PLANEJAMENTO DE ORCAMENTO FAMILIAR");
	printf("\n ================================================================");
	printf("\n\n Seja bem vindo,");
	printf("\n Com essa ferramenta voce podera organizar melhor suas financas.");
	printf("\n Nela voce e sua familia entraram com despesas e receitas");
	printf("\n e poderam acompanhar o desempenho financeiro da familia");
	printf("\n\n OBSERVACAO: Membros com menos de 18 anos devem ter suas despesas");
	printf("\n e receitas contabilizadas junto com o Pai ou a Mae.");
	printf("\n\n Pressione a tecla [ENTER] para inicia o cadastro...\n\n  ");
 	gets(temp);

	//LOOP PARA CADASTRAR OS MEMBROS
	i = 1;
	while (i != 0)
	{

		//EXIBE NA TELA AS OPCOES DE CADASTRO
		system("CLS");
		system("COLOR A");
		printf("\n Informe a colocacao do %iº membro da familia:\n\n", membros +1);

		for (y = 0; y <= 2; y++)
			printf("\n %i - %s", y+1, membro[y].funcao);

		printf("\n 0 - Exibir relatorio\n\n ");

		// ARMAZENA A ESCOLHA DO USUARIO E TRATA A MESMA.
		temp[0]=getch();
	    i=temp[0]-48;
		if (i==-35)
  			i=15;

		if (i==3)
		{
			outro = outro + 1;
			i = outro;
		}

		if (i == 0)
		{
			if (membros == 0)
			{
				system("CLS");
				system("COLOR C");
				printf("\n Voce deve cadastrar no minimo um membro da familia!");
				printf("\n Pressione qualquer tecla para cadastrar um membro...\n");
				system ("PAUSE>NUL");
				i = 1;
			}
		}
		else
		{
		    // CADASTRA USUARIO E A RENDA
			if (i <= outro)
			{
	            printf("\n Digite o nome do(a) %s: ", membro[i-1].funcao);
				scanf("%s", membro[i-1].nome);
				printf("\n Renda do(a) %s: R$ ", membro[i-1].funcao);
				scanf(" %s", &temp);
				membro[i-1].renda = atof(temp);
				membro[i-1].id = i;
				membros = membros + 1;

				// CHAMA FUNCAO DE CADASTRO DE DESPESAS
				despesa_pessoal(i - 1);
				despesa_coletiva(i - 1);
			}
			else
			{
				system("CLS");
				system("COLOR 04");
				printf("\n Voce escolheu um membro inexistente!");
 				printf("\n Pressione qualquer tecla para cadastrar um membro...\n");
				system ("PAUSE>NUL");
			}
		}
	}

	// CALCULA VALOR TOTAL DAS DESPESAS MENSAIS, TRIMESTRAIS E ANUAIS
	cont = membros;
	total_Anual[0] = 0;
	total_Anual[0] = 0;
	total_trimestral = 0;
	for (i = 0; i <= cont; i++)
	{
		total_Desp_Pessoal =  total_Desp_Pessoal + membro[i].despesa_Pessoal[9].total;
		total_Desp_Coletiva = total_Desp_Coletiva + membro[i].despesa_Coletiva[9].total;
		total_trimestral = trimestral[i] + total_trimestral;
		total_Anual[0] = total_Anual[0] + anual[0][i];
		total_Anual[1] = total_Anual[1] + anual[1][i];

		renda = membro[i].renda + renda;
    }

	despesa = total_Desp_Pessoal + total_Desp_Coletiva;
	i = 1;

   // LOOP PARA EXIBIR RELATORIOS
   while (i != 0)
   {
		system("CLS");
		system("COLOR D");
		printf("\n Informe o membro para exibir o relatorio:\n");
		membros = 0;
		for (y = 0; y <= 14; y++)
			if (membro[y].id > 0)
				printf("\n  %i - %s", membro[y].id, membro[y].nome);

		printf("\n  0 - Sair\n\n");
		temp[0]=getch();
	    i=temp[0]-48;
		system("CLS");
		y = i - 1;

		if (i > 0)
		{
			if (i <= 14)
			{
				if (membro[y].id > 0)
				{
					system("COLOR A");
					printf ("\n =====================================================");
					printf("\n    RELATORIO MENSAL PLANEJAMENTO PESSOAL DO(A) %s", strupr(membro[y].nome));
					printf("\n =====================================================\n\n");
					printf("\n Nome: %s", membro[y].nome);
					printf("\n Funcao: %s", membro[y].funcao);
					printf("\n Renda: R$  %.2f", membro[y].renda);
					printf("\n\n Lista das despesas:\n");

					x = 0;
					for (cont = 0; cont <= 9; cont++)
					{
						if (membro[y].despesa_Pessoal[cont].valor > 0)
						{
							x = x + 1;
							printf("\n  %i - %s: R$ %.2f", x, membro[y].despesa_Pessoal[cont].descricao, membro[y].despesa_Pessoal[cont].valor);
						}
					}

					for (cont = 0; cont <= 9; cont++)
					{
						if (membro[y].despesa_Coletiva[cont].valor > 0)
						{
							x = x + 1;
							printf("\n  %i - %s: R$ %.2f", x, membro[y].despesa_Coletiva[cont].descricao, membro[y].despesa_Coletiva[cont].valor);
						}
					}

					despesa = membro[y].despesa_Pessoal[9].total + membro[y].despesa_Coletiva[9].total;
					printf("\n\n Total despesa pessoal: R$ %.2f", membro[y].despesa_Pessoal[9].total);
					printf("\n Total despesa coletiva: R$ %.2f", membro[y].despesa_Coletiva[9].total);
					printf("\n Total de despesas: R$ %.2f", despesa);
					printf("\n Saldo: R$ %.2f", membro[y].renda - despesa);

					if (i<=2)
					{
						despesa = total_Desp_Pessoal + total_Desp_Coletiva;
						printf ("\n\n\n =====================================================");
						printf ("\n             RELATORIO MENSAL - FAMILIAR");
						printf ("\n =====================================================\n\n");
						printf ("\n Renda: R$ %.2f", renda);
						printf ("\n Total despesa pessoal: R$ %.2f", total_Desp_Pessoal);
						printf ("\n Total despesa coletiva: R$ %.2f", total_Desp_Coletiva);
						printf ("\n Total de despesas: R$ %.2f", despesa);
						printf ("\n Saldo: R$ %.2f", renda - despesa);

						printf ("\n\n\n =====================================================");
						printf ("\n            RELATORIO TRIMESTRAL - FAMILIAR");
						printf ("\n =====================================================\n\n");
						printf ("\n Renda: R$ %.2f", renda * 3);
						printf ("\n Total despesa coletiva: R$ %.2f", total_trimestral);
						printf ("\n Total de outras: R$ 0,00");
						printf ("\n Saldo: R$ %.2f", (renda * 3) - total_trimestral);

						printf ("\n\n\n =====================================================");
						printf ("\n               RELATORIO ANUAL - FAMILIAR");
						printf ("\n =====================================================\n\n");
						printf ("\n Renda: R$ %.2f", renda * 12);
						printf ("\n Total despesa coletiva: R$ %.2f", total_Anual[1]);
						printf ("\n Total de outras: R$ 0,00");
						printf ("\n Saldo: R$ %.2f", (renda * 12) - total_Anual[1]);
					}

					despesa = total_Anual[0] + total_Anual[1];
					printf ("\n\n\n =====================================================");
					printf ("\n   RELATORIO PESSOAL ANUAL DO(A) %s", strupr(membro[y].nome));
					printf ("\n =====================================================\n\n");
					printf ("\n Renda: R$ %.2f", membro[y].renda * 12);
					printf ("\n Total despesa pessoais: R$ %.2f", total_Anual[0]);
					printf ("\n Total despesa coletiva: R$ %.2f", total_Anual[1]);
					printf("\n Total de despesas: R$ %.2f", despesa);
					printf ("\n Saldo: R$ %.2f", (membro[y].renda * 12) - despesa);

					if (membro[y].renda > 1904)
	  					printf ("\n\n\n ATENÇÃO SR(A) %s... \n VOCÊ ESTA OBRIGADO(A) A APRESENTAR A DECLARAÇÃO DE AJUSTE ANUAL DO IMPOSTO DE RENDA.\n\n Link para declaração: http://idg.receita.fazenda.gov.br/acesso-rapido/tributos/irpf-imposto-de-renda-pessoa-fisica", strupr(membro[y].nome));
					else
						printf ("\n\n\n ATENÇÃO SR(A) %s... \n VOCÊ ESTA ISENTO(A) A APRESENTAR A DECLARAÇÃO DE AJUSTE ANUAL DO IMPOSTO DE RENDA.", strupr(membro[y].nome));

					printf ("\n\n Pressione qualquer tecla para continuar...");
					system ("PAUSE>NUL");
				}
				else
				{
					system("CLS");
					system("COLOR 04");
					printf("\n Voce escolheu um membro não cadastrado!");
					printf("\n Pressione qualquer tecla para escolher um membro valido...\n");
					system ("PAUSE>NUL");
					i = 1;
				}
			}
		}
	}

  	system ("PAUSE>NUL");
	return(0);
}

// FUNCAO PARA CADASTRO DAS DESPESAS PESSOAIS
void despesa_pessoal(int cadastro)
{
	cont = 0;
	x = 1;
	especial = 0;
	anual[0][cadastro]=0;

	// LOOP PARA CADASTRAR AS DESPESAS PESSOAIS
	while (x != 0)
	{
		// EXIBE NA TELA AS OPCOES DE CADASTRO
		system("CLS");
		system("COLOR E");
		printf("\n Escolha a %iª despesa PESSOAL para o(a) %s:\n", cont +1, membro[cadastro].nome);
		for (y = 0; y <= 5; y++)
			printf("\n  %i - %s", y + 1, membro[cadastro].despesa_Pessoal[y].descricao);

		printf("\n  0 - Finalizar despesa pessoal.\n\n");

		// ARMAZENA A ESCOLHA DO USUARIO
		temp[0]=getch();
	    x=temp[0]-48;
		if (x > 0)
		{
			if (x <= 6)
			{
				cont = cont + 1;
				printf ("\n  Valor da despesa com %s: R$ ", strupr(membro[cadastro].despesa_Pessoal[x-1].descricao));
				scanf("%s", &temp);
				membro[cadastro].despesa_Pessoal[x-1].valor = atof(temp);
				anual[0][cadastro] = anual[0][cadastro] + (atof(temp)*12);
				membro[cadastro].despesa_Pessoal[9].total = membro[cadastro].despesa_Pessoal[9].total + membro[cadastro].despesa_Pessoal[x-1].valor;
			}
			else
			{
				system("CLS");
				system("COLOR 04");
				printf("\n Voce escolheu uma despesa não cadastrada!");
				printf("\n Pressione qualquer tecla para cadastrar uma despesa valida...\n");
				system("PAUSE > NULL");
				x = 1;
			}
		}
	}
}

// FUNCAO PARA CADASTRO DAS DESPESAS COLETIVAS
void despesa_coletiva(int cadastro)
{
	cont = 0;
	x = 1;
	especial = 0;
	anual[1][cadastro] = 0;
	trimestral[cadastro] = 0;

	// LOOP PARA CADASTRAR AS DESPESAS COLETIVAS
	while (x != 0)
	{
		// EXIBE NA TELA AS OPCOES DE CADASTRO
		system("CLS");
		system("COLOR F");
		printf("\n Escolha a %iª despesa COLETIVA para o(a) %s:\n", cont +1, membro[cadastro].nome);
		for (y = 0; y <= 6; y++)
			printf("\n  %i - %s", y + 1, membro[cadastro].despesa_Coletiva[y].descricao);

		printf("\n  0 - Finalizar despesa coletiva.\n\n");

		// ARMAZENA A ESCOLHA DO USUARIO
		temp[0]=getch();
	    x=temp[0]-48;

		if (x > 0)
		{
			if (x <= 7)
   			{
				if (x == 6)
				{
					// VARIAVEL CARRO - TRATAMENTO ESPECIAL
					printf ("\n Valor da despesa com IPVA : R$ ");
					scanf ("%s", &temp);
					valor = atof(temp);
					especial = especial + valor;
					printf ("\n Valor da despesa com Seguro : R$ ");
					scanf ("%s", &temp);
					valor = atof(temp);
					especial = especial + valor;
					printf ("\n Valor da despesa com Combustivel : R$ ");
					scanf ("%s", &temp);
					valor = atof(temp);
					especial = especial + valor;
					printf ("\n Valor da despesa com Higienizacao : R$ ");
					scanf ("%s", &temp);
					valor = atof(temp);
					especial = especial + valor;
					printf ("\n Valor da despesa com Manutencao : R$ ");
					scanf ("%s", &temp);
					valor = atof(temp);
					especial = especial + valor;
					membro[cadastro].despesa_Coletiva[5].valor = especial;
				}
				else
				{
					// DEMAIS VAIAVEIS
					printf ("\n  Valor da despesa com %s: R$ ", strupr(membro[cadastro].despesa_Coletiva[x-1].descricao));
					scanf ("%s", &temp);
					membro[cadastro].despesa_Coletiva[x-1].valor = atof(temp);
					trimestral[cadastro] = trimestral[cadastro] + (atof(temp)*3);
					anual[1][cadastro] = anual[1][cadastro] + (atof(temp)*12);
				}

				cont = cont + 1;
				membro[cadastro].despesa_Coletiva[9].total = membro[cadastro].despesa_Coletiva[9].total + membro[cadastro].despesa_Coletiva[x-1].valor;
			}
			else
			{
				system("CLS");
				system("COLOR 04");
				printf("\n Voce escolheu uma despesa não cadastrada!");
				printf("\n Pressione qualquer tecla para cadastrar uma despesa valida...\n");
				system("PAUSE > NULL");
				x = 1;
			}
		}
	}
}
