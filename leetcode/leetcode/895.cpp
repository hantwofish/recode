#include"STLCOMMON.h"

using namespace std;

class FreqStack {
public:
    FreqStack() {
        map_count.clear();
        map_list.clear();
        maxSize =0;
    }
    
    void push(int val) {
        map_count[val]++;
        int countNumber = map_count[val];
        map_list[countNumber].push(val);
        if(countNumber > maxSize){
            maxSize = countNumber;
        }
        cout << "push:: val=   " << val  <<"  countNumber= " << countNumber << "  maxSize= " << maxSize << endl;

    }
    
    int pop() {
        //cout << "pop:: maxSize= " << maxSize << endl;
        // stack<int> stk = map_list[maxSize];
        cout << "   pop:: stk.size()= " << map_list[maxSize].size() << " maxSize= " << maxSize << endl;
        if(map_list[maxSize].size()==0){
            cout << "err"<< endl;
            //return 999;
        }
        int resu = map_list[maxSize].top();
        map_list[maxSize].pop();
        map_count[resu]--;
        if(map_list[maxSize].size()==0){
            maxSize--;
        }
        cout << "rsu= " << resu << endl;
        
        return resu;
    }
public:
    unordered_map<int,int> map_count;
    unordered_map<int,stack<int>> map_list;
    int maxSize;

};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */;

int main()
{
    FreqStack f1;
    f1.push(4);
    f1.push(0);
    f1.push(9);
    f1.push(3);
    f1.push(4);
    f1.push(2);

    f1.pop();
    f1.push(6);
    f1.pop();
    f1.push(1);
    f1.pop();
    f1.push(1);
    f1.pop();
    f1.push(4);
    f1.pop();        
    f1.pop();
    f1.pop();
    f1.pop();
    f1.pop();
    f1.pop();

    
    return 0;
}

/*

Line 175: Char 16: runtime error: reference binding to misaligned address 0xbebebebebebec0ba for type 'int', which requires 4 byte alignment (stl_deque.h)
0xbebebebebebec0ba: note: pointer points here
<memory cannot be printed>
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_deque.h:180:16

["FreqStack","push","push","push","push","push","push","pop","push","pop","push","pop","push","pop","push","pop","pop","pop","pop","pop","pop"]
[[],[4],[0],[9],[3],[4],[2],[],[6],[],[1],[],[1],[],[4],[],[],[],[],[],[]]
*/