class MyQueue {
    
    //created 2 stack for pushing and popping purpose
      stack<int> pullStk;
      stack<int> pushStk;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        //pushing the element into queue
        pushStk.push(x);
    }
    
    int pop() {
        //if the popping stack is empty
        if (pullStk.empty()) 
        {
            //it will continue popping the stack top pointer and after popping element it will push element into queue
            while (!pushStk.empty()) {
                int val = pushStk.top();
                pushStk.pop();
                pullStk.push(val);
             }
        }
        int val = pullStk.top();
        pullStk.pop();
        return val;   
    }
    
    int peek() {
        //same as popping stack process
        if (pullStk.empty()) {
            while (!pushStk.empty()) {
                int val = pushStk.top();
                pushStk.pop();
                pullStk.push(val);
            }
        }
        int val = pullStk.top();
        return val;
    }
    
    bool empty() {
        return (pullStk.empty() && pushStk.empty());
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
