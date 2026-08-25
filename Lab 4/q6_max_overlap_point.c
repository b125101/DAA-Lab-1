#include <stdio.h>
#include <stdlib.h>

struct Event {
    int point;
    int type;
};

int compare(const void *a, const void *b) {
    struct Event *e1 = (struct Event *)a;
    struct Event *e2 = (struct Event *)b;

    if (e1->point != e2->point)
        return e1->point - e2->point;

    // Start event before end event
    if (e1->type == 1 && e2->type == -1)
        return -1;

    if (e1->type == -1 && e2->type == 1)
        return 1;

    return 0;
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Event events[2 * n];

    printf("Enter intervals:\n");

    for (int i = 0; i < n; i++) {
        int left, right;

        printf("Interval %d: ", i + 1);
        scanf("%d %d", &left, &right);

        events[2 * i].point = left;
        events[2 * i].type = 1;      // Start

        events[2 * i + 1].point = right;
        events[2 * i + 1].type = -1; // End
    }

    // Sort events
    qsort(events, 2 * n, sizeof(struct Event), compare);

    int current = 0;
    int maximum = 0;
    int bestPoint = 0;

    for (int i = 0; i < 2 * n; i++) {

        current += events[i].type;

        if (current > maximum) {
            maximum = current;
            bestPoint = events[i].point;
        }
    }

    printf("\nPoint with maximum overlap = %d\n", bestPoint);
    printf("Maximum number of intervals = %d\n", maximum);

    return 0;
}
