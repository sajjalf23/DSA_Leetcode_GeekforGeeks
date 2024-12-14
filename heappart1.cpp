#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;                              // HEAP

class maxheap{

    int *arr;
    int number_of_elements;
    int total_size ;

    public:

    maxheap(int n){

        arr = new int [n];
        total_size = n;
        number_of_elements = 0;

    }


    void insert(int index){

        if(number_of_elements == total_size){
            cout<<" child overflow "<<endl;
            return;
        }

        arr[number_of_elements]=index;
        int i = number_of_elements;
        number_of_elements++;

        while(i > 0 && arr[i] > arr[(i-1)/2]){
            swap(arr[i],arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void print(){

        for(int i = 0 ; i < number_of_elements ; i++)
        cout << arr[i] << " ";

    }

    void delete_from_heap(){

        if(number_of_elements == total_size){
            return;
        }

        arr[0] = arr[number_of_elements-1];
        number_of_elements--;

        if(number_of_elements == 0){
            return;
        }

        heapify(0);

    }

    void heapify(int index){

        int largest = index;
        int left = index*2 + 1;
        int right = index *2 + 2;

        if(left < number_of_elements && arr[largest] < arr[left]){        // for min heap arr[largest] > arr[left]
            largest = left;
        }
        if(right < number_of_elements && arr[largest] < arr[right]){
            largest = right;
        }
        if(largest!=index){
            swap(arr[largest],arr[index]);
            heapify(largest);
        }

    } 
};



int main(){
    maxheap h(6);
    h.insert(4);
    h.insert(11);
    h.insert(14);
    h.insert(36);
    h.print();
    h.delete_from_heap();
    h.print();
}