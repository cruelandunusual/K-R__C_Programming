#include <stdio.h>

/* character counting, for-loop version */

main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc) {
	; // isolated semi-colon is a null statement
    }
    printf("%.0f\n", nc);
}
