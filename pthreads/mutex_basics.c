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

struct transaction {
    struct brokerage_account* account;
    struct stock_position* position;
    double shares;
};

int change_position(struct stock_position* position, struct brokerage_account* account, double shares) {
    // Acquire the mutex lock before altering shared data.
    pthread_mutex_lock(&account->mutex);

    double prior_share_count = position->shares;
    position->shares += shares;
    printf(
        "Account #%ld position %s share count changed %.2f from %.2f to %.2f.\n",
        position->account_id,
        position->symbol,
        shares,
        prior_share_count,
        position->shares
    );

    // Release the mutex lock after altering shared data.
    pthread_mutex_unlock(&account->mutex);
    return position->shares;
}

void* start_thread(void *arg) {
    struct transaction *tr = (struct transaction*) arg;
    change_position(tr->position, tr->account, tr->shares);
    return NULL;
}

int main() {
    pthread_t thread_1, thread_2, thread_3;

    struct brokerage_account account = {.mutex = PTHREAD_MUTEX_INITIALIZER, .account_id = 1};
    struct stock_position aapl_position = {1, "AAPL", 35};
    struct stock_position nvda_position = {1, "NVDA", 40};

    struct transaction buy1 = {&account, &nvda_position, 1};
    pthread_create(&thread_1, NULL, start_thread, (void*) &buy1);

    struct transaction buy2 = {&account, &aapl_position, 2};
    pthread_create(&thread_2, NULL, start_thread, (void*) &buy2);

    struct transaction dividend_reinvest = {&account, &aapl_position, 0.1231};
    pthread_create(&thread_3, NULL, start_thread, (void*) &dividend_reinvest);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_detach(thread_3);

    return 0;
}