
#include <FrequencyTimer2.h>


#define A  { \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}  \
}

#define B { \
    {0, 0, 1, 1, 0, 0, 0, 0},  \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0} \
}

#define C { \
    {0, 0, 0, 1, 1, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0} \
}

#define D { \
    {0, 0, 1, 1, 0, 0, 0, 0},  \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0} \
}

#define E { \
    {0, 0, 1, 1, 1, 1, 0, 0},  \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0} \
}

#define F { \
    {0, 0, 1, 1, 1, 1, 0, 0},  \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0} \
}

#define G { \
    {0, 0, 0, 1, 1, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 1, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 1, 0, 0} \
}

#define H { \
    {0, 0, 1, 0, 0, 1, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0} \
}

#define I { \
    {0, 1, 1, 1, 1, 1, 0, 0},  \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 0, 0} \
}

#define J { \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}  \
}

#define K { \
    {0, 0, 1, 0, 0, 1, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 1, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0} \
}

#define L { \
    {0, 0, 1, 0, 0, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0} \
}

#define M { \
    {1, 0, 0, 0, 0, 0, 1, 0},  \
    {1, 1, 0, 0, 0, 1, 1, 0}, \
    {1, 0, 1, 0, 1, 0, 1, 0}, \
    {1, 0, 0, 1, 0, 0, 1, 0}, \
    {1, 0, 0, 1, 0, 0, 1, 0}, \
    {1, 0, 0, 1, 0, 0, 1, 0}, \
    {1, 0, 0, 0, 0, 0, 1, 0}, \
    {1, 0, 0, 0, 0, 0, 1, 0} \
}

#define N { \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 1, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 1, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}  \
}

#define O { \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}  \
}

#define P { \
    {0, 0, 1, 1, 1, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0} \
}

#define Q { \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 1, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 1, 0}  \
}

#define R { \
    {0, 0, 1, 1, 1, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0} \
}

#define S { \
    {0, 0, 0, 1, 1, 1, 1, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0}  \
}

#define T { \
    {0, 1, 1, 1, 1, 1, 0, 0},  \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0} \
}

#define U { \
    {0, 0, 1, 0, 0, 1, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0} \
}

#define V { \
    {0, 0, 1, 0, 0, 0, 1, 0},  \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 1, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 1, 0, 0, 0} \
}

#define W { \
    {1, 0, 0, 0, 0, 0, 1, 0},  \
    {1, 0, 0, 0, 0, 0, 1, 0}, \
    {1, 0, 0, 0, 0, 0, 1, 0}, \
    {1, 0, 0, 0, 0, 0, 1, 0}, \
    {1, 0, 0, 1, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 1, 0, 1, 0}, \
    {0, 0, 1, 0, 1, 1, 1, 0}, \
    {0, 0, 0, 1, 0, 0, 1, 0} \
}

#define X { \
    {0, 1, 0, 0, 0, 0, 1, 0},  \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0} \
}

#define Y { \
    {0, 1, 0, 0, 0, 0, 1, 0},  \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0} \
}

#define Z { \
    {0, 1, 1, 1, 1, 1, 1, 0},  \
    {0, 0, 0, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0} \
}

#define SPACE { \
    {0, 0, 0, 0, 0, 0, 0, 0},  \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0} \
}

#define HYPHEN { \
    {0, 0, 0, 0, 0, 0, 0, 0},  \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0} \
}

#define QUESTION { \
    {0, 0, 0, 1, 1, 0, 0, 0},  \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 0, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0} \
}


