#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        void processCommmands(vector<string>& commands){
            int n = commands.size();

            while(n--){
                
            }
        }


};

int main(){
    vector<string> t1 = {"INSERT Nayan", 
    "INSERT Das", 
    "COPY 0 4", 
    "PASTE", 
    "PRINT", 
    "DELETE 0 4", 
    "PRINT", 
    "UNDO", 
    "UNDO", "PRINT", "REDO", "PRINT", "REDO"};

    // NayanDasNayan
    // DasNayan
    // NayanDas
    // NayanDasNayan
    // DasNayan
}