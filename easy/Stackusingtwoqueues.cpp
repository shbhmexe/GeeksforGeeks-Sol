/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
void QueueStack ::push(int x)
{
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    // Push the new element into q1
    q1.push(x);

    // Move all elements back from q2 to q1
    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
}

int QueueStack ::pop()
{

    if (q1.empty())
    {
        return -1; // Underflow case
    }

    int ans = q1.front();
    q1.pop();
    return ans;
}