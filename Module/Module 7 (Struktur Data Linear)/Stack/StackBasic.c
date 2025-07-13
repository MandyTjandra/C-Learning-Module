#include <stdio.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

// Cek apakah stack kosong
int isEmpty() {
    return top == -1;
}

// Push (tambah ke atas)
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = value;
    printf("%d pushed to stack\n", value);
}

// Pop (hapus dari atas)
void pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

// Peek (lihat elemen paling atas tanpa menghapus)
void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", stack[top]);
}

// Ambil elemen paling atas (return datanya)
int stack_top() {
    if (!isEmpty()) {
        return stack[top];
    }
    return -1; // Jika kosong, kembalikan -1
}

// Tampilkan semua elemen stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(5);
    push(10);
    push(15);
    display();

    pop();
    peek();
    display();

    if (!isEmpty()) {
        printf("Current top element is: %d\n", stack_top());
    } else {
        printf("Stack is empty\n");
    }

    return 0;
}
