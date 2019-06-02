#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
std::vector<int> to_vector( std::string comma_seperated_integers )
{
    std::vector<int> sequence ;
    char COMMA = ',' ;

    comma_seperated_integers += COMMA ;
    std::istringstream stm(comma_seperated_integers) ;

    int value ;
    char delimiter ;
    while( stm >> value >> delimiter && ( delimiter == COMMA ) )
          sequence.push_back(value) ;

    return sequence ;
}
int main(int argc, char** argv) {
	char dermatologyFile[] = "dermatology.data"; 
    FILE *dermaDataset = fopen(dermatologyFile, "r"); 
    vector<int> entradas[366];
    int classes[366];
    int desejado[366][6];
    if(dermaDataset == NULL){
        printf("Erro ao abrir arquivo ou arquivo vazio!");
    } else {
        char linha[72]; 
        int k = 0;
        while (fgets(linha, sizeof linha, dermaDataset)) {
            int i;
            string token(linha);
            entradas[k] = to_vector(linha);
			k++;
			i++;
        }
    	fclose(dermaDataset);
    }
	for (int i = 0; i < 366; i++) {
		for (int j = 0; j < 6; j++) {
			desejado[i][j] = 0;
		}
	}
    for (int j = 0; j < 366; j++) {
        switch (classes[j]) {
            case 1:
                desejado[j][0] = 1;
                break;
            case 2:
                desejado[j][1] = 1;
                break;
            case 3:
                desejado[j][2] = 1;
                break;
            case 4:
                desejado[j][3] = 1;
                break;
            case 5:
                desejado[j][4] = 1;
                break;
            case 6:
                desejado[j][5] = 1;
                break;
            default:
                break;
        }
	}
    system("pause");
	return 0;
}
