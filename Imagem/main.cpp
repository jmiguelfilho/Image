//
//  main.cpp
//  Imagem
//
//  Created by João Miguel on 11/07/20.
//  Copyright © 2020 João Miguel. All rights reserved.
//
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Image{

    vector<vector<bool>> image;//0x0
    int dim;
public:
    Image():dim(0){
    }
    bool carregaImagem(char* nomeArq){
        ifstream arq(nomeArq);//c_str() string->*char e .str() ostringstream->string
            int i, j;
            char c;
            if (!arq.is_open())
                return false;
            arq >> dim;
            arq.read(&c, 1);
            image.resize(dim);
            
            for(i=0;i<dim;i++){
                image[i].resize(dim);
                for(j=0;j<dim;j++){
                    arq.read(&c, 1); //arq >> c;
                    if(arq.eof())
                        return false;
                    image[i][j]=(c!='0');
                }
            }
            arq.close();
            return true;
    }
    void mostraImagem(){
            vector<vector<bool>>::iterator it1;
            vector<bool>:: iterator it2;
            
            for(it1=image.begin();it1!=image.end();it1++){
                for(it2=it1->begin();it2!=it1->end();it2++){
                    cout<< ((*it2)?(char)35:' ');
                    }
                cout<< endl;
        }
    }
    
};

int main() {
    Image i;
    
    if(i.carregaImagem("imagem.img")) // fin>>i;
     i.mostraImagem();              // cout<<i;

    return 0;
}
