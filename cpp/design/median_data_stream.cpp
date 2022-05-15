#include<iostream>
#include<vector>
#include<set>

using namespace std;

class MedianFinder {
    multiset<int> stream;
    multiset<int>::iterator mid;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        stream.insert(num);

        if(stream.size() == 1){
            mid = stream.begin();
        } else {
            // printf("isnear %d\n", mid == stream.begin());
            
            if(stream.size() % 2 != 0){
                if(*mid <= num){
                    mid++;
                }
            }

            // printf("stream.size() % 2 == 0 && *mid > num: %d\n", stream.size() % 2 == 0);
            if(stream.size() % 2 == 0){
                if(*mid > num){
                    mid--;
                }
            }
        }

        // printf("inserted %d\n", *mid);
        
    }
    
    double findMedian() {
        if(stream.size() % 2 == 0){
            double left = *mid;
            double right = *(++mid);
            mid--;

            // printf("left: %f, right: %f\n", left, right);

            return (left + right)/2;
        } else {
            return *mid;
        }
    }
};

int main() {
    // vector<string> t1 = {"MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"};
    // vector<vector<int>> t1_vals = {{}, {1}, {2}, {}, {3}, {}};

    vector<string> t1 = {"MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian"};
    vector<vector<int>> t1_vals = {{},{6},{},{10},{},{2},{},{6},{},{5},{},{0},{},{6},{},{3},{},{1},{},{0},{},{0},{}};

    // vector<string> t1 = {"MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"};
    // vector<vector<int>> t1_vals = {{}, {1}, {1}, {}, {1}, {}};

    int n = t1.size();

    MedianFinder * obj;

    int i = 0;
    while(i < n){
        string s = t1[i];

        if(t1[i] == "MedianFinder"){
            obj = new MedianFinder();
        } else if(t1[i] == "addNum") {
            // printf("addnum: %d\n", t1_vals[i][0]);
            obj->addNum(t1_vals[i][0]);
        } else {
            printf("findMedian: %f\n", obj->findMedian());
        }

        i++;
    }
}