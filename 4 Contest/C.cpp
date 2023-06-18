#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::swap;


void siftDown(std::vector <std::vector<int>> &heap){
    int i = 0;
    while (2 * i + 1 < heap.size()){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        if (right < heap.size() && heap[right][0] < heap[left][0]){
            j = right;
        }
        if (heap[i][0] <= heap[j][0]){
            break;
        }
        swap(heap[i],heap[j]);
        i = j;
    }
}

void siftUp (std::vector <std::vector<int>> &heap, int pos){
    while ((pos-1)/2 >= 0 and heap[pos][0] < heap[(pos-1)/2][0]){
        swap(heap[pos],heap[(pos-1)/2]);
        pos = (pos-1)/2;
    }
}


void extract(std::vector <std::vector<int>> &heap){
    if (heap.empty()){
        cout << '*' <<'\n';
        return;
    }

    cout << heap[0][0] << '\n';
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    if (heap.size() > 1) {siftDown(heap);}
}

void decrease(std::vector <std::vector<int>> &heap, int position, int val){
    for (int i = 0; i < heap.size(); i++){
        if (heap[i][1] == position){
            heap[i][0] = val;
            siftUp(heap, i);
            return;
        }
    }
}

int main(){

    std::vector <std::vector<int>> array;
    string str;
    int number, position;
    int poscounter = 1;

    while(cin >> str){
        if(str[0] == 'p'){
            cin >> number;
            array.push_back({number, poscounter});
            siftUp(array, array.size() - 1);
        }
        else if(str[0] == 'e'){
            extract(array);
        }
        else if(str[0] == 'd'){
            cin >> position >> number;
            decrease(array, position, number);
        }
        poscounter++;
    }
    return 0;
}