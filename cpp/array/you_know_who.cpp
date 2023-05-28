// https://acm.timus.ru/problem.aspx?space=1&num=1439
// Rooms of the Ministry of Magic are enchanted with a spell which enumerates them automatically. The spell works as follows. The first room created at the Ministry got the number 1. When a new room is created by magic, a number-plate appears at once upon the door. The new number is greater by one than the maximal room number existing at the moment. If a room is not needed anymore, then it is destroyed and all the room numbers that are greater than the number of the destroyed room are lessened by one. Thus, the numeration of the rooms at the Ministry always remains continuous.
// Harry Potter found out a list of the numbers of the rooms where Lord Voldemort's Horcruxes are stored (A Horcrux is a magical artifact that provides for the owner's immortality). It seems that now it will be easy for Harry to find the Horcruxes and destroy them. But the task turned out to be more complicated. Because of his mysterious bond with Harry, Voldemort knew at once about Harry's discovery, so he transported himself to the Ministry and started to destroy rooms. This means that numbers of rooms are changing, so when Harry looks at a room's door, he doesn't know which number this door had before. But he knows which numbers were on the doors of the rooms that were destroyed by Voldemort, due to the mentioned bond between them.
// Help Harry to defeat Voldemort. You don't have to fight Harry's enemy, but you can help him to determine the true numbers of rooms when he looks at their doors.
// Input
// The first line contains the number of rooms at the Ministry of Magic N (1 ≤ N ≤ 109) and a number M (1 ≤ M ≤ 105). Each of the subsequent M lines has the following format:
// <letter> <number>
// where <letter> is one of the letters 'D' (Destroy) or 'L' (Look at), and <number> is the number on the door of the room which is destroyed or at which Harry looks at the moment. It is guaranteed that not more than 104 rooms will be destroyed during the battle.
// Output
// The output must contain for each line
// L <number>
// of the input the true number (which it had before the battle) of the room at which Harry looks. The numbers must be given one in a line.
// Sample
// input	output
// 20 7
// L 5
// D 5
// L 4
// L 5
// D 5
// L 4
// L 5
// 5
// 4
// 6
// 4
// 7


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int findPos(vector<int>& arr, int item) {
	int n = arr.size();
	
	if(n == 0) {
		return 0;
	}

	int lo = 0, hi = n - 1, mid;

	while(lo < hi) {
		mid = (lo + hi) / 2;

		if(item < arr[mid]){
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	if(arr[lo] <= item){
		return lo + 1;
	} else {
		return lo;
	}

}

void printArr(vector<int>& arr) {
	for(const int& i: arr){
		cout << i << ", ";
	}
	cout << endl;
}


int main()
{
   int n, m;
   cin >> n >> m;

   //cout << "n: " << n << " m: " << m << endl;

   string op;
   int number;
	
   vector<int> deletedPos;

   unordered_map<int,int> lookup;
   
   int insertPos;
   while(m--){
		cin >> op >> number;
		
		// cout << op << " " << number << endl;

		 if(op == "L"){
		 	insertPos = findPos(deletedPos, number);
			
			if(lookup.find(insertPos + number) == lookup.end()){
				cout << insertPos + number << endl; 
			} else {
				printf("%d\n", insertPos + number + lookup[insertPos + number]);
			}
		 } else {
		 	insertPos = findPos(deletedPos, number);
			
			deletedPos.insert(deletedPos.begin() + insertPos, number);
			lookup[number] = insertPos + 1 + lookup[insertPos + number + 1];
			
			 // cout << "insertPos" << insertPos << " Lookup Table\n"; 
			 // for(auto itr: lookup){
			 // 	cout << itr.first << " => " << itr.second << endl;
			 // }
		 }
		
   }

   
   return 0;
}
