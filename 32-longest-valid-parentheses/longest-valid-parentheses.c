struct stk {
    int *data;
    int top, cap;
};

struct stk* ini(struct stk* st, int l) {
    st->top = -1;
    st->data = (int*)malloc(l * sizeof(int));
    st->cap = l;
    return st;
}

int isfull(struct stk* st) {
    return st->top == st->cap - 1;
}

int isempty(struct stk* st) {
    return st->top == -1;
}

void push(struct stk *st, int val) {
    if (isfull(st)) return;
    st->data[++st->top] = val;
}

int pop(struct stk* st) {
    if (isempty(st)) return -1;
    return st->data[st->top--];
}

int top(struct stk* st) {
    if (isempty(st)) return -1;
    return st->data[st->top];
}

int longestValidParentheses(char* s) {
    int i=0, m=0;
    struct stk *st = (struct stk*)malloc(sizeof(struct stk));
    ini(st, strlen(s));
    push(st, -1);
    while (s[i] != '\0') {
        if (s[i] == '(') {
            push(st, i);
        } else {
            pop(st);
            if (isempty(st)) {
                push(st, i); 
            } else {
                int len = i - top(st);
                if (len > m) m = len;
            }
        }
        i++;
    }
    free(st->data);
    free(st);
    return m;
}