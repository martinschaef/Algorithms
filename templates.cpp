#include <vector>
#include <iostream>
#include <stdexcept> // stdexcept header contains runtime_error
using namespace std; 

template <typename T>
class Stack {
// Write your code here
};

int main(){
    Stack<int> a, b;
    a.push(1); a.push(2);
    b.push(3); b.push(4);
    
    a.append(b);
    
    while( !a.empty() ){
        cout << a.top() << endl; a.pop();
    }
    
    try {
        a.top();
    }
    catch(const std::logic_error& le) {
        cout << "Stack is empty" << endl;;
    }
}