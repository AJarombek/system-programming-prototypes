// System Programming Example: Basics of using mutexes in the pthread library.
// Author: Andrew Jarombek
// Date: 6/12/2022

#include <pthread.h>
#include <stdio.h>

struct brokerage_account {
    pthread_mutex_t mutex;
    long account_id;
};

struct stock_position {
    long account_id;
    char* symbol;
    double shares;
};

int change_position(struct stock_position* position, struct brokerage_account* account, double shares) {
    pthread_mutex_lock(&account->mutex);

    pthread_mutex_unlock(&account->mutex);
}

int main() {
    struct brokerage_account account = {.mutex = PTHREAD_MUTEX_INITIALIZER, .account_id = 1};
    struct stock_position aapl_position = {1, "AAPL", 35};
    struct stock_position nvda_position = {1, "NVDA", 40};

    return 0;
}