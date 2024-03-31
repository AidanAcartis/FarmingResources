#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;
bool solution(vector<int> friendlyTroop, vector<int> enemyTroop, vector<int> loggingCamp, vector<vector<int>> impassableCells);
vector<int> fonction1(vector<int> Test, vector<int> loggingCamp, vector<int> local);
vector<int> fonction2(vector<int> Test, vector<vector<int>> impassableMove,vector<vector<int>> Change);
vector<int> fonction3(vector<int> Test, vector<int> friendlyTroop);
int CountPath(vector<int> Test, vector<int> loggingCamp, vector<int> friendlyTroop, vector<vector<int>> Change, vector<int> Move, vector<vector<int>> impassableCells);
vector<vector<int>> forMove(vector<int> Test, vector<vector<int>> impassableCells);
int Verif(vector<int> Test, vector<vector<int>> impassableCells);
vector<vector<int>> forChange(vector<int> Move);
vector<vector<int>> ForPossiblePath(vector<vector<int>> path, vector<int> shortPath);
vector<int> ChooseRightMove(vector<vector<int>> possiblePath, vector<int> Move);
vector<int> RightTest(vector<int> Test, vector<int> rightMove);
vector<int> TestForMove(vector<int> Move, vector<int> Test, vector<int> local);

int main(){
vector<int> friendlyTroop = {0,3,9};
vector<int> enemyTroop = {1,0,9};
vector<int> loggingCamp = {1,1};
vector<vector<int>> impassableCells = {{0,2},{1,2}};
if(solution(friendlyTroop, enemyTroop, loggingCamp, impassableCells)){
    cout<<"True"<<endl;
}
else{
    cout<<"False"<<endl;
}
}
bool solution(vector<int> friendlyTroop, vector<int> enemyTroop, vector<int> loggingCamp, vector<vector<int>> impassableCells){
    vector<int> solution;vector<int> Test = friendlyTroop;
    vector<int> test = enemyTroop;
    vector<int> Move;
    vector<int> move;
    int friendPath(0), enemyPath(0), friendTime(0), enemyTime(0);
    srand(time(NULL));
    vector<vector<int>> Change;
    vector<vector<int>> change;

friendPath = CountPath(Test, loggingCamp, friendlyTroop, Change, Move, impassableCells);
enemyPath = CountPath(test, loggingCamp, enemyTroop, change, move, impassableCells);
friendTime = friendPath*friendlyTroop[2];
enemyTime = enemyPath*enemyTroop[2];

return(friendTime<enemyTime);

}

vector<int> TestForMove(vector<int> Move, vector<int> Test, vector<int> local){
  vector<vector<int>> path;
  vector<vector<int>> possiblePath;

 path = forChange({0,-1});
 possiblePath = ForPossiblePath(path, Move);  //parfois le mvmt a faire est impossible alors cette fonction genere des chemins 
                                              //possibles qui remplacent ce mvt
 Move = ChooseRightMove(possiblePath, Move);
 Test = RightTest(local, Move);
 
return Test;
}
vector<int> RightTest(vector<int> Test, vector<int> rightMove){
    for(int i=0; i<2; i++){
        Test[i] = Test[i]+rightMove[i];
    }
    return Test;
}
vector<int> ChooseRightMove(vector<vector<int>> possiblePath, vector<int> Move){
    vector<int> rightMove;
    int counter(0), size(0), min(0), max(0), a(0);
    size = possiblePath.size();
    max = size-1;
    counter = Verif(Move, possiblePath);
    if(counter==2){
        rightMove = Move;
    }
    else{
        a = rand()%(max-min+1)+min;
        for(int i=0; i<2; i++){
            rightMove.push_back(possiblePath[a][i]);
        }
    }
    return rightMove;
}
vector<vector<int>> ForPossiblePath(vector<vector<int>> path, vector<int> shortPath){
  vector<vector<int>> possiblePath;
  vector<int> temp;
  int sum = shortPath[0]+shortPath[1];
  int Sum;
  for(int i=0; i<6; i++){
    Sum = path[i][0]+path[i][1];
    if(sum<-1 && Sum==-1){

             for(int j=0; j<2; j++){
                temp.push_back(path[i][j]);
             }
             possiblePath.push_back(temp);
             temp.clear();
    }
    else if(sum>1 && Sum==1){
            for(int l=0; l<2; l++){
                temp.push_back(path[i][l]);
            }
            possiblePath.push_back(temp);
            temp.clear();
    }
  }
  return possiblePath;
}
int CountPath(vector<int> Test, vector<int> loggingCamp, vector<int> friendlyTroop, vector<vector<int>> Change, vector<int> Move, vector<vector<int>> impassableCells){
int npath(0), verif(0), counter(0);
 vector<vector<int>> impassableMove;
 vector<int> local;

do{
 impassableCells.push_back(Test);
 impassableMove = forMove(Test, impassableCells);
 local = Test;
 Test = fonction1(Test,loggingCamp,local);  //genere le chemin le plus court de la ou on est
Move = fonction3(Test, local);
Change = forChange(Move);

do{ 
    verif=0;
    counter=0;
    counter = Verif(Test,impassableCells);
    if(counter==2){
      Test = fonction2(local,impassableMove,Change);
      if(Test[0]==local[0] && Test[1]==local[1]){
        verif=1;
        Test[0]=loggingCamp[0];
        Test[1]=loggingCamp[1];
        npath=10000;
      }
    }
    else{
        verif=1;
    }
}while(verif!=1);
npath++;

}while(Test[0]!=loggingCamp[0] || Test[1]!=loggingCamp[1]);
return npath;
}
vector<int> fonction1(vector<int> Test, vector<int> loggingCamp, vector<int> local){
int sum(0);
vector<int> Move; 

    for(int i=0; i<2; i++){
    if(Test[i]<loggingCamp[i]){
        Test[i]++;
    }
    else if(Test[i]>loggingCamp[i]){
        Test[i]--;
    }
    else if(Test[i]==loggingCamp[i]){
        Test[i]=Test[i]+0;
    }
}
 Move = fonction3(Test,local);     //mouvement a faire pour se deplacer sur le cells le plus proche du but
 sum = Move[0]+Move[1];
 if(sum<-1 || sum>1){
    Test = TestForMove(Move, Test, local);
 }
return Test;
}
int Verif(vector<int> Test, vector<vector<int>> impassableCells){
    int counter=0;
     int size = impassableCells.size();
for(int m=0; m<size; m++){
        counter = 0;
    for(int n=0; n<2; n++){
        if(impassableCells[m][n]==Test[n]){
          counter++;
        }
        if(counter==2){
            n=2;
            m=size;
        }
    }
}
return counter;
}
vector<vector<int>> forMove(vector<int> Test, vector<vector<int>> impassableCells){
    vector<vector<int>> impassableMove;
    int size = impassableCells.size();

    for (int i = 0; i < size; i++) {
        vector<int> temp;    // Créer un vecteur temporaire pour stocker les coordonnées après la soustraction
        for (int j = 0; j < 2; j++) {
            temp.push_back(impassableCells[i][j] - Test[j]);
        }
        impassableMove.push_back(temp);  // Ajouter le vecteur temporaire à impassableMove
    }
    return impassableMove;
}
vector<int> fonction2(vector<int> Test, vector<vector<int>> impassableMove,vector<vector<int>> Change){
    int counter(0), verif(0), compteur(0), a(0), Counter(0);
    vector<int> temp;
    vector<int> Move;

for(int i=1; i<6; (i=i+2)){
    
    if(i==5){
        for(int k=0; k<2; k++){
            temp.push_back(Change[i][k]);
        }
        Counter = Verif(temp, impassableMove);
        if(Counter==2){
            cout<<"On ne peut pas sortir d'ici"<<endl;
            for(int l=0; l<2; l++){
            Move.push_back(0);
        }
            temp.clear();
        }
        else{
            Move = temp;
        }
    }
    else{
     a = rand()%((i+1)-i+1)+i;
     do{ 
         verif=0;
         counter=0;
         temp.clear();
         for(int j=0; j<2; j++){
            temp.push_back(Change[a][j]);
         }
         counter = Verif(temp, impassableMove);
         if(counter==2){
            if(a==i){
                a = i+1;
            }
            else if(a==(i+1)){
                a=i;
            }
         }
         else{
            Move = temp;
            verif = 1;
            i=6;
         }
         compteur++;
         if(compteur==2){
            temp.clear();
            verif=1;
         }
     }while(verif!=1);
    }
    
}
Test[0]=Test[0]+Move[0];
Test[1]=Test[1]+Move[1];
   
return Test;
}
vector<int> fonction3(vector<int> Test, vector<int> friendlyTroop){
    vector<int> Move;
    for(int i=0; i<2; i++){
        Move.push_back(Test[i]-friendlyTroop[i]);
    }
    return Move;
}
vector<vector<int>> forChange(vector<int> Move){
    int a(0), b(0), c(0), counter(0);
    vector<vector<int>> Change;
    int sum = Move[0]+Move[1];

    for(int i=0; i<6; i++){
        vector<int> temp;

        int sign = -1;
        if((i%3)==0 && i!=0){
            counter++;
        }
        if((i%2)==1 && i!=5){
            a=rand()%(2);
            b=(a+1)%2;
        }
        if((counter%2)==0){
          sign = -sign;
        }
        for(int j=0; j<2; j++){
          if(i==0 || i==5){
            temp.push_back((Move[j]*sign));
          }
          else{
            if(j==a){
                temp.push_back((sum*sign));
             }
          else if(j==b){
            temp.push_back((Move[b]*sign)-(sum*sign));
          }}
        }
        Change.push_back(temp);
          c=a;
          a=b;
          b=c;
    }
    return Change;
}