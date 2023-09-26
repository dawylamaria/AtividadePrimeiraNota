#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void ordenandoNomes(string vetor[], int n) {
    for (int i = 1; i < n; i++) {
        string aux = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > aux) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
}

void stringOrdemDecrescente(string& palavra) { 
    int n = palavra.length();
    
    for (int i = 1; i < n; i++) {
        char aux = palavra[i];
        int j = i - 1;

        while (j >= 0 && palavra[j] < aux) { 
            palavra[j + 1] = palavra[j];
            j--;
        }
        palavra[j + 1] = aux;
    }
}

void ordenandoPorTamanho(vector<string>& nomes){

    int n = nomes.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nomes[j].length() < nomes[i].length()) {
                swap(nomes[i], nomes[j]);
            }
        }
    }
}

void merge(string &str, int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    
    vector<char> L(n1);
    vector<char> R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = str[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = str[meio + 1 + j];
        
    int i = 0;
    int j = 0;
    int k = inicio;
    
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            str[k] = L[i];
            i++;
        } else {
            str[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1){
        str[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2){
        str[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(string &str, int inicio, int fim){
    if (inicio < fim){
        int meio = (inicio + fim)/2;
        
        mergeSort(str, inicio, meio);
        mergeSort(str, meio + 1, fim);

        merge(str, inicio, meio, fim);
    }
}

int particionar(int arr[], int inicio, int fim) {
    int esquerda, direita, pivo;
	pivo = arr[inicio]; 
    esquerda = inicio;
    direita = fim;

	while (esquerda < direita){
		while (arr[esquerda] <= pivo && esquerda < fim){
			esquerda++;
		}
		
		while (arr[direita] > pivo){
			direita--;
		}
		
		if (esquerda < direita){
			int aux = arr[esquerda];
			arr[esquerda] = arr[direita];
			arr[direita] = aux;
		}
	}
	
	arr[inicio] = arr[direita];
	arr[direita] = pivo;
	
	return direita;
}

void quickSort(int arr[], int inicio, int fim) {
    int pivo;
	if (inicio < fim) {
        pivo = particionar(arr, inicio, fim);
        quickSort(arr, inicio, pivo - 1);
        quickSort(arr, pivo + 1, fim);
    }
}

int main() {
    int escolha = -1;
    
    while (escolha != 0){
    	cout << "Digite a questao que deseja executar (1 a 8): ";
	    cin >> escolha;
	
	    switch (escolha) {
	    case 1:
	    	{
	        int n;
	        cout << "Digite o numero de nomes: ";
	        cin >> n;
	
	        string* nomes = new string[n];
	
	        for (int i = 0; i < n; i++) {
	            cout << "Digite o nome " << i + 1 << ": ";
	            cin >> nomes[i];
	        }
	
	        ordenandoNomes(nomes, n);
	
	        cout << "Nomes ordenados:" << endl;
	        for (int i = 0; i < n; i++) {
	            cout << nomes[i] << endl;
	        }
	        
	        break;
	    	}
	    
	    case 2:
	    	{
	    		string palavra;
	
	        	cout << "Digite uma palavra: ";
	        	cin >> palavra;
	
	        	stringOrdemDecrescente(palavra);
	
	        	cout << "String ordenada em ordem decrescente: " << palavra << endl;
	
	        	break;
			}
	
	    case 3:
	        {
	        int n;
	    	cout << "Quantos nomes deseja ordenar? ";
	    	cin >> n;
	
	    	vector<string> nomes(n);
	
	    	for (int i = 0; i < n; i++) {
	        	cout << "Digite o nome " << i + 1 << ": ";
	        	cin >> nomes[i];
	    	}
	
	    	ordenandoPorTamanho(nomes);
	
	    	cout << "Nomes ordenados:" << endl;
	        for (int i = 0; i < n; i++) {
	            cout << nomes[i] << endl;  
	        }
			}
	        break;
	    
	    case 4:
		    {string palavra;
		    
		    cout << "Digite uma palavra: ";
		    cin >> palavra;
		    int tamanho = palavra.length();
		
		    mergeSort(palavra, 0, tamanho - 1);
		
		    cout << "Caracteres em ordem alfabetica: ";
		    for(int i = 0; i < tamanho; i++)
		        cout << palavra[i];
		    cout << endl;}
	        break;
	       
	    case 5:
	    	{int tamanho = 30;
	        int arr[tamanho];
		
		    cout << "Digite " << tamanho << " numeros:" << endl;
		    for (int i = 0; i < tamanho; i++) {
		        cout << "Numero " << (i + 1) << ": ";
		        cin >> arr[i];
		    }
		
		    quickSort(arr, 0, tamanho - 1);
		
		    cout << "Numeros ordenados:" << endl;
		    for (int i = 0; i < tamanho; i++) {
		        cout << arr[i] << " ";
		    }
		    cout << endl;}
	        break;
	        
	    case 6:
	        cout << "LETRA C. Em [10, 8, 7, 0] sao feitas 6 comparacoes e 6 trocas" << endl;
	        cout << "Na primeira rodada, o 10 eh comparado com 8, 7 e 0, trocando com todos" << endl;
	        cout << "Na segunda, o 8 eh comparado com 7 e 0, visto que o 10 ja esta na posicao correta, trocando com ambos" << endl;
			cout << "Na terceira e ultima, o 7 eh comparado com 0 e faz a trocam ficando todos ordenados" << endl;
			break;
	        
	    case 7:
	        cout << "LETRA A. Selection Sort eh o algoritmo de busca e ordenacao que encontra" <<endl;
	        cout << "o menor elemento e troca com a primeira posicao e assim sucessivamente." <<endl;
	        cout << "Ressalta-se que isso pode ser feito com o maior elemento tambem." <<endl;
			break;    
	        
	    case 8:
	        cout << "BUBBLESORT: os elementos vizinhos sao comparados, trocando a posicao" <<endl;
	        cout << "caso a ordem esteja errada. Isso ocorre ate que todos estejam na posicao" <<endl;
	        cout << "correta. Ressalta-se que aqueles que ja estao posicionados nao sao testados novamente;" <<endl << endl;
	        cout << "SELECTIONSORT: Encontra-se o menor ou maior valor de uma lista, para ordem crescente ou " <<endl;
	        cout << "decrescente respectivamente, e coloca-o na primeira posicao. Procura-se entao o segundo" <<endl;
	        cout << "menor ou maior valor e coloca-o na segunda posicao e assim sucessivamente;" <<endl << endl;
	        cout << "INSERTIONSORT: o segundo elemento da lista eh comparado com o primeiro e se estiver fora" <<endl;
	        cout << "de ordem eh trocado. O terceiro elemento eh comparado com o anterior, se for maior nenhuma" <<endl;
	        cout << "outra comparacao e feita, visto que os anteriores ja estao ordenados. Caso seja menor, havera" <<endl;
	        cout << "troca ate que seja o maior numero entre os comparados ou chegar na primeira posicao;" <<endl << endl;
	        cout << "MERGESORT: A lista eh divida ao meio, estas partes sao ordenas e depois unificadas;" <<endl << endl;
	        cout << "QUICKSORT: A lista tambem eh dividida em duas partes, mas com base em um elemento: o pivot." <<endl;
	        cout << "Os elementos sao comparados com o pivot, ficando os menores a esquerda e maiores a direita." <<endl;
			break;
	    }
	}
	
    return 0;
}



