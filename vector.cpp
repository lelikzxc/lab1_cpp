#include <iostream>
using namespace std;

struct subvector {
    int *mas;
    unsigned int top;
    unsigned int capacity;
};

bool init(subvector *qv) {
    qv->mas = nullptr;
    qv->top = 0;
    qv->capacity = 0;
    return true;
}

bool push_back(subvector *qv, int d) {
    if (qv->top == qv->capacity) {
        unsigned int new_capacity = (qv->capacity == 0) ? 1 : qv->capacity * 2;
        int *new_mas = new int[new_capacity];
        if (qv->mas != nullptr) {
            for (unsigned int i = 0; i < qv->top; ++i)
                new_mas[i] = qv->mas[i];
            delete[] qv->mas;
        }
        qv->mas = new_mas;
        qv->capacity = new_capacity;
    }
    qv->mas[qv->top++] = d;
    return true;
}

int pop_back(subvector *qv) {
    if (qv->top == 0)
        return 0;
    return qv->mas[--qv->top];
}

bool resize(subvector *qv, unsigned int new_capacity) {
    if (new_capacity == 0) {
        delete[] qv->mas;
        qv->mas = nullptr;
        qv->top = 0;
        qv->capacity = 0;
    } else {
        int *new_mas = new int[new_capacity];
        unsigned int elements_to_copy = (qv->top < new_capacity) ? qv->top : new_capacity;
        for (unsigned int i = 0; i < elements_to_copy; ++i)
            new_mas[i] = qv->mas[i];
        delete[] qv->mas;
        qv->mas = new_mas;
        qv->top = elements_to_copy;
        qv->capacity = new_capacity;
    }
    return true;
}

void shrink_to_fit(subvector *qv) {
    if (qv->top < qv->capacity) {
        resize(qv, qv->top);
    }
}

void clear(subvector *qv) {
    qv->top = 0;
}

void destructor(subvector *qv) {
    delete[] qv->mas;
    qv->mas = nullptr;
    qv->top = 0;
    qv->capacity = 0;
}

int main() {
    subvector sv;
    init(&sv);

    push_back(&sv, 1);
    push_back(&sv, 2);
    push_back(&sv, 3);

    cout << "Top element: " << pop_back(&sv) << endl;

    resize(&sv, 10);

    shrink_to_fit(&sv);
    clear(&sv);
    destructor(&sv);

    return 0;
}
