// HEAP

// padre di i è i/2
// figli di i sono 2i e 2i+1
// e partiamo da 1

vector<int> heap = {0};

int top() {
    return heap[1];
}

void push(int x) {
    heap.push_back(x);
    int i = heap.size() - 1;
    while (heap[i/2] < heap[i] and i > 1) {
        swap(heap[i/2], heap[i]);
        i /= 2;
    }
}

void pop() {
    swap(heap[1], heap.back());
    heap.pop_back();
    int i = 1;
    while (2*i < heap.size() and not (heap[i] > heap[2*i] and heap[i] > 2*i+1 == heap.size() ? -numeric_limits<int>::min() : heap[2*i+1])) {
        int j = 2*i;
        if (heap[2*i+1] > heap[2*i]) j = 2*i+1;
        swap(heap[i], heap[j]);
        i = j;
    }
}

// TREAP

// approccio 1: uso le STL, invece dei puntatori uso shared_ptr<treap> L, R;
// approccio 2: fare attenzione a deallocare quando serve: delete T;
// approccio 3: fregarsene dei memory leak

struct treap {
    int key, pri, size;
    treap *L, *R;

    treap(int key, treap *L = NULL, treap *R = NULL) : treap(key, rand(), L, R) {}

    treap(int key, int pri, treap *L, treap *R) : key(key), pri(pri), L(L), R(R) {
        size = 1;
        if (L != NULL) size += L->size;
        if (R != NULL) size += R->size;
    }
};

treap* merge(treap *L, treap *R) {
    if (L == NULL) return R;
    if (R == NULL) return L;
    if (L->pri > R->pri) {
        return new treap(L->key, L->pri, L->L, merge(L->R, R));
    } else {
        return new treap(R->key, R->pri, merge(L, R->L), R->R);
    }
}

pair<treap*, treap*> split(treap* T, int key) {
    if (T == NULL) return {NULL, NULL};
    if (T->key < key) {
        auto [RL, RR] = split(T->R, key);
        treap* L = new treap(T->key, T->pri, T->L, RL);
        return {L, RR};
    } else {
        auto [LL, LR] = split(T->L, key);
        treap* R = new treap(T->key, T->pri, LR, T->R);
        return {LL, R};
    }
}

int count(treap* T, int key) {
    if (T == NULL) return 0;
    if (T->key == key) return 1;
    if (T->key < key) return count(T->R, key);
    else return count(T->L, key);
}

treap* insert(treap* T, int key) {
    auto [L,R] = split(T, key);
    return merge(L, merge(new treap(key), R));
}

treap* erase(treap* T, int key) {
    auto [L,R] = split(T, key);
    auto [RL, RR] = split(R, key+1);
    return merge(L, RR);
}

int size(treap* T) {
    if (T == NULL) return 0;
    return T->size;
}

int get(treap* T, int i) {
    assert(T != NULL);
    if (size(T->L) == i) return T->key;
    if (size(T->L) > i) return get(T->L, i);
    if (size(T->L) < i) return get(T->R, i - size(T->L) - 1);
}
