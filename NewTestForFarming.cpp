#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;
bool solution(vector<int> friendlyTroop, vector<int> enemyTroop, vector<int> loggingCamp, vector<vector<int>> impassableCells);
vector<int> fonction1(vector<int> Test, vector<int> loggingCamp);
vector<int> fonction2(vector<int> Test, vector<vector<int>> impassableMove,vector<vector<int>> Change);
vector<int> fonction3(vector<int> Test, vector<int> friendlyTroop);
int CountPath(vector<int> Test, vector<int> loggingCamp, vector<int> friendlyTroop, vector<vector<int>> Change, vector<int> Move, vector<vector<int>> impassableCells);
vector<vector<int>> forMove(vector<int> Test, vector<vector<int>> impassableCells);
int Verif(vector<int> Test, vector<vector<int>> impassableCells);
vector<vector<int>> forChange(vector<int> Move);
vector<vector<int>> ForPossiblePath(vector<vector<int>> path, vector<int> shortPath);

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
    for(int j=0; j<2; j++){
    cout<<Test[j]<<endl;
}
cout<<"Pour les troupes amis"<<endl;
friendPath = CountPath(Test, loggingCamp, friendlyTroop, Change, Move, impassableCells);
cout<<"\nNombre de chemin = "<<friendPath<<endl;
cout<<"Pour les troupes ennemis"<<endl;
enemyPath = CountPath(test, loggingCamp, enemyTroop, change, move, impassableCells);
cout<<"\nNombre de chemin = "<<enemyPath<<endl;
friendTime = friendPath*friendlyTroop[2];
cout<<"\nLe temps pris par les amis = "<<friendTime<<endl;
enemyTime = enemyPath*enemyTroop[2];
cout<<"\nLe temps pris par les ennemis = "<<enemyTime<<endl;

return(friendTime<enemyTime);

}
vector<vector<int>> ForPossiblePath(vector<vector<int>> path, vector<int> shortPath){
  vector<vector<int>> possiblePath;
  vector<int> temp;
  int sum = shortPath[0]+shortPath[1];
  int Sum;
  for(int i=0; i<6; i++){
    Sum = path[i][0]+path[i][1];
    if(sum<=-1 && Sum==-1){

             for(int j=0; j<2; j++){
                temp.push_back(path[i][j]);
             }
             possiblePath.push_back(temp);
             temp.clear();
    }
    else if(sum==0 && Sum==0){
            for(int k=0; k<2; k++){
                temp.push_back(path[i][k]);
            }
            possiblePath.push_back(temp);
            temp.clear();
    }
    else if(sum>=1 && Sum==1){
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
int npath(0), verif(0), counter(0),stop(0), size(0);
 vector<vector<int>> impassableMove;
 vector<int> local;
 vector<vector<int>> path;
 vector<vector<int>> possiblePath;

do{
 impassableCells.push_back(Test);
 impassableMove = forMove(Test, impassableCells);
 local = Test;
 Test = fonction1(Test,loggingCamp);  //genere le chemin le plus court
 cout<<"Test :"<<endl;
 for(int x=0; x<2; x++){
    cout<<Test[x]<<endl;
 }
 cout<<"\n"<<endl;
 Move = fonction3(Test,local);
 cout<<"Move :"<<endl;               //mouvement a faire pour se deplacer sur le cells le plus proche du but
 for(int m=0; m<2; m++){
    cout<<Move[m]<<endl;
 }
 path = forChange({0,-1});
 possiblePath = ForPossiblePath(path, Move);  //parfois le mvmt a faire est impossible alors cette fonction genere des chemins 
                                              //possibles qui remplacent ce mvt
 size = possiblePath.size();
 cout<<"possiblePath :\n"<<endl;
for(int i=0; i<size; i++){
    for(int j=0; j<2; j++){
        cout<<possiblePath[i][j]<<endl;
    }
    cout<<"\n"<<endl;
}
 cout<<"\n"<<endl;
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
cout<<"\n Test"<<endl;
for(int j=0; j<2; j++){
    cout<<Test[j]<<endl;
}
npath++;
cout<<"npath = "<<npath<<"\n"<<endl;
cout<<" appuiez sur 1 pour contimuer"<<endl;
cin>>stop;
}while(Test[0]!=loggingCamp[0] || Test[1]!=loggingCamp[1]);
return npath;
}
vector<int> fonction1(vector<int> Test, vector<int> loggingCamp){
    for(int i=0; i<2; i++){
    if(Test[i]<loggingCamp[i]){
        Test[i]++;
        //Move.push_back(Test[i]-friendlyTroop[i]);
    }
    else if(Test[i]>loggingCamp[i]){
        Test[i]--;
        //Move.push_back(Test[i]-friendlyTroop[i]);
    }
    else if(Test[i]==loggingCamp[i]){
        Test[i]=Test[i]+0;
        //Move.push_back(Test[i]-friendlyTroop[i]);
    }
}
return Test;
}
int Verif(vector<int> Test, vector<vector<int>> impassableCells){
    int counter=0;
     int size = impassableCells.size();
for(int m=0; m<size; m++){
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
        // Créer un vecteur temporaire pour stocker les coordonnées après la soustraction
        vector<int> temp;
        for (int j = 0; j < 2; j++) {
            temp.push_back(impassableCells[i][j] - Test[j]);
            //cout << temp[j] << endl;
        }
        // Ajouter le vecteur temporaire à impassableMove
        impassableMove.push_back(temp);
        cout << "\n" << endl;
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
    //cout<<"\n Move"<<endl;
//for(int k=0; k<2; k++){
    //cout<<Move[k]<<endl;
//}

//cout<<"counter = "<<counter<<endl;
//cout<<"sum = "<<sum<<endl;
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
            //cout<<"On randomise a et b\t i = "<<i<<endl;
            a=rand()%(2);
            b=(a+1)%2;
        }
        if((counter%2)==0){
          sign = -sign;
        }
        //cout<<"sign = "<<sign<<endl;
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