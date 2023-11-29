#include "../../include/Search/binary_search.h"
extern int g_total_elements;

int binary_search_name(struct movie_index_name* array, char* target, int* lower,
    int* upper)
{
    int low = 0;
    int high = g_total_elements - 1;

    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        int comp = strcasecmp(array[mid].name, target);
        if (comp < 0)
            low = mid + 1;
        else if (comp > 0)
            high = mid - 1;
        else {
            /// target found on mid
            *lower = *upper = mid;

            while (*lower > 0 && strcasecmp(array[*lower - 1].name, target) == 0) {
                printf("%d", *lower);
                *(lower) -= 1;
            }

            // Find the upper bound
            while (*upper < g_total_elements - 1 && strcasecmp(array[*upper + 1].name, target) == 0) {
                printf("%d", *upper);
                *(upper) += 1;
            }

            break;
        }
    }
    return (*upper - *lower + 1);
}
