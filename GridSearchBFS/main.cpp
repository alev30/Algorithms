#include "busroute.h"

int main() {

    vector<vector<int>> take1 {{4,1,2,2,2,2,2},
                               {2,4,4,4,4,4,2},
                               {3,4,2,2,2,4,2},
                               {2,4,2,4,2,4,2},
                               {2,2,2,1,2,2,2}};

    busroute try1 = busroute(take1);
    try1.printhousedist();

    return 0;
}