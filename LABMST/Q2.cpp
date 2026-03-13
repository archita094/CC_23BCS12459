#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    int func(vector<int>&tokens,int power){
        int l=0;
        int h=tokens.size()-1;
        int score=0;

        sort(tokens.begin(),tokens.end());

        while(l<=h){
            if(power>=tokens[l]){
                score+=1;
                power-=tokens[l];
                l+=1;
            }
            else if(l<h&&score>0){
                score-=1;
                power+=tokens[h];
                h-=1;
            }
            else{
                return score;
            }
        }

        return score;
    }
int main(){
    vector<int>tokens={100,200,300,400};
    int p=200;
    cout<<func(tokens,p);

    return 0;
}