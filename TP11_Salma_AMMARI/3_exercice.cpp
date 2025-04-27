#include <vector>
#include<stdexcept>
#include<iostream>
class StackFullException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Stack is Full ";
    }
};
class StackEmptyException:public std::exception{
public:
    const char* what() const noexcept override{
        return  "Stack is empty";
    }
};
class Stack{
private:
    std::vector<int> stack;
    int length;
public:
    Stack(int len){length=len;};
    void push(int ele){
        if (is_full()){
            throw StackFullException();
        }
        stack.push_back(ele);
    };
    int pop(){
        if (is_empty()){
            throw StackEmptyException();
        }
        int val= stack.back();
        stack.pop_back();
        return val;
    };
    int size() const{
        return stack.size();
    };
    bool is_empty()const{
        return stack.empty();
    };
    bool is_full()const{
        return stack.size()>=length;
    };
    void func_c(Stack& s) {
        s.push(3); // This will throw StackFullException when we will create a stack of capacity 2 and call it to push the 3r d element

    }

    void func_b(Stack& s) {
        func_c(s);
    }

    void func_a(Stack& s) {
        func_b(s);
    }

};
int main() {
    // Test 1: Démontrer StackFullException via func_a
    try {
        Stack stack(2); // Stack with capacity of 2
        stack.push(1);
        stack.push(2);
        std::cout << "Stack size: " << stack.size() << std::endl;
        stack.func_a(stack); // Will throw StackFullException
    }
    catch (const StackFullException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }
    // Test 2: Démontrer StackEmptyException avec pop
    try {
        Stack stack(2); // Nouvelle pile vide
        std::cout << "Stack size: " << stack.size() << std::endl;
        stack.pop(); // Will throw StackEmptyException
    }
    catch (const StackEmptyException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }
    std::cout << "Program completed" << std::endl;
    return 0;
}