#include <iostream>
#include <stack>

using namespace std;

struct Queue {
    stack<int> stack_1, stack_2;
   /*
    |     |     |     |
    |  2  |     |     |
    |  1  |     |     |
    stack_1     stack_2
    */
    void enQueue(int x) {

        // Move all elements from stack_1 to stack_2     //   |     |      |     |
        while (!stack_1.empty()) {                       //   |     |      |  1  |
            stack_2.push(stack_1.top());              //   |     |      |  2  |
            stack_1.pop();                               //   stack_1      stack_2
        }
                                                         //   |     |      |     |
        // Push item into stack_1                        //   |     |      |  1  |
        stack_1.push(x);                                 //   |  3  |      |  2  |
                                                         //   stack_1      stack_2
        // Push everything back to stack_1
        while (!stack_2.empty()) {                       //   |  1  |      |     |
            stack_1.push(stack_2.top());              //   |  2  |      |     |
            stack_2.pop();                               //   |  3  |      |     |
        }                                                //   stack_1      stack_2
    }

    // Dequeue an item from the queue
    int deQueue() {

        // if first stack is empty
        if (stack_1.empty()) {
            cout << "Q is empty" << endl;
            exit(0);
        }

        // Return top of stack_1
        int x = stack_1.top();
        stack_1.pop();
        return x;
    }
};

struct Queue_2 {

    stack<int> stack_1,stack_2;

    // Enqueue an item to the queue
    void enqueue(int x) {
        // Push item into the first stack
        stack_1.push(x);
    }

    // Dequeue an item from the queue
    int deQueue() {
        // if both stacks are empty
        if (stack_1.empty() && stack_2.empty()) {
            cout << "Q is empty" << endl;
            exit(0);
        }

        // if stack_2 is empty, move
        // elements from stack_1
        if (stack_2.empty()) {
            while (!stack_1.empty()) {
                stack_2.push(stack_1.top());
                stack_1.pop();
            }
        }

        int x = stack_2.top();
        stack_2.pop();
        return x;
    }

};

int main() {

    Queue q;
    cout << "Queue method 1:" << endl;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    Queue_2 q_2;
    cout << "Queue method 2:" << endl;

    q_2.enqueue(1);
    q_2.enqueue(2);
    q_2.enqueue(3);
    q_2.enqueue(4);

    cout << q_2.deQueue() << '\n';
    cout << q_2.deQueue() << '\n';
    cout << q_2.deQueue() << '\n';
    cout << q_2.deQueue() << '\n';

    return 0;
}
