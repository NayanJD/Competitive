#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<queue>

using namespace std;

class Solution {
public:
    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     return 0;
    // }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // unordered_map<string, unordered_set<string>> tree;
        unordered_map<string, vector<string>> all_combo;

        int n = wordList.size();
        int length = wordList[0].length();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < length; j++){
                string currStr = wordList[i].substr(0, j) + "*";
                if(j != length -1 ){
                    currStr += wordList[i].substr(j + 1, length - j - 1);
                }
                // cout << currStr << endl;

                if(all_combo.find(currStr) != all_combo.end()) {
                    all_combo[currStr].push_back(wordList[i]);
                } else {
                    all_combo[currStr] = {wordList[i]};
                }
            }
        }

        // for(auto itr = all_combo.begin(); itr != all_combo.end(); itr++){
        //     cout << itr->first << ": ";
        //     for(string word: itr->second){
        //         cout<< word << ",";
        //     }

        //     cout << endl;
        // }

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push(make_pair(beginWord, 1));

        while(q.size() != 0){
            pair<string, int> p = q.front();
            q.pop();
            
            
            string word = p.first;
            int level = p.second;

            // cout << "currWord: " << word << endl;
            visited.insert(word);

            if(word == endWord){
                return level;
            }

            for(int j = 0; j < length; j++){
                string currStr = word.substr(0, j) + "*";
                if(j != length -1 ){
                    currStr += word.substr(j + 1, length - j - 1);
                }

                // cout << "breakWord: " << currStr << endl;
                vector<string> adjWords = all_combo[currStr];

                for(string adjWord: adjWords){
                    if(visited.find(adjWord) == visited.end()){
                        // cout << "inserting: " << adjWord << endl;
                        q.push(make_pair(adjWord, level + 1));
                    }
                }
            }

        }

        return 0;
    }

    // 77ms solution
    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     queue<pair<string,int>> Q;
    //     unordered_set<string> S;
    //     int n=wordList.size();
    //     for(int i=0;i<n;i++){S.insert(wordList[i]);}
    //     Q.push({beginWord,0});
    //     do
    //     {
    //         string s=Q.front().first;
    //         int cur=Q.front().second;
    //         Q.pop();
    //         for(int i=0;i<s.size();i++)
    //         {
    //             char c=s[i];
    //             for(int j=0;j<26;j++)
    //             {
    //                 if(c!=j+'a')
    //                 {
    //                     s[i]=j+'a';
    //                     if(S.count(s))
    //                     {
    //                         if(s==endWord)return cur+2;
    //                         Q.push({s,cur+1});
    //                         S.erase(s);
    //                     }
    //                 }
    //             }
    //             s[i]=c;
    //         }
    //     }while(!Q.empty());
    //     return 0;
    // }

    void printTree(unordered_map<string, vector<string>>& tree){
        for(auto itr = tree.begin(); itr != tree.end(); itr++){
            cout << itr->first << ": ";

            for(auto adjItr = (itr->second).begin(); adjItr != itr->second.end(); adjItr++){    
                cout << *adjItr << " ";
            }

            printf("\n");
        }
    }
};

int main() {
    // vector<string> t1 = {"hot","dot","dog","lot","log","cog"};
    // string beginWord = "hit";
    // string endWord = "cog";

    // vector<string> t1 = {"hot","dot","dog","lot","log"};
    // string beginWord = "hit";
    // string endWord = "cog";

    vector<string> t1 = {"talk","tons","fall","tail","gale","hall","negs"};
    string beginWord = "talk";
    string endWord = "tail";



    Solution sol;

    // auto tree = sol.createAdjacencyTree(t1);

    // sol.printTree(tree);

    printf("Sequence length: %d", sol.ladderLength(beginWord, endWord, t1));

}