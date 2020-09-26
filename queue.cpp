#define QUEUE_SIZE 100

struct Student {
  char name[128];
  int age;
  int average;
};

Student QueueData[QUEUE_SIZE];
int front = 0;
int end = 0;

void push(Student s) {
  rear++;
  rear = rear % QUEUE_SIZE;
  QueueData[rear] = s;
}

Student pop() {
  front++;
  front = front % QUEUE_SIZE;
  return QueueData[front];
}
