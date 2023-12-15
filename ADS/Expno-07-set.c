#include <stdio.h>

#define MAX_SET_SIZE 10

typedef struct {
    int bitString[MAX_SET_SIZE];
} BitSet;

void initializeSet(BitSet *set) {
    for (int i = 0; i < MAX_SET_SIZE; ++i) {
        set->bitString[i] = 0;
    }
}

void addToSet(BitSet *set, int element) {
    set->bitString[element] = 1;
}

void unionSets(BitSet *result, BitSet *set1, BitSet *set2) {
    for (int i = 0; i < MAX_SET_SIZE; ++i) {
        result->bitString[i] = set1->bitString[i] | set2->bitString[i];
    }
}

void intersectionSets(BitSet *result, BitSet *set1, BitSet *set2) {
    for (int i = 0; i < MAX_SET_SIZE; ++i) {
        result->bitString[i] = set1->bitString[i] & set2->bitString[i];
    }
}

void differenceSets(BitSet *result, BitSet *set1, BitSet *set2) {
    for (int i = 0; i < MAX_SET_SIZE; ++i) {
        result->bitString[i] = set1->bitString[i] & ~set2->bitString[i];
    }
}

void printSet(BitSet *set) {
    printf("Set: { ");
    for (int i = 0; i < MAX_SET_SIZE; ++i) {
        if (set->bitString[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}\n");

    printf("Bit String: ");
    int leadingZeros = 1;
    for (int i=0 ;i < MAX_SET_SIZE ; ++i) {
	if (set->bitString[i] ==0) {
	   printf("0");
	   continue;
	}
        if (set->bitString[i] == 1) {
            leadingZeros = 0;
        }
	if (!leadingZeros){
            printf("%d", set->bitString[i]);
        }
    }
    if (leadingZeros) {
        printf("0");
    }
    printf("\n");
}

int main() {
    BitSet set1, set2, resultSet;

    initializeSet(&set1);
    initializeSet(&set2);

    int element;

    printf("\nUniversal set :\n");
    printf("{");
    for(int i=0;i<MAX_SET_SIZE;i++){
        printf("%d ",i);
    }
    printf("}\n");

    printf("Enter elements for Set 1 (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &element);
        if (element == -1) {
            break;
        }
        addToSet(&set1, element);
    }

    printf("Enter elements for Set 2 (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &element);
        if (element == -1) {
            break;
        }
        addToSet(&set2, element);
    }

    printf("Set 1: ");
    printSet(&set1);

    printf("Set 2: ");
    printSet(&set2);

    unionSets(&resultSet, &set1, &set2);
    printf("Union: ");
    printSet(&resultSet);

    intersectionSets(&resultSet, &set1, &set2);
    printf("Intersection: ");
    printSet(&resultSet);

    differenceSets(&resultSet, &set1, &set2);
    printf("Difference (Set1 - Set2): ");
    printSet(&resultSet);

    return 0;
}
