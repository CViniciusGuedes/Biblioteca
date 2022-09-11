#include <iostream>
#include <conio.h>
#include <string.h>
#include "locale.h"

using namespace std;

struct alunos{
	int ra;
	char nome[30];
	char endereco[30];
	char telefone[20];
	char cidade[20];
	char uf[2];
	int status;
};

struct ind_alunos{
	int codigo;
	int ender;
};

struct editoras{
	int codigo;
	char nome[30];
	char endereco[30];
	char telefone[20];
	char cidade[20];
	char uf[2];
	int status;
};

struct ind_editoras{
	int codigo;
	int ender;
};

struct livros{
	int codigo;
	char descricao[30];
	int cod_editora;
	char situacao;
	int status;
};

struct ind_livros{
	int codigo;
	int ender;
};

struct emprestimos{
	int codigo;
	int ra_aluno;
	int codigo_livro;
	char data_emprestimo[8];
	char data_devolucao[8];
	char situacao;
	int status;
};

struct ind_emprestimos{
	int codigo;
	int ender;
};

void leitura_alunos(struct alunos alu[], int &cont){
	int i = 0;
	for(int saida = 1; i < 20 && saida != 0; i++){
		cout << "\nRA do aluno: " << (i+1) << ": \n";
		cin >> alu[i].ra;
		if(alu[i].ra > 0){
			cout << "Nome: ";
			cin >> alu[i].nome;
            cout << "Endereço: ";
            cin >> alu[i].endereco;
            cout << "Telefone: ";
            cin >> alu[i].telefone;
            cout << "Cidade: ";
            cin >> alu[i].cidade;
            cout << "UF: ";
            cin >> alu[i].uf;
            alu[i].status == 0;
		}
		else saida = 0;
	}
	cont = i-1;
}

leitura_indice (struct ind_alunos idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nRA do aluno no Indice " << (i+1) << ": ";
        cin >> idx[i].codigo;
        cout << "Endereco Físico na Area de Dados: ";
        cin >> idx[i].ender;
    }
}

void inclusao_alunos (struct ind_alunos idx[], struct alunos alu[], int &cont, int cod){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].ender;
    if ((cod == idx[m].codigo)){
        cout << "\n\n Aluno já existe";
        cout << "RA: ";
    	cin >> cod;
    }
    else{
    	x = 1 ;
	}
}
    cont++;
    alu[cont].ra = cod;
    cout << "Nome: ";
    cin >> alu[cont].nome;
    cout << "Endereco: ";
    cin >> alu[cont].endereco;
    cout << "Telefone: ";
    cin >> alu[cont].telefone;
    cout << "Cidade: ";
    cin >> alu[cont].cidade;
    cout << "Estado: ";
    cin >> alu[cont].uf;
    alu[cont].status == 0;
    // inclusao na area de indices
    
    for (i = cont - 1; idx[i].codigo > cod; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo = alu[cont].ra;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso" << endl;
}

void busca_alunos (struct ind_alunos idx[], struct alunos alu[], int cont){
	int m;
	cout << "\n\nAlunos" << endl;
	
	for(int i = 0; i < cont; i++){
		m = idx[i].ender;
		if(alu[m].status==0){
			cout << "\nRA:" << alu[m].ra << endl;
			cout << "Nome: " << alu[m].nome << endl;
			cout << "Endereço: " << alu[m].endereco << endl;
			cout << "Telefone: " << alu[m].telefone << endl;
			cout << "Cidade: " << alu[m].cidade << endl;
			cout << "Estado: " << alu[m].uf << endl;
		}
	}
	getch();
}

void exclusao_aluno (struct ind_alunos idx[], struct alunos alu[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].ender;
    if ((cod == idx[m].codigo) && alu[i].status == 0){
        alu[i].status = 1;
        cout << "\n\n Aluno " << alu[i].nome << " Excluido com Sucesso!" << endl;
    }
    else
        cout << "Aluno não cadastrado";
    getch();
}

void leitura_editoras(struct editoras edt[], int &cont){
	int i = 0;
	for(int saida = 1; i < 20 && saida != 0; i++){
		cout << "\n\nCódigo da editora " << (i+1) << ": ";
		cin >> edt[i].codigo;
		if(edt[i].codigo > 0){
			cout << "Nome: ";
			cin >> edt[i].nome;
			cout << "Endereço: ";
			cin >> edt[i].endereco;
			cout << "Telefone: ";
			cin >> edt[i].telefone;
			cout << "Cidade: ";
			cin >> edt[i].cidade;
			cout << "UF: ";
			cin >> edt[i].uf;
		}
		else saida = 0;
	}
	cont = i-1;
}

leitura_indice_edt (struct ind_editoras idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].ender;
    }
}

void inclusao_editoras (struct ind_editoras idx[], struct editoras edt[], int &cont, int cod){
	cont ++;
	edt[cont].codigo = cod;
	cout << "Nome: ";
	cin >> edt[cont].nome;
	cout << "Endereço: ";
	cin >> edt[cont].endereco;
	cout << "Telefone: ";
	cin >> edt[cont].telefone;
	cout << "Cidade: ";
	cin >> edt[cont].cidade;
	cout << "UF: ";
	cin >> edt[cont].uf;
	
	int i;
    for (i = cont - 1; idx[i].codigo > cod; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void exclusao_editora (struct ind_editoras idx[], struct editoras edt[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].ender;
    if ((cod == idx[m].codigo) && edt[i].status == 0){
        edt[i].status = 1;
        cout << "\n\n Editora Excluido com Sucesso";
    }
    else
        cout << "Editora não cadastrado";
    getch();
}

void busca_editora (struct ind_editoras idx[], struct editoras edt[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].ender;
    if (cod == idx[m].codigo){
        
        cout << "\n\nEditora: " << edt[m].nome;
    }
    else
        cout << "\n \nEditora não cadastrado";
    getch();
}

void leitura_livros(struct livros liv[], int &cont, struct editoras edt[], struct ind_editoras idx[]){
	int i = 0;
	for(int saida = 1; i < 20 && saida != 0; i++){
		cout << "\n\nCódigo do Livro " << (i+1) << ": ";
		cin >> liv[i].codigo;
		if(liv[i].codigo > 0){
			cout << "Descrição: ";
			cin >> liv[i].descricao;
			cout << "Código da Editora: ";
			cin >> liv[i].cod_editora;
			
			if(liv[i].cod_editora == edt[i].codigo){
				cout << "Editora " << edt[i].nome << endl;
			}else{
				cout << "Código da Editora não cadastrado no sistema." << endl;
			}
			liv[i].situacao = 'd';
		}
		else saida = 0;
	}
	cont = i-1;
}

leitura_indice_liv (struct ind_livros idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Livro no Indice: " << (i+1) << ": ";
        cin >> idx[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].ender;
    }
}

void inclusao_livros(struct ind_livros idx[], struct livros liv[], int &cont, int cod){
	cont ++;
	liv[cont].codigo = cod;
	cout << "Descrição: ";
	cin >> liv[cont].descricao;
	cout << "Código Editora: ";
	cin >> liv[cont].cod_editora;
	liv[cont].situacao = 'd';
	
	int i;
    for (i = cont - 1; idx[i].codigo > cod; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void exclusao_livros (struct ind_livros idx[], struct livros liv[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].ender;
    if ((cod == idx[m].codigo) && liv[i].status == 0){
        liv[i].status = 1;
        cout << "\n\n Livro Excluido com Sucesso";
    }
    else
        cout << "Livro não cadastrado";
    getch();
}

void leitura_emprestimos(struct emprestimos emp[], int &cont, struct alunos alu[], struct ind_alunos idx[], struct livros liv[], struct ind_livros idxL[]){
	int i = 0;
	for(int saida = 1; i < 20 && saida != 0; i++){
		cout << "\n\nCódigo do Empréstimo " << (i+1) << ": ";
		cin >> emp[i].codigo;
		if(emp[i].codigo > 0){
			cout << "RA do Aluno: ";
			cin >> emp[i].ra_aluno;
			if(emp[i].ra_aluno == alu[i].ra){
				cout << "Aluno: " << alu[i].nome << endl;
			}else{
				cout << "Aluno não cadastrado no sistema." << endl;
			}
				
			cout << "Código do Livro: ";
			cin >> emp[i].codigo_livro;
			if(emp[i].codigo_livro == liv[i].codigo){
				cout << "Livro: " << liv[i].descricao << endl;
			}else{
				cout << "Livro não cadastrado no sistema." << endl;
			}
			if(liv[i].situacao == 'd'){
				cout << "Data do Empréstimo: ";
				cin >> emp[i].data_emprestimo;
				cout << "Data de Devolução: ";
				cin >> emp[i].data_devolucao;
			}else if(liv[i].situacao == 'e'){
				cout << "Livro Indisponível." << endl;
			}
			liv[i].situacao = 'e';	
			emp[i].situacao = 'e';
			
		}
		else saida = 0;
	}
	cont = i-1;
}

leitura_indice_emp (struct ind_emprestimos idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].ender;
    }
}

void inclusao_emprestimos(struct ind_emprestimos idx[], struct emprestimos emp[], int &cont, int cod){
	cont ++;
	emp[cont].codigo = cod;
	cout << "RA do Aluno: ";
	cin >> emp[cont].ra_aluno;
	cout << "Código do Livro: ";
	cin >> emp[cont].codigo_livro;
	cout << "Data do Empréstimo: ";
	cin >> emp[cont].data_emprestimo;
	cout << "Data de Devolução: ";
	cin >> emp[cont].data_devolucao;
	cout << "Situação: ";
	cin >> emp[cont].situacao;
	
	int i;
    for (i = cont - 1; idx[i].codigo > cod; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";	
}

void exclusao_emprestimo (struct ind_emprestimos idx[], struct emprestimos emp[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].ender;
    if ((cod == idx[m].codigo) && emp[i].status == 0){
        emp[i].status = 1;
        cout << "\n\n Emprestimo Excluido com Sucesso";
    }
    else
        cout << "Emprestimo não cadastrado";
    getch();
}

void devolver_livro(struct livros liv[], struct ind_livros idxL[], int &cont){
	int i, x, cod;
	cout << "Informe o código do livro para verificar a situação: " << endl;
	cin >> cod;
	if(cod == liv[i].codigo){
				cout << liv[i].descricao << endl;
				if(liv[i].situacao == 'e'){
					cout << "O Livro está emprestado, deseja devolver? (Digite 1 para devolver, 2 para cancelar)";
					cin >> x;
					if(x =! 1)
						cout << "Consulta Cancelada" << endl;						
					else
						liv[i].situacao = 'd';
						cout << "Livro Devolvido" << endl;
					
				}else if(liv[i].situacao == 'd'){
					cout << "O livro está disponível";
				}
			}
}

void menu(){
	cout << "---------- Menu Sistema Biblioteca ----------" << endl;
	cout << "\nSelecione uma opção: " << endl;
	cout << "\n1 - Digitar Dados Do Aluno \n\n2 - Digitar Dados Da Editora \n\n3 - Digitar Dados do Livro \n\n4 - Registrar Empréstimo\n\n5 - Incluir Novo Registro de Aluno\n\n6 - Mostrar Alunos\n\n";
	cout << "7 - Excluir Aluno\n\n8 - Excluir Empréstimo\n\n9 - Devolver Livro\n\n10 - Consultar prazos\n\n";
}

int main(){
	setlocale (LC_ALL, "Portuguese");
	
	int op;
	struct alunos alu[3];
	struct ind_alunos idxA[3];
	int idxEx, cod; // exclusao
	
	
	struct editoras edt[3];
	struct ind_editoras idxEdt[3];
	
	
	struct livros liv[3];
	struct ind_livros idxL[3];
	
	struct emprestimos emp[3];
	struct ind_emprestimos idxEmp[3];
		
	int cont, contE, contIdx, codInc, ra;
	int idxB, aluB, contB, raB;
	
	int idxLiv; //emprestimo
	
	
	
	//Variáveis da inclusao:
	int idxInc, aluInc;
	
	int x=1;
 	while(x==1){
  
  	menu();
  	cout<<"Escolha a opção desejada: ";
  	cin>>op;
	
	
	
	switch(op){
        case 1:
        	cout << "Digite os dados do Aluno: " << endl;
			leitura_alunos(alu, cont);
			leitura_indice(idxA, cont);
			break;
		case 2:
			cout << "Digite os Dados da Editora: ";
			leitura_editoras(edt, cont);
			leitura_indice_edt(idxEdt, cont);
			break;
		case 3:
			cout << "Digite as informações do livro: " << endl;			
			leitura_livros(liv, cont, edt, idxEdt);
			leitura_indice_liv(idxL, cont);
			break;
		case 4:
			cout << "Registrar Emprestimo:\n" << endl;			
			leitura_emprestimos(emp, cont, alu, idxA, liv, idxL);
			leitura_indice_emp(idxEmp, cont);
			break;
		case 5:
			cout << "Digite o RA: " << endl;
			cin >> codInc;
			inclusao_alunos(idxA, alu, cont, codInc);
			leitura_indice(idxA, cont);
			break;
		case 6:
            busca_alunos(idxA, alu, cont);
            break;
    	case 7:
    		for (int codpesq = 9; codpesq != 0;){
        		cout << "\n\nInforme o RA do Aluno a ser Excluído (0 para Encerrar): ";
        		cin >> codpesq;
        		if (codpesq != 0)
            	exclusao_aluno (idxA, alu, cont, codpesq);
    		}
    		break;
    	case 8:
    		for (int codpesq = 9; codpesq != 0;){
        		cout << "\n\nInforme o código do empréstimo a ser Excluído (0 para Encerrar): ";
        		cin >> codpesq;
        		if (codpesq != 0)
            	exclusao_emprestimo (idxEmp, emp, cont, codpesq);
        }
        	break;
        case 9:
        	devolver_livro(liv, idxL, cont);
        	break;
        case 10:
				
        
        	
		default:
    	cout<<"\nOpção inválida!\n\n";

		}
		cout<<"\nDeseja escolher outra opcao?\n 1 - Sim \n 0 - Não\n";
  		cin>>x;
	}
	
}
