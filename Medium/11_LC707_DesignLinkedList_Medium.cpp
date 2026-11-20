class MyCircularDeque {
public:
    int arr[1000];
    int front, rear, size, capacity;

    MyCircularDeque(int k) {
        front = 0;
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        front = (front - 1 + capacity) % capacity;

        if (size == 0)
            rear = front;

        arr[front] = value;
        size++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        rear = (rear + 1) % capacity;

        if (size == 0)
            front = rear;

        arr[rear] = value;
        size++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        size--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        rear = (rear - 1 + capacity) % capacity;
        size--;

        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};


