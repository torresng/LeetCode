// Stack
class MinStack {
  public:
    stack<int> st, min_st;
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        st.push(x);
        if (min_st.empty() || x <= min_st.top()) {
            min_st.push(x);
        }
    }

    void pop() {
        int x = st.top();
        st.pop();
        if (min_st.top() == x) {
            min_st.pop();
        }
    }

    int top() { return st.top(); }

    int getMin() { return min_st.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Link
class MinStack {
public:
    struct Node {
        int val;
        Node *next;
        Node(int v, Node *n) {
            val = v;
            next = n;
        }
    };
    
    Node *head = nullptr;
    int min_val = INT_MAX;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(x <= min_val) {
            head = new Node(min_val, head);
            min_val = x;
        }
        head = new Node(x, head);
    }
    
    void pop() {
        if(head->val == min_val) {
            min_val = head->next->val;
            head = head->next->next;
        } else {
            head = head->next;
        }
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return min_val;
    }
};
