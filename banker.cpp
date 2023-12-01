#include <iostream>
#include <fstream>
#include <string> 



using std::string; using std::cout; using std::endl; using std::ifstream; 



void inputTable(char* fileName, int allocated[][3], int max[][3], int* available){
    int current=0; 
    int currentIndex=0; 
    string currentLine; 
    ifstream resourceTable(fileName, ifstream::in); 
    while(!resourceTable.eof()){
        std::getline(resourceTable, currentLine, ';'); 
        if(std::stoi(currentLine)<0){
            for(int i=0; i<3; ++i){
                std::getline(resourceTable, currentLine, ','); 
                available[i]=std::stoi(currentLine); 
            }
            break; 
        }
        current=std::stoi(currentLine); 
        for(currentIndex=0; currentIndex<3; ++currentIndex){
            if(currentIndex==2)
                std::getline(resourceTable, currentLine, ';'); 
            else   
                std::getline(resourceTable, currentLine, ','); 
            allocated[current][currentIndex]=std::stoi(currentLine); 
        }
        for(currentIndex=0; currentIndex<3; ++currentIndex){
            if(currentIndex==2)
                std::getline(resourceTable, currentLine, ';'); 
            else
                std::getline(resourceTable, currentLine, ','); 
            max[current][currentIndex]=std::stoi(currentLine); 
        }
    }
}

int main(int argc, char** argv){
    if(argc!=2){
        std::cerr<<"ERROR: No input file specified. \n"; 
        exit(1);
    }
    char* table=argv[1]; 

    int allocated[5][3]; 
    int max[5][3]; 
    int available[3]; 

    inputTable(table, allocated, max, available); 
    int finished[5]; 
    int answer[5]; 
    int index=0; 
    int need[5][3]; 

    for(int i=0; i<5; ++i){
        for(int j=0; j<3; ++j){
            need[i][j]=max[i][j]-allocated[i][j]; 
        }
    }

    for(int i=0; i<5; ++i){
        finished[i]=-1; 
    }

    for(int k=0; k<5; ++k){
        for(int l=0; l<5; ++l){
            if(finished[l]==-1){
                int flag=-1; 
                for(int a=0; a<3; ++a){
                    if(need[l][a]>available[a]){
                        flag=1; 
                        break; 
                    }
                }
                if(flag==-1){
                    answer[index++]=l; 
                    for(int b=0; b<3; ++b){
                        available[b]+=allocated[l][b]; 
                        finished[l]=1; 
                    }
                }
            }
        }
    }
    int safeFlag=1; 

    for(int i=0; i<5; ++i){
        if(finished[i]==-1){
            safeFlag=0; 
            cout<<"A deadlock is very likely with given sequence"
            <<endl; 
            break; 
        }
    }

    if(safeFlag==1){
        cout<<"No deadlocks, current sequence: "
        <<endl; 
        for(int j=0; j<4; ++j){
            cout<<"P: "<<answer[j]<<", "; 
        }
        cout<<"P: "<<answer[4]<<endl; 
    }
}
